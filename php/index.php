<?php
session_start();
session_register('usuario'); 
session_register('contrase'); 
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1"> 
<meta http-equiv="content-language" content="es" />
<title>Pa chuparse los dedos</title>
<link rel="Shortcut Icon" href=""/> 
<link href="stylo.css" rel="stylesheet" type="text/css" />
<script src="jquery-1.4.2.min.js" type="text/javascript"></script> 
<script>
$(document).ready(function(){

	$("#conteinicio").fadeIn(500);
	
   $("#ocultarproductos").click(function(event){
    event.preventDefault();
    $("#menuproductos").hide("slow");
	$("#ocultarproductos").hide();
   });
   $("#mostrarproductos").click(function(event){
    event.preventDefault();
    $("#menuproductos").show(1000);
	$("#ocultarproductos").show(1);
   });
   $("#enlaceinicio").click(function(event){
    event.preventDefault();
    $("#conteinicio").fadeIn(500);
	$("#conteaceite").hide();
	$("#contevino").hide();
	$("#contejamon").hide();
	$("#contequeso").hide();
	$("#conteembutido").hide();
	$("#contevarios").hide();
	$("#contenoticias").hide();
	$("#conteayuda").hide();
	$("#menuproductos").hide("slow");
	$("#ocultarproductos").hide();
   });
   $("#enlacenoticias").click(function(event){
    event.preventDefault();
    $("#contenoticias").fadeIn(500);
	$("#conteaceite").hide();
	$("#contevino").hide();
	$("#contejamon").hide();
	$("#contequeso").hide();
	$("#conteembutido").hide();
	$("#contevarios").hide();
	$("#conteinicio").hide();
	$("#conteayuda").hide();
	$("#menuproductos").hide("slow");
	$("#ocultarproductos").hide();
   });
   $("#enlaceayuda").click(function(event){
    event.preventDefault();
    $("#conteayuda").fadeIn(500);
	$("#conteinicio").hide();
	$("#conteaceite").hide();
	$("#contevino").hide();
	$("#contejamon").hide();
	$("#contequeso").hide();
	$("#conteembutido").hide();
	$("#contevarios").hide();
	$("#contenoticias").hide();
	$("#menuproductos").hide("slow");
	$("#ocultarproductos").hide();
   });
   $("#enlaceaceite").click(function(event){
    event.preventDefault();
    $("#conteaceite").fadeIn(500);
	$("#conteinicio").hide();
	$("#contevino").hide();
	$("#contejamon").hide();
	$("#contequeso").hide();
	$("#conteembutido").hide();
	$("#contevarios").hide();
	$("#contenoticias").hide();
	$("#conteregistro").hide();
	$("#conteayuda").hide();
	$("#ocultarproductos").hide();
   });
   $("#enlacejamon").click(function(event){
    event.preventDefault();
    $("#contejamon").fadeIn(500);
	$("#conteaceite").hide();
	$("#contevino").hide();
	$("#contequeso").hide();
	$("#conteembutido").hide();
	$("#contevarios").hide();
	$("#conteinicio").hide();
	$("#contenoticias").hide();
	$("#conteregistro").hide();
	$("#conteayuda").hide();
	$("#ocultarproductos").hide();
   });
   $("#enlacevino").click(function(event){
    event.preventDefault();
    $("#contevino").fadeIn(500);
	$("#conteaceite").hide();
	$("#contejamon").hide();
	$("#contequeso").hide();
	$("#conteembutido").hide();
	$("#contevarios").hide();
	$("#conteinicio").hide();
	$("#contenoticias").hide();
	$("#conteregistro").hide();
	$("#conteayuda").hide();
	$("#ocultarproductos").hide();
   });
   $("#enlacequeso").click(function(event){
    event.preventDefault();
    $("#contequeso").fadeIn(500);
	$("#conteaceite").hide();
	$("#contevino").hide();
	$("#contejamon").hide();
	$("#contevarios").hide();
	$("#conteembutido").hide();
	$("#conteinicio").hide();
	$("#contenoticias").hide();
	$("#conteregistro").hide();
	$("#conteayuda").hide();
	$("#ocultarproductos").hide();
   });
   $("#enlaceembutido").click(function(event){
    event.preventDefault();
    $("#conteembutido").fadeIn(500);
	$("#conteaceite").hide();
	$("#contevino").hide();
	$("#contejamon").hide();
	$("#contequeso").hide();
	$("#contevarios").hide();
	$("#conteinicio").hide();
	$("#contenoticias").hide();
	$("#conteregistro").hide();
	$("#conteayuda").hide();
	$("#ocultarproductos").hide();
   });
   $("#enlacevarios").click(function(event){
    event.preventDefault();
    $("#contevarios").fadeIn(500);
	$("#conteaceite").hide();
	$("#contevino").hide();
	$("#contejamon").hide();
	$("#contequeso").hide();
	$("#conteembutido").hide();
	$("#conteinicio").hide();
	$("#contenoticias").hide();
	$("#conteregistro").hide();
	$("#conteayuda").hide();
	$("#ocultarproductos").hide();
   });
});   
</script>
</head>
<body>
<div id="general">
<div id="cabecera">
	<p>PA CHUPARSE LOS DEDOS</p>
</div>
<div id="carro">
			<?php
				if (isset($_GET['eli'])){
					 session_unset();
				}
				if(isset($_POST['usu']) && isset($_POST['contra'])){
					$nombre = $_POST['usu'];
					$contrase = $_POST['contra'];
					$db = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
					$consulta = 'SELECT * FROM Cliente WHERE nombre = "'.$nombre.'" AND dni = "'.$contrase.'"';
					$cursor= $db->query($consulta);
					$cuantos = $cursor->num_rows;
					if ($cuantos >0){
						$_SESSION['usuario'] = $nombre;
						$_SESSION['contrase'] = $contrase;
						echo "<b>BIENVENIDO/A $nombre</b><br/>";
						echo '<a href="carrito.php" target="blank">Ir al carrito</a><br/>';
						echo '<a href="index.php?eli=0">Desconectar</a>';
					}else{
					?>
					<b><p>Datos incorrectos</p></b>
					<form action="index.php" method = "POST">
						  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Usuario: <input type = "text" id = "usu" name = "usu"><br/>
						Contraseña: <input type = "password" id = "contra" name = "contra"><br/>
						<input type = "submit" id = "Acceder" name = "Acceder" value="Acceder" text="Acceder"><a href="registro.php" id="enlaceregistro" target="blank">Registrarse</a>
					</form>	
				<?php
				}
				}
				else{
				
			?>
			<form action="index.php" method = "POST">
						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Usuario: <input type = "text" id = "usu" name = "usu"><br/>
				Contraseña: <input type = "password" id = "contra" name = "contra"><br/>
			<input type = "submit" id = "Acceder" name = "Acceder" value="Acceder" text="Acceder"><a href="registro.php" id="enlaceregistro" target="blank">Registrarse</a>
			</form>	
			<?php
			}
			?>
</div>
<div id="izquierda">
<div id="submenu">
	<div class='box'>
 		<div class='boxtop'>
			<div></div>
		</div>
  		<div class='boxcontent'>
			<?php
			if (isset($_GET['op'])){
				echo"entra en el iff";
			?>
			<li><a href="index.php"><p>Inicio</p></a></li>
			<li><a href="">Productos</a></li>
			<?php
			}
			else{
			?>
			<li><a href="#" id="enlaceinicio"><p>Inicio</p></a></li>
			<li><a href="#" id="mostrarproductos">Productos</a> <a href="#" id="ocultarproductos">&nbsp;&nbsp;-</a></li>
			<?php
			}
			?>
		
			<div id="menuproductos">
				<ul>
				<li><a href="#" id="enlaceaceite">Aceites</a></li>
				<li><a href="#" id="enlacejamon">Jamones</a></li>
				<li><a href="#" id="enlacevino">Vinos</a></li>
				<li><a href="#" id="enlacequeso">Quesos</a></li>
				<li><a href="#" id="enlaceembutido">Embutidos</a></li>
				<li><a href="#" id="enlacevarios">Varios</a></li>
			</div>
			<li><a href="#" id="enlacenoticias"><p>Noticias</p></a></li>
			<li><a href="#" id="enlaceayuda"><p>Ayuda</p></a></li>
			</ul>
  		</div>
 	<div class='boxbottom'>
		<div></div>
	</div>
</div>
</div>
<div id="noticias">
	<div class='box'>
	<div class='boxtop'><div></div>
	</div>
	<div class='boxcontent'>
		<?php
			include_once("./include/funciones.inc");
			$mysqli = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
			$consulta = 'SELECT * FROM Noticia ORDER BY fecha DESC';
			$cursor= $mysqli->query($consulta);
			$cuantos = $cursor->num_rows;
			for ($i=1; $i<2; $i++)
				{
					$cont++;
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="noticia.php" method = "GET">';
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_noticia"){
							$idnot = $valor;
						}
						if ($campo == "titulo"){
							echo '<b><a href="noticias.php?id='.$idnot.'" id="ennoticia" target=_blank>'.$valor.'</a></b>';
							echo "<br/>";
							echo "<br/>";
						}
						if ($campo == "contenido"){
							$conte = $valor;
							$conten= substr($conte,0,150); 
							echo "  $conten";
							echo "  ...";
							echo "<br/>";
							echo "<br/>";
						}
						if ($campo == "fecha"){
							$fech = cambiaf_a_normal($valor);
							echo "  Fecha: $fech";						
						}
					}
					echo "</form>";
			}
		?>
	  </div>
	<div class='boxbottom'>
		<div></div>
	</div>
</div>
</div>
</div>
<div id="centro">
	<div id="conteinicio">
		<h3><p id="tituloproducto">INFORMACIÓN</p></h3>
		<p>	Práctica 1, Infraestructura Virtual 2013
		</p>
	</div>
	<div id="contenoticias">
		<h3><p id="tituloproducto">NOTICIAS</p></h3>
		<?php
			include_once("./include/funciones.inc");
			include_once("./include/contenoticias.inc");
		?>
	</div>
	<div id="conteaceite">
		<h3><p id="tituloproducto">ACEITES</p></h3>
		<?php
			include_once("./include/conteaceite.inc");
		?>
	</div>
	<div id="contejamon">
		<h3><p id="tituloproducto">JAMONES</p></h3>
		<?php
			include_once("./include/contejamon.inc");
		?>
	</div>
	<div id="contevino">
		<h3><p id="tituloproducto">VINOS</p></h3>
		<?php
			include_once("./include/contevino.inc");
		?>
	</div>
	<div id="contequeso">
		<h3><p id="tituloproducto">QUESOS</p></h3>
		<?php
			include_once("./include/contequeso.inc");
		?>
	</div>
	<div id="conteembutido">
		<h3><p id="tituloproducto">EMBUTIDOS</p></h3>
		<?php
			include_once("./include/conteembutido.inc");
		?>
	</div>
	<div id="contevarios">
		<h3><p id="tituloproducto">PRODUCTOS VARIOS</p></h3>
		<?php
			include_once("./include/contevarios.inc");
		?>
	</div>
	<div id="conteayuda">
		<h3><p id="tituloproducto">PREGUNTAS FRECUENTES</p></h3>
		<br/>
		<?php
			include_once("./include/conteayuda.inc");
		?>
	</div>
</div>
<div id="derecha">
	<img src="./fondo/aa.jpg">
</div>

<div id="pie">
<br/>
<br/>
	<div class='box'>
		<div class='boxtop'><div></div></div>
		<div class='boxcontent'>
			<p><b>Contacto: email --> administrador@administrador.com TLF --> 666666666 &nbsp;&nbsp;&nbsp;<b/>
			</p>
		</div>
	<div class='boxbottom'><div></div></div>
</div>
  </div>
</div>
</body>
</html>
