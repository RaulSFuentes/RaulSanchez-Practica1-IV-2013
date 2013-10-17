<?php
			$db = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
			if (isset ($_POST['confirmaproducto'])){
			$pro = $_POST['idpro'];
				$consulta = 'DELETE FROM Producto WHERE id_producto = "'.$pro.'"';
				$cursor = $db->query($consulta);
				echo "<h3>Producto Eliminado</h3>";
				echo "<br/>";
			}else
			if (isset ($_POST['eliminaproducto'])){
			$pro = $_POST['idpro'];
				$consulta = 'SELECT * FROM Producto WHERE id_producto = "'.$pro.'"'; // Hacemos una consulta sobre la tabla producto
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				
				for ($i=1; $i<$cuantos+1; $i++)
				{
					echo "¿Esta seguro que desea eliminarlo?";
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=6" method = "POST">';
					echo "<ul>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_producto"){
							echo '<input type="hidden" name = "idpro" id ="idpro" value="'.$valor.'">'; 
						}
						if ($campo == "nombre_p"){
						echo "<li>";
						echo'<input type ="submit" value="Confirmar" name = "confirmaproducto" id = "confirmaproducto">';
						echo " --> ";
						echo "$valor";				
						}
						if ($campo == "tipo"){
						echo " , tipo: $valor";						
						echo "</li>";
						}
					}
					echo "</ul>";
					echo '</form>';
					echo "<br/>";
				}
			}else if (isset ($_POST ['busquedanombre'])){ // Sacamos los resultados de la búsqueda por nombre
				$nombre = $_POST['nombre'];
				$consulta = 'SELECT * FROM Producto WHERE nombre_p = "'.$nombre.'" ORDER BY id_tipo ASC'; // Hacemos una consulta sobre la tabla producto
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				
				for ($i=1; $i<$cuantos+1; $i++)
				{
					echo "Producto con nombre : $nombre";
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=6" method = "POST">';
					echo "<ul>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_producto"){
							echo '<input type="hidden" name = "idpro" id ="idpro" value="'.$valor.'">'; 
						}
						if ($campo == "nombre_p"){
						echo "<li>";
						echo'<input type ="submit" value="Eliminar" name = "eliminaproducto" id = "eliminaproducto">';
						echo " --> ";
						echo "$valor";				
						}
						if ($campo == "tipo"){
						echo " , tipo: $valor";						
						echo "</li>";
						}
					}
					echo "</ul>";
					echo '</form>';
					echo "<br/>";					
				};
				
			}
			else if (isset ($_POST ['busquedatipo'])){ // Sacamos los resultados de la búsqueda por tipo
				$tipo = $_POST['tipo'];
				$consulta = 'SELECT * FROM Producto WHERE id_tipo="'.$tipo.'" ORDER BY id_tipo ASC'; // Hacemos una consulta sobre la tabla producto
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				
				for ($i=1; $i<$cuantos+1; $i++)
				{
					echo "Productos del tipo : $tipo";
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=6" method = "POST">';
					echo "<ul>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_producto"){
							echo '<input type="hidden" name = "idpro" id ="idpro" value="'.$valor.'">'; 
						}
						if ($campo == "nombre_p"){
						echo "<li>";
						echo'<input type ="submit" value="Eliminar" name = "eliminaproducto" id = "eliminaproducto">';
						echo " --> ";
						echo "$valor";
						}
						if ($campo == "tipo"){
						echo " , tipo: $valor";						
						echo "</li>";
						}
					}
					echo "</ul>";
					echo '</form>';
					echo "<br/>";					
				};
				
			}
				$consulta = 'SELECT * FROM Producto ORDER BY id_tipo ASC'; // Hacemos una consulta sobre la tabla Producto
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				$cont = 0;
				echo '<form action="index.php?op=6" method = "POST">';
				echo 'Búsqueda producto por nombre';
				echo "<br/>";
				echo 'Nombre: ';
				echo '<input type="text" name = "nombre" id ="nombre">';
				echo' <input type ="submit" value="Búsqueda" name = "busquedanombre" id = "busquedanombre">';	
				echo '</form>';
				echo '<form action="index.php?op=6" method = "POST">';
				echo 'Búsqueda producto por tipo';
				echo "<br/>";
				echo 'Tipo: ';
				echo '<input type="text" name = "tipo" id ="tipo">';
				echo' <input type ="submit" value="Búsqueda" name = "busquedatipo" id = "busquedatipo">';	
				echo "<br/>";
				echo '</form>';
				echo "Listado Completo de Productos:";
				echo "<br/>";
				echo "<br/>";
				for ($i=1; $i<$cuantos+1; $i++)
				{
					$cont++;
					$fila= $cursor -> FETCH_ASSOC();
					echo "<ul>";
					echo '<form action="index.php?op=6" method = "POST">';
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_producto"){
							echo '<input type="hidden" name = "idpro" id ="idpro" value="'.$valor.'">';
						}
						if ($campo == "nombre_p"){
						echo "<li>";
						echo'<input type ="submit" value="Eliminar" name = "eliminaproducto" id = "eliminaproducto">';
						echo " --> ";
						echo "$valor";
						}
						if ($campo == "apellidos"){
						echo " , tipo: $valor";						
						echo "</li>";
						}
					}
					echo '</form>';
					echo "<br/>";
					echo "</ul>";		
				};
				$db->CLOSE();
?>
