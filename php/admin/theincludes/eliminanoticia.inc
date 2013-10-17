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
			if (isset ($_POST['confirmanoticia'])){
				$noti = $_POST['idnoti'];
				$consulta = 'DELETE FROM Noticia WHERE id_noticia = "'.$noti.'"';
				$cursor = $db->query($consulta);
				echo "<h3>Noticia Eliminada</h3>";
				echo "<br/>";
			}else	
			if (isset ($_POST['eliminanoticia'])){
				$not = $_POST['idnoti'];
				$fecha = cambiafamysql($fech);
				$consulta = 'SELECT * FROM Noticia WHERE id_noticia = "'.$not.'"'; // Hacemos una consulta sobre la tabla Noticia
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				
				for ($i=1; $i<$cuantos+1; $i++)
				{
					echo "¿Esta seguro que desea eliminarlo?";
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=9" method = "POST">';
					echo "<ul>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_noticia"){
							echo '<input type="hidden" name = "idnoti" id ="idnoti" value="'.$valor.'">'; 
						}
						if ($campo == "titulo"){
						echo "<li>";
						echo'<input type ="submit" value="Confirmar" name = "confirmanoticia" id = "confirmanoticia">';
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
			}else if (isset ($_POST ['busquedafecha'])){ // Sacamos los resultados de la búsqueda por fecha
				$fech = $_POST['fecha'];
				$fecha = cambiafamysql($fech);
				$consulta = 'SELECT * FROM Noticia WHERE fecha = "'.$fecha.'" ORDER BY fecha DESC'; // Hacemos una consulta sobre la tabla Noticia
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				
				for ($i=1; $i<$cuantos+1; $i++)
				{
					echo "Noticia con fecha : $fecha";
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=9" method = "POST">';
					echo "<ul>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_noticia"){
							echo '<input type="hidden" name = "idnoti" id ="idnoti" value="'.$valor.'">'; 
						}
						if ($campo == "titulo"){
						echo "<li>";
						echo'<input type ="submit" value="Eliminar" name = "eliminanoticia" id = "eliminanoticia">';
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
				$consulta = 'SELECT * FROM Noticia ORDER BY fecha DESC'; // Hacemos una consulta sobre la tabla Producto
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				$cont = 0;
				echo '<form action="index.php?op=9" method = "POST">';
				echo 'Búsqueda producto por Fecha';
				echo "<br/>";
				echo 'Fecha: ';
				echo '<input type="text" name = "fecha" id ="fecha">';
				echo' <input type ="submit" value="Búsqueda" name = "busquedafecha" id = "busquedafecha">';	
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
					echo '<form action="index.php?op=9" method = "POST">';
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_noticia"){
							echo '<input type="hidden" name = "idnoti" id ="idnoti" value="'.$valor.'">';
						}
						if ($campo == "titulo"){
						echo "<li>";
						echo'<input type ="submit" value="Eliminar" name = "eliminanoticia" id = "eliminanoticia">';
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
?>
