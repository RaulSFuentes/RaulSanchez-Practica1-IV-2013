<?php
			include_once("./theincludes/funciones.inc");
			$esta = false;
			$db = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
			if (isset ($_POST['modnoti'])){
				$esta = true;
				$fallo = false;
				$noti = $_POST['idnoti'];
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
				
					$consulta = 'UPDATE Noticia SET titulo = "'.$titulo.'", contenido = "'.$contenido.'", fecha = "'.$fecha.'" WHERE id_noticia = "'.$noti.'"';
					$cursor = $db->query($consulta);
					echo "<h3>Noticia Modificada: $titulo.</h3>";
					echo "<br/>";
					$db->CLOSE();
				}else{
					echo "Revise:  $fallo"; 
					echo "<span><h3>Datos Noticia</h3></span>";
				echo '<form action="index.php?op=8" method = "POST">
				Nombre: Titulo: <input type="text" name = "titulo" id ="titulo" value="'.$titulo.'">
				<br/>
				<br/>
				Contenido: <br/>
				<textarea name="contenido" id="descrip">'.$contenido.'</textarea>
				<br/>
				<br/>
				<br/>';
				echo 'Fecha: <input type="text" name = "fecha" id ="fecha" value="'.$fecha.'">
				<br/>
				<br/>';
				echo '
				<input type ="submit" value="Modificar Datos" name = "modnoti" id = "modnoti">
				</form>';
				}
			}else
			if (isset ($_POST['modificanoticia'])){ // Sacamos los datos de la noticia solicitada
				$esta = true;
				$noti = $_POST['idnoti'];
				$consulta = 'SELECT * FROM Noticia WHERE id_noticia = "'.$noti.'"';
				$cursor = $db->query($consulta);
				$cuantos = $cursor->num_rows;
				echo "<span><h3>Datos Noticia</h3></span>";
				for ($i=1; $i<$cuantos+1; $i++)
				{
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=8" method = "POST">';
					foreach ($fila as $campo => $valor)
					{
							echo '<input type="hidden" name = "idnoti" id ="idnoti" value="'.$noti.'">';
							if ($campo == "titulo"){							
							echo 'Titulo: <input type="text" name = "titulo" id ="titulo" value="'.$valor.'">
							<br/>
							<br/>';
							};
							if ($campo == "contenido"){
							echo 'Contenido: <br/>
							<textarea name="contenido" id="descrip">'.$valor.'</textarea>
							<br/>
							<br/>
							<br/>';
							};
							if ($campo == "fecha"){
							$fecha = cambiaf_a_normal($valor);
							echo 'Fecha: <input type="text" name = "fecha" id ="fecha" value="'.$fecha.'">
							<br/>
							<br/>';
							};
					}
					echo '<input type ="submit" value="Modificar Datos" name = "modnoti" id = "modnoti">';
					echo '</form>';
				}
			}else if (isset ($_POST ['busquedafecha'])){ // Sacamos los resultados de la b�squeda por fecha
				$fech = $_POST['fecha'];
				$fecha = cambiafamysql($fech);
				$consulta = 'SELECT * FROM Noticia WHERE fecha = "'.$fecha.'" ORDER BY fecha DESC'; // Hacemos una consulta sobre la tabla Noticia
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				
				for ($i=1; $i<$cuantos+1; $i++)
				{
					echo "Noticia con fecha : $fecha";
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=8" method = "POST">';
					echo "<ul>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_noticia"){
							echo '<input type="hidden" name = "idnoti" id ="idnoti" value="'.$valor.'">'; 
						}
						if ($campo == "titulo"){
						echo "<li>";
						echo'<input type ="submit" value="Modificar" name = "modificanoticia" id = "modificanoticia">';
						echo " --> ";
						echo "$valor";				
						}
						if ($campo == "fecha"){
						$fech = cambiaf_a_normal($valor);
						echo " , Fecha: $fech";						
						echo "</li>";
						}
					}
					echo "</ul>";
					echo '</form>';
					echo "<br/>";					
				};
				
			}
			if ($esta == false){  // Listado de todas las noticias y opciones de b�squeda
				$consulta = 'SELECT * FROM Noticia ORDER BY fecha DESC'; // Hacemos una consulta sobre la tabla Noticia
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				$cont = 0;
				echo '<form action="index.php?op=8" method = "POST">';
				echo 'B�squeda producto por Fecha';
				echo "<br/>";
				echo 'Fecha: ';
				echo '<input type="text" name = "fecha" id ="fecha">';
				echo' <input type ="submit" value="B�squeda" name = "busquedafecha" id = "busquedafecha">';	
				echo '</form>';
				echo "<br/>";
				echo '</form>';
				echo "Listado Completo de Noticias:";
				echo "<br/>";
				echo "<br/>";
				for ($i=1; $i<$cuantos+1; $i++)
				{
					$cont++;
					$fila= $cursor -> FETCH_ASSOC();
					echo "<ul>";
					echo '<form action="index.php?op=8" method = "POST">';
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_noticia"){
							echo '<input type="hidden" name = "idnoti" id ="idnoti" value="'.$valor.'">';
						}
						if ($campo == "titulo"){
						echo "<li>";
						echo'<input type ="submit" value="Modificar" name = "modificanoticia" id = "modificanoticia">';
						echo " --> ";
						echo "$valor";
						}
						if ($campo == "fecha"){
						$fech = cambiaf_a_normal($valor);
						echo " , Fecha: $fech";						
						echo "</li>";
						}
					}
					echo '</form>';
					echo "<br/>";
					echo "</ul>";		
				};
				$db->CLOSE();
			}
?>
