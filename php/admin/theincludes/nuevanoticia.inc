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
				$titulo = $_POST['titulo'];
				$contenido= $_POST['contenido'];
				$fe = $_POST['fecha'];
				$fecha = $fe;
				if (($titulo == "" || $contenido == "" || $fecha == "") && $fallo == false){
					$fallo = "Todos los campos son obligatorios";
				}
				if($fallo == false){
				
					$fecha = null;
					$fecha = cambiafamysql($fe);
					
					$consulta = "INSERT INTO Noticia (titulo,contenido,fecha) VALUES('".$titulo."', '".$contenido."', '".$fecha."')";
					$cursor = $db->query($consulta);
					echo "<h3>A�adida noticia: $titulo.</h3>";
					echo "<br/>";
					$db->CLOSE();
				}else{
					echo "Revise:  $fallo"; 
					echo "<span><h3>Nueva Noticia</h3></span>";
				echo '<form action="index.php?op=7" method = "POST">
				Titulo: <input type="text" name = "titulo" id ="titulo" value ="'.$titulo.'">
				<br/>
				<br/>
				Contenido: <br/>
				<textarea name="contenido" id="descrip">'.$contenido.'</textarea>
				<br/>
				<br/>
				<br/>
				Fecha: <input type="text" name = "fecha" id ="fecha" value="'.$fecha.'">
				<br/>
				<br/>
				<input type ="submit" value="Insertar" name = "Insertar">
				</form>';
				}
			}else{
				echo "<span><h3>Nueva Noticia</h3></span>";
				$today = date("d/m/Y");                       
				echo '<form action="index.php?op=7" method = "POST">
				Titulo: <input type="text" name = "titulo" id ="titulo">
				<br/>
				<br/>
				Contenido: <br/>
				<textarea name="contenido" id="descrip"></textarea> 
				<br/>
				<br/>
				<br/>
				Fecha: <input type="text" name = "fecha" id ="fecha" value="' . $today . '">
				<br/>
				<br/>
				<input type ="submit" value="Insertar" name = "Insertar">
				</form>';
			}		
?>
