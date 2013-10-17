<?php
			include_once("./theincludes/funciones.inc");
			$esta = false;
			$mysqli = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
			if (isset ($_POST['mod'])){ // Comprobamos que los datos introducidos son correctos, en caso contrario se le indica
				$fallo = false;
				$esta = true;
				$cli = $_POST['idcli'];
				$nombre = $_POST['nombre'];
				$ape= $_POST['ape'];
				$fe = $_POST['fecha'];
				$fecha = $fe;
				$dire = $_POST['dire'];
				$loca = $_POST['loca'];
				$prov = $_POST['prov'];
				$pais = $_POST['pais'];
				$cp = $_POST['cp'];
				$dni = $_POST['dni'];
				$tel = $_POST['tel'];
				$email = $_POST['email'];
				$contracli = $_POST['contracli'];
				if (($contracli == "" || $nombre == "" || $ape == "" || $fecha == "" || $dire == "" || $loca == "" || $prov == "" || $pais == "" || $cp == "" || $dni == "" || $tel == "" || $email == "") && $fallo == false){
					$fallo = "Todos los campos son obligatorios";
				}
				if (!validarcp($cp) && $fallo == false){
					$fallo = "Introduzca un Código Postal correcto";
				}
				if (comprobar_dni($dni) == 0 && $fallo == false){
					$fallo = "Introduzca un DNI correcto";
				}
				if (!validarTelefono($tel) && $fallo == false){
					$fallo = "Introduzca un número de teléfono correcto";
				}
				if (comprobar_email($email) == 0 && $fallo == false){
					$fallo = "Introduzca un email correcto";
				}
				if($fallo == false){

					$fecha = null;
					$fecha = cambiafamysql($fe);
				
					$consulta = 'UPDATE Cliente SET nombre = "'.$nombre.'", apellidos = "'.$ape.'", fecha_nacimiento = "'.$fecha.'", direccion = "'.$dire.'", localidad = "'.$loca.'", provincia = "'.$prov.'", pais = "'.$pais.'", cp = "'.$cp.'", dni = "'.$dni.'", telefono = "'.$tel.'", email = "'.$email.'", contraseña = "'.$contracli.'" WHERE id_cliente = "'.$cli.'"';
					$cursor = $mysqli->query($consulta);
					echo "<h3>Modificado $nombre $ape.</h3>";
					echo "<br/>";
					$mysqli->CLOSE();
				}else{
					echo "Revise:  $fallo"; 
					echo "<span><h3>Datos Cliente</h3></span>";
				echo '<form action="index.php?op=2" method = "POST">
				Nombre: <input type="text" name = "nombre" id ="nombre" value="'.$nombre.'">
				<br/>
				<br/>
				Apellidos: <input type="text" name = "ape" id ="ape" value="'.$ape.'">
				<br/>
				<br/>
				Fecha de Nacimiento: <input type="text" name = "fecha" id ="fecha" value="'.$fecha.'">
				<br/>
				<br/>
				Dirección: <input type="text" name = "dire" id ="dire" value="'.$dire.'">
				<br/>
				<br/>
				Localidad: <input type="text" name = "loca" id ="loca" value="'.$loca.'">
				<br/>
				<br/>
				Provincia: <input type="text" name = "prov" id ="prov" value="'.$prov.'">
				<br/>
				<br/>
				País: <input type="text" name = "pais" id ="pais" value="'.$pais.'">
				<br/>
				<br/>
				Código Postal: <input type="text" name = "cp" id ="cp" value="'.$cp.'">
				<br/>
				<br/>
				DNI: <input type="text" name = "dni" id ="dni" value="'.$dni.'">
				<br/>
				<br/>
				Teléfono: <input type="text" name = "tel" id ="tel" value="'.$tel.'">
				<br/>
				<br/>
				Email: <input type="text" name = "email" id ="email" value="'.$email.'">
				<br/>
				<br/>
				Contraseña: <input type="text" name = "contracli" id ="contracli" value="'.$contracli.'">
				<br/>
				<br/>
				<input type ="submit" value="Modificar Datos" name = "mod" id = "mod">
				</form>';
				}
			}else
			if (isset ($_POST['modificacliente'])){ // Sacamos los datos del cliente solicitado
				$esta = true;
				$cli = $_POST['idcli'];
				$consulta = 'SELECT * FROM Cliente WHERE id_cliente = "'.$cli.'"';
				$cursor = $mysqli->query($consulta);
				$cuantos = $cursor->num_rows;
				echo "<span><h3>Datos Cliente</h3></span>";
				for ($i=1; $i<$cuantos+1; $i++)
				{
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=2" method = "POST">';
					foreach ($fila as $campo => $valor)
					{
							echo '<input type="hidden" name = "idcli" id ="idcli" value="'.$cli.'">';
							if ($campo == "nombre"){							
							echo 'Nombre: <input type="text" name = "nombre" id ="nombre" value="'.$valor.'">
							<br/>
							<br/>';
							};
							if ($campo == "apellidos"){
							echo 'Apellidos: <input type="text" name = "ape" id ="ape" value="'.$valor.'">
							<br/>
							<br/>';
							};
							if ($campo == "fecha_nacimiento"){
							$fech = cambiaf_a_normal($valor);
							echo 'Fecha de Nacimiento: <input type="text" name = "fecha" id ="fecha" value="'.$fech.'">
							<br/>
							<br/>';
							};
							if ($campo == "direccion"){
							echo 'Dirección: <input type="text" name = "dire" id ="dire" value="'.$valor.'">
							<br/>
							<br/>';
							};
							if ($campo == "localidad"){
							echo 'Localidad: <input type="text" name = "loca" id ="loca" value="'.$valor.'">
							<br/>
							<br/>';
							};
							if ($campo == "provincia"){
							echo 'Provincia: <input type="text" name = "prov" id ="prov" value="'.$valor.'">
							<br/>
							<br/>';
							};
							if ($campo == "pais"){
							echo 'País: <input type="text" name = "pais" id ="pais" value="'.$valor.'">
							<br/>
							<br/>';
							};
							if ($campo == "cp"){
							echo 'Código Postal: <input type="text" name = "cp" id ="cp" value="'.$valor.'">
							<br/>
							<br/>';
							};
							if ($campo == "dni"){
							echo 'DNI: <input type="text" name = "dni" id ="dni" value="'.$valor.'">
							<br/>
							<br/>';
							};
							if ($campo == "telefono"){
							echo 'Teléfono: <input type="text" name = "tel" id ="tel" value="'.$valor.'">
							<br/>
							<br/>';
							};
							if ($campo == "email"){
							echo 'Email: <input type="text" name = "email" id ="email" value="'.$valor.'">
							<br/>
							<br/>';
							};
							if ($campo == "contraseña"){
							echo 'Contraseña: <input type="text" name = "contracli" id ="contracli" value="'.$valor.'">
							<br/>
							<br/>';
							};				
							}
							echo '<input type ="submit" value="Modificar Datos" name = "mod" id = "mod">';
							echo '</form>';
					
					
				}
				
			}else if (isset ($_POST ['busquedadni'])){ // Sacamos los resultados de la búsqueda por dni
				$dni = $_POST['dni'];
				$consulta = 'SELECT * FROM Cliente WHERE dni="'.$dni.'"'; // Hacemos una consulta sobre la tabla Cliente
				$cursor= $mysqli->query($consulta);
				$cuantos = $cursor->num_rows;
				
				for ($i=1; $i<$cuantos+1; $i++)
				{
					echo "Cliente con DNI: $dni";
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=2" method = "POST">';
					echo "<ul>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_cliente"){
							echo '<input type="hidden" name = "idcli" id ="idcli" value="'.$valor.'">'; 
						}
						if ($campo == "nombre"){
						echo "<li>";
						echo'<input type ="submit" value="Modificar" name = "modificacliente" id = "modificacliente">';
						echo " --> ";
						echo "$valor";
						}
						if ($campo == "apellidos"){
						echo " $valor";						
						echo "</li>";
						}
					}
					echo "</ul>";
					echo '</form>';
					echo "<br/>";					
				};
				
			}
			else if (isset ($_POST ['busquedanombre']) && $esta == false){ // Sacamos los resultados de la búsqueda por nombre
				$nombre = $_POST['nombre'];
				$consulta = 'SELECT * FROM Cliente WHERE nombre="'.$nombre.'"'; // Hacemos una consulta sobre la tabla Cliente
				$cursor= $mysqli->query($consulta);
				$cuantos = $cursor->num_rows;
				
				for ($i=1; $i<$cuantos+1; $i++)
				{
					echo "Cliente con nombre: $nombre";
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=2" method = "POST">';
					echo "<ul>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_cliente"){
							echo '<input type="hidden" name = "idcli" id ="idcli" value="'.$valor.'">'; 
						}
						if ($campo == "nombre"){
						echo "<li>";
						echo'<input type ="submit" value="Modificar" name = "modificacliente" id = "modificacliente">';
						echo " --> ";
						echo "$valor";
						}
						if ($campo == "apellidos"){
						echo " $valor";						
						echo "</li>";
						}
					}
					echo "</ul>";
					echo '</form>';
					echo "<br/>";					
				};
				
			}
			if ($esta == false){  // Listado de todo los clientes y opciones de búsqueda
				$consulta = 'SELECT * FROM Cliente ORDER BY nombre'; // Hacemos una consulta sobre la tabla Cliente
				$cursor= $mysqli->query($consulta);
				$cuantos = $cursor->num_rows;
				$cont = 0;
				echo '<form action="index.php?op=2" method = "POST">';
				echo 'Búsqueda cliente por dni';
				echo "<br/>";
				echo 'DNI: ';
				echo '<input type="text" name = "dni" id ="dni">';
				echo' <input type ="submit" value="Búsqueda" name = "busquedadni" id = "busquedadni">';	
				echo '</form>';
				echo '<form action="index.php?op=2" method = "POST">';
				echo 'Búsqueda cliente por nombre';
				echo "<br/>";
				echo 'Nombre: ';
				echo '<input type="text" name = "nombre" id ="nombre">';
				echo' <input type ="submit" value="Búsqueda" name = "busquedanombre" id = "busquedanombre">';	
				echo "<br/>";
				echo '</form>';
				echo "Listado Completo de Clientes:";
				echo "<br/>";
				echo "<br/>";
				for ($i=1; $i<$cuantos+1; $i++)
				{
					$cont++;
					$fila= $cursor -> FETCH_ASSOC();
					echo "<ul>";
					echo '<form action="index.php?op=2" method = "POST">';
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_cliente"){
							echo '<input type="hidden" name = "idcli" id ="idcli" value="'.$valor.'">';
						}
						if ($campo == "nombre"){
						echo "<li>";
						echo'<input type ="submit" value="Modificar" name = "modificacliente" id = "modificacliente">';
						echo " --> ";
						echo "$valor";
						}
						if ($campo == "apellidos"){
						echo " $valor";						
						echo "</li>";
						}
					}
					echo '</form>';
					echo "<br/>";
					echo "</ul>";		
				};
				$cursor->FREE(); 
				$mysqli->CLOSE();
			}
?>
