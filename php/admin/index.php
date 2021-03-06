<?php
	session_start();
	session_register('us'); 
	session_register('co'); 
	if (isset ($_POST['usuario'])){
					$_SESSION['us'] = $_POST['usuario'];
					$_SESSION['co'] = $_POST['contra'];
	}
?>

<?php
/*
http://myapp-raulsanchez.rhcloud.com/

Copyright (C) 2013  Raúl Sánchez Fuentes

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
?>

<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1"> 
<meta http-equiv="content-language" content="es" />
<title>Pa chuparse los dedos</title>
<link rel="Shortcut Icon" href=""/> 
<link href="stilos.css" rel="stylesheet" type="text/css" />
<script src="jquery-1.4.2.min.js" type="text/javascript"></script> 
<script>
$(document).ready(function(){

   $("#ocultarcliente").click(function(event){
    event.preventDefault();
    $("#menuclientes").hide("slow");
	$("#ocultarcliente").hide();
   });
   $("#mostrarcliente").click(function(event){
    event.preventDefault();
    $("#menuclientes").show(1000);
	$("#ocultarcliente").show(1);
   });

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

   $("#ocultarnoticias").click(function(event){
    event.preventDefault();
    $("#menunoticias").hide("slow");
	$("#ocultarnoticias").hide();
   });
   $("#mostrarnoticias").click(function(event){
    event.preventDefault();
    $("#menunoticias").show(1000);
	$("#ocultarnoticias").show(1);
   });

   $("#ocultaradministrador").click(function(event){
    event.preventDefault();
    $("#menuadministrador").hide("slow");
	$("#ocultaradministrador").hide();
   });
   $("#mostraradministrador").click(function(event){
    event.preventDefault();
    $("#menuadministrador").show(500);
	$("#ocultaradministrador").show(1);
   });

   $("#ocultarcuenta").click(function(event){
    event.preventDefault();
    $("#menucuenta").hide("slow");
	$("#ocultarcuenta").hide();
   });
   $("#mostrarcuenta").click(function(event){
    event.preventDefault();
    $("#menucuenta").show(500);
	$("#ocultarcuenta").show(1);
   });
    $("#ocultarcompra").click(function(event){
    event.preventDefault();
    $("#menucompra").hide("slow");
	$("#ocultarcompra").hide();
   });
   $("#mostrarcompra").click(function(event){
    event.preventDefault();
    $("#menucompra").show(500);
	$("#ocultarcompra").show(1);
   });
});
</script>
</head>
<body>
	<div id="central">
		<div id = "cabecera">
			<h1>PA CHUPARSE LOS DEDOS</h1>
		</div>
		<div id = "cuerpo">
			<?php
					$entra = false;
				if (isset ($_POST['Acceder']) || isset ($_GET['op'])){
					
					$db = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
					$consulta = 'SELECT * FROM Administrador WHERE id_administrador = 1';
					$cursor= $db->query($consulta);
					$cuantos = $cursor->num_rows;
					for ($i=1; $i<$cuantos+1; $i++)
					{
						$fila= $cursor -> FETCH_ASSOC();
						foreach ($fila as $campo => $valor)
						{
							if ($campo == "nombre_a"){							
								$usu = $valor;
							};
							if ($campo == "contrase�a"){
								$contra = $valor;
							};
						}
					}
					if ($_SESSION['us'] == $usu && $_SESSION['co'] == $contra){
						$entra = true;
						$_SESSION['us'] = $usu;
						$_SESSION['co'] = $contra;
						echo '<div id = "menu">';
						echo '<p><a href="index.php">Pulse para Desconectar</a></p>';
						echo'
							<h3>MENU</h3>
							<ul>
									<li><a href="#" id="mostrarcliente">Clientes</a> <a href="#" id="ocultarcliente">-</a></li>
									<div id="menuclientes">
									<a href="index.php?op=1">Nuevo Cliente</a><br/>
									<a href="index.php?op=2">Modifica Cliente</a><br/>
									<a href="index.php?op=3">Elimina Cliente</a><br/>
									</div>
									<li><a href="#" id="mostrarproductos">Productos</a> <a href="#" id="ocultarproductos">-</a></li>
									<div id="menuproductos">
									<a href="index.php?op=4">Nuevo Producto</a><br/>
									<a href="index.php?op=5">Modifica Producto</a><br/>
									<a href="index.php?op=6">Elimina Producto</a><br/>
									</div>
									<li><a href="#" id="mostrarnoticias">Noticias</a> <a href="#" id="ocultarnoticias">-</a></li>
									<div id="menunoticias">
									<a href="index.php?op=7">Nueva Noticia</a><br/>
									<a href="index.php?op=8">Modifica Noticia</a><br/>
									<a href="index.php?op=9">Elimina Noticia</a><br/>
									</div>
									<li><a href="#" id="mostraradministrador">Administrador</a> <a href="#" id="ocultaradministrador">-</a></li>
									<div id="menuadministrador">
									<a href="index.php?op=10">Modificar Datos Administrador</a><br/>
									</div>
									<li><a href="#" id="mostrarcuenta">Cuenta</a> <a href="#" id="ocultarcuenta">-</a></li>
									<div id="menucuenta">
									<a href="index.php?op=11">Modificar Datos Cuenta</a><br/>
									</div>
									<li><a href="#" id="mostrarcompra">Compra</a> <a href="#" id="ocultarcompra">-</a></li>
									<div id="menucompra">
									<a href="index.php?op=12">Administrar Compras</a><br/>
									</div>
								</ul>
						';
						echo '</div>';
						echo '<div id = "contenido">';
							if(isset ($_GET['op'])){
								$opcion = $_GET['op'];
								switch($opcion){
									case 1: include_once("./theincludes/nuevocliente.inc"); break;
									case 2: include_once("./theincludes/modificacliente.inc");break;
									case 3: include_once("./theincludes/eliminacliente.inc");break;
									case 4: include_once("./theincludes/nuevoproducto.inc");break;
									case 5: include_once("./theincludes/modificaproducto.inc");break;
									case 6: include_once("./theincludes/eliminaproducto.inc");break;
									case 7: include_once("./theincludes/nuevanoticia.inc");break;
									case 8: include_once("./theincludes/modificanoticia.inc");break;
									case 9: include_once("./theincludes/eliminanoticia.inc");break;
									case 10: include_once("./theincludes/modificaadministador.inc");break;
									case 11: include_once("./theincludes/modificacuenta.inc");break;
									case 12: include_once("./theincludes/modificarcompra.inc");break;
								}
							}
						echo '</div>';
						
					}else{
						echo '<div id = "menu">';
						$entra = true;
						echo '<b>Usuario no valido</b>';
						echo "<br/>";
						echo "<br/>";
						echo'<div id = "forentrada">';
						echo '<form action="index.php" method = "POST">
							Usuario: <br/><input type="text" name = "usuario" id ="usuario">
							<br/>
							<br/>
							Contrase�a: <br/><input type="password" name = "contra" id ="contra">
							<br/>
							<br/>
							<input type ="submit" value="Acceder" name = "Acceder">
							</form>';
						echo'</div>';
						echo'</div>';
						echo '<div id = "contenido">';
						echo '</div>';
					}
				}
				if($entra == false){
				echo '<div id = "menu">';
				echo'<div id = "forentrada">';
				echo '<form action="index.php" method = "POST">
							Usuario: <br/><input type="text" name = "usuario" id ="usuario">
							<br/>
							<br/>
							Contrase�a: <br/><input type="password" name = "contra" id ="contra">
							<br/>
							<br/>
							<input type ="submit" value="Acceder" name = "Acceder">
							</form>';
				echo'</div>';
				echo'</div>';
				echo '<div id = "contenido">';
				echo '</div>';
				}
	?>
			</div>
	</div>
</body>
</html>
