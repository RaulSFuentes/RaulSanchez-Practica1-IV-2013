<?php			
			include_once("./theincludes/funciones.inc");
			$db = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
			if (isset ($_POST['Insertar'])){
				$fallo = false;
				$nombre = $_POST['nombre'];
				$precio= $_POST['precio'];
				$tipo = $_POST['tipo'];
				$ima = $_POST['ima'];
				$desc = $_POST['descrip'];
				if ($tipo == "Aceites"){
					$tip = 1;
				}else if ($tipo == "Jamones"){
					$tip = 2;
				}else if ($tipo == "Vinos"){
					$tip = 3;
				}else if ($tipo == "Quesos"){
					$tip = 4;
				}else if ($tipo == "Embutidos"){
					$tip = 5;
				}else {
					$tip = 6;
				}
				if (($nombre == "" || $precio == "" ) && $fallo == false){
					$fallo = "Los campos nombre y precio son obligatorios";
				}
				if (!is_numeric($precio) && $fallo == false){
					$fallo = "Introduzca un Precio correcto";
				}
				if($fallo == false){
					include_once('clasesubirarchivo.inc');
					$arch = new subearchivo();
					$arch->nombre=$nombre_archivo = $_FILES [ 'ima' ] [ 'name'];
					$arch->tipo=$tipo_archivo = $_FILES [ 'ima' ] [ 'type' ];
					$arch->tamanho=$tamano_archivo = $_FILES [ 'ima'] [ 'size' ];
					$arch->nombretmp=$nombre_temp = $_FILES [ 'ima' ] [ 'tmp_name' ];
					$arch->sube();
					$consulta = "INSERT INTO Producto (nombre_p,precio,id_tipo,imagen,descripcion) VALUES('".$nombre."', '".$precio."','".$tip."','".$arch->nombre."','".$desc."')";
					$cursor = $db->query($consulta);
					echo "<h3>Bienvenido $nombre.</h3>";
					echo "<br/>";
					$db->CLOSE();
				}else{
					echo "Revise:  $fallo"; 
					echo "<span><h3>Nuevo Producto</h3></span>";
				echo '<form action="index.php?op=4" method = "POST" enctype="multipart/form-data">
				Nombre: <input type="text" name = "nombre" id ="nombre" value = "'.$nombre.'">
				<br/>
				<br/>
				Precio: <input type="text" name = "precio" id ="precio" value = "'.$precio.'"> 
				<br/>
				<br/>
				Contenido: <br/>
				<textarea name="descrip" id="descrip"></textarea> 
				<br/>
				<br/>
				<br/>
				<fieldset style="width:100px">
				<legend>Tipo</legend>
				<input type="radio" name = "tipo" value="Aceites" checked="checked"> Aceites 
				<br/>
				<input type ="radio" name = "tipo" value="Jamones"> Jamones
				<br/>
				<input type ="radio" name = "tipo" value="Vinos"> Vinos
				<br/>
				<input type ="radio" name = "tipo" value="Quesos"> Quesos
				<br/>
				<input type ="radio" name = "tipo" value="Embutidos"> Embutidos	
				<br/>
				<input type ="radio" name = "tipo" value="Varios"> Varios
				</fieldset>
				<br/>
				<br/>
				Imagen: <input type ="file" name="ima" id="ima">
				<br/>
				<br/>
				<input type ="submit" value="Insertar" name = "Insertar">
				</form>';
				}
			}else{
				echo "<span><h3>Nuevo Producto</h3></span>";
				echo '<form action="index.php?op=4" method = "POST" enctype="multipart/form-data">
				Nombre: <input type="text" name = "nombre" id ="nombre">
				<br/>
				<br/>
				Precio: <input type="text" name = "precio" id ="precio">
				<br/>
				<br/>
				<br/>
				Contenido: <br/>
				<textarea name="descrip" id="descrip"></textarea> 
				<br/>
				<br/>
				<br/>
				<fieldset style="width:100px">
				<legend>Tipo</legend>
				<input type="radio" name = "tipo" value="Aceites" checked="checked"> Aceites
				<br/>
				<input type ="radio" name = "tipo" value="Jamones"> Jamones
				<br/>
				<input type ="radio" name = "tipo" value="Vinos"> Vinos
				<br/>
				<input type ="radio" name = "tipo" value="Quesos"> Quesos
				<br/>
				<input type ="radio" name = "tipo" value="Embutidos"> Embutidos	
				<br/>
				<input type ="radio" name = "tipo" value="Varios"> Varios
				</fieldset>
				<br/>
				<br/>
				Imagen: <input type ="file" name="ima" id="ima">
				<br/>
				<br/>
				<input type ="submit" value="Insertar" name = "Insertar">
				</form>';
			}
			
?>
