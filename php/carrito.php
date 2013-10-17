<?php
session_start(); 
session_register('itemsEnCesta'); 
session_register('usuari'); 
$item=$_POST['idpro']; 
$cantidad=$_POST['cantidad']; 
$usu = $_SESSION['contrase'];
$itemsEnCesta=$_SESSION['itemsEnCesta']; 
if ($usu){
	$_SESSION['usuari'] = $usu;
}
if ($item){ 
   if (!isset($itemsEnCesta)){ 
      $itemsEnCesta[$item]=$cantidad; 
   }else{ 
      foreach($itemsEnCesta as $k => $v){ 
         if ($item==$k){ 
			 $itemsEnCesta[$k]+=$cantidad; 
			 $encontrado=1; 
			 if ($itemsEnCesta[$k]<0){
				$itemsEnCesta[$k]= 0;
			 }
         } 
      } 
      if (!$encontrado) $itemsEnCesta[$item]=$cantidad; 
   } 
} 
$_SESSION['itemsEnCesta']=$itemsEnCesta; 

?>
<html>
<head>
<title>Carrito en "Pa chuparse los dedos"</title>
<link href="stylo.css" rel="stylesheet" type="text/css" />
</head>
<body id ="bodycarro">
<div id="todocarro">
<div id="cabeceracarro">
	<h1>LISTA DE LA COMPRA</h1>
</div>
<div id="contenidocarro">
<?php
$total = 0;
$db = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
if ($_GET['confirmar'] == 'no'){
	echo "<b>Datos de la compra</b>";
	$cadena = "";
	echo "<br/>";
	echo "<br/>";
	foreach($itemsEnCesta as $k => $v){ 
			if ($v > 0){
				for ($j= 1; $j<2;$j++){
					$consulta = 'SELECT * FROM Producto WHERE id_producto = '.$k.''; 
					$cursor= $db->query($consulta);
					$cuantos = $cursor->num_rows;
					for ($i=1; $i<$cuantos+1; $i++)
					{
						$fila= $cursor -> FETCH_ASSOC();
						foreach ($fila as $campo => $valor)
						{
							if ($campo == "nombre_p"){
								$nombrep = $valor;
							}
							if ($campo == "precio"){
								$pre = $valor;
							}
						}
					};
					$pr = $pre * $v;
					$total = $total + $pr;
					if ($j == 1){
						$cadena = $cadena.$nombrep." --> ".$v." unidades " . " Precio --> " . $pre . "€/"; 
					}else{
						$cadena = $cadena."/".$nombrep." --> ".$v." unidades " . " Precio --> " . $pre . "€/"; 
					}
				}
			}
	   }
	$cadena2 = split("/",$cadena);
	echo "<ul>";
	for($i=0;$cadena2[$i];$i++) {
			echo "<li>";
			echo "$cadena2[$i]<br>"; 
			echo "<br/>";
			echo "</li>";
	  }
	 echo "</ul>";
	echo "<br/>"; 
	echo "Precio total de la compra --> $total €";
	echo "<br/>"; 
	echo '<a href="carrito.php?confirmar=si">Confirmar</a> ';
	echo ' <a href="carrito.php">Cancelar</a>';
}else if ($_GET['confirmar'] == 'si'){
	echo "Compra realizada";
	$cadena = "";
	foreach($itemsEnCesta as $k => $v){ 
			if ($v > 0){
				for ($j= 1; $j<2;$j++){
					$consulta = 'SELECT * FROM Producto WHERE id_producto = '.$k.''; 
					$cursor= $db->query($consulta);
					$cuantos = $cursor->num_rows;
					for ($i=1; $i<$cuantos+1; $i++)
					{
						$fila= $cursor -> FETCH_ASSOC();
						foreach ($fila as $campo => $valor)
						{
							if ($campo == "nombre_p"){
								$nombrep = $valor;
							}
							if ($campo == "precio"){
								$pre = $valor;
							}
						}
					};
					$pr = $pre * $v;
					$total = $total + $pr;
					if ($j == 1){
						$cadena = $cadena.$nombrep." --> ".$v." unidades " . " Precio unidad --> " . $pre . "€/"; 
					}else{
						$cadena = $cadena."/".$nombrep." --> ".$v." unidades " . " Precio unidad --> " . $pre . "€/"; 
					}
				}
			}
	   }
	$usuari = $_SESSION['usuari'];
	$consulta2 = 'SELECT * FROM Cliente WHERE dni = "'.$usuari.'"'; 
					$cursor2= $db->query($consulta2);
					$cuantos2 = $cursor2->num_rows;
					for ($i=1; $i<2; $i++)
					{
						$fila2= $cursor2 -> FETCH_ASSOC();
						foreach ($fila2 as $campo2 => $valor2)
						{
							if ($campo2 == "id_cliente"){
								$cli = $valor2;
							}
							if ($campo2 == "nombre"){
								$nom = $valor2;
							}
							if ($campo2 == "email"){
								$emaile = $valor2;
							}
						}
					};
	$consulta3 = 'SELECT * FROM Cuenta'; 
					$cursor3= $db->query($consulta3);
					$cuantos3 = $cursor3->num_rows;
					for ($i=1; $i<2; $i++)
					{
						$fila3= $cursor3 -> FETCH_ASSOC();
						foreach ($fila3 as $campo3 => $valor3)
						{
							if ($campo3 == "numero"){
								$cuent = $valor3;
							}
						}
					};
	$cadena2 = split("/",$cadena);
	$consulta = "INSERT INTO Compra (id_cliente,fecha,pagado,enviado,productos,precio) VALUES('".$cli."', NOW(), 0 , 0 , '".$cadena."', $total)";
	$cursor = $db->query($consulta);
	$consulta4 = 'SELECT * FROM Compra WHERE id_cliente = "'.$cli.'"'; 
					$cursor4= $db->query($consulta4);
					$cuantos4 = $cursor4->num_rows;
					for ($i=1; $i<$cuantos4+1; $i++)
					{
						$fila4= $cursor4 -> FETCH_ASSOC();
						foreach ($fila4 as $campo4 => $valor4)
						{
							if ($campo4 == "id_compra"){
								$comp = $valor4;
							}
						}
					};
	$cuerpo = "Datos Compra:\n"; 
	for($i=0;$cadena2[$i];$i++) {
			$cuerpo .= "$cadena2[$i]\n"; 
	  }
	$cuerpo .= "Precio Total de la Compra: " . $total . " € \n\n"; 
    $cuerpo .= "Número de cuenta: " . $cuent . "\n\n"; 
	$cuerpo .= "Identificación: " . $cli . "-". $comp ."\n\n"; 
	$cuerpo .= 'Estimado Cliente, ' . "\n\n" .' Estos son los datos de su compra en "Pa Chuparse los Dedos", asi como los datos bancarios en los que debe de hacer el ingreso del precio de la compra, escriba la identificación que se le indica a la hora de hacer el ingreso y en el plazo más breve posible se le realizara el envio.' ."\n\n"; 
	$cuerpo .= "Para cualquier duda no responda a este correo, mande un correo a la dirección de contacto que aparece en la web.\n\n"; 
	$cuerpo .= "Gracias por su compra.\n\n"; 

    mail($emaile,"Pa chuparse los dedos",$cuerpo); 
	echo "<br/>";
	echo "Se le ha enviado un email a su cuenta de correo con los datos de la compra y los datos de pago.";	
	echo "<br/>";
	echo "<b>Gracias por su compra.</b>";
	session_unset();
}else{
	echo "<b>Datos de la compra</b>";
	echo "<br/>";
	echo "<br/>";
	if (isset($itemsEnCesta)){ 
	echo "<ul>";
	   foreach($itemsEnCesta as $k => $v){ 
			$consulta = 'SELECT * FROM Producto WHERE id_producto = '.$k.''; 
			$cursor= $db->query($consulta);
			$cuantos = $cursor->num_rows;
			for ($i=1; $i<$cuantos+1; $i++)
			{
				$fila= $cursor -> FETCH_ASSOC();
				foreach ($fila as $campo => $valor)
						{
							if ($campo == "nombre_p"){
								$nombrep = $valor;
							}
							if ($campo == "precio"){
								$pre = $valor;
							}
						}
			};
			if ($v > 0){
			echo '<form action="carrito.php" method = "POST" target="blank">';
			echo "<li>";
			echo 'Artículo: '.$nombrep.' ud: '.$v.' '; 
			echo '<select name="cantidad">';
				for ($j= 1; $j<$v+1;$j++){
					if ($j ==1){
						echo '<option selected>-'.$j.'';
					}else{
						echo '<option>-'.$j.'';
					}
				}
			echo '</select>';
			echo '<input type="hidden" id="idpro" name="idpro" value="'.$k.'">';
			echo "&nbsp;";
			echo '<input type ="submit" value="Quitar" name = "Quitar">';
			echo "&nbsp;";
			$pr = $pre * $v;
			$total = $total + $pr;
			echo "Precio --> $pre €";
			echo "</li>";
			echo "</form>";
			}
	   }
	    echo "Precio total de la compra --> $total €";
		echo "<br/>";
		echo '<a href="carrito.php?confirmar=no">Comprar</a>';
	}
	echo "</ul>";
} 

?>
</div>
</div>
</body>
</html>
