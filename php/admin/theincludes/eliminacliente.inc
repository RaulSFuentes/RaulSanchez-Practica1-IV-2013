<?php
			$db = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
			if (isset ($_POST['confirmacliente'])){
				$usu = $_POST['idusu'];
				$consulta = 'DELETE FROM Cliente WHERE id_cliente = "'.$usu.'"';
				$cursor = $db->query($consulta);
				echo "<h3>Cliente Eliminado3</h3>";
				echo "<br/>";
			}else
			if (isset ($_POST['eliminacliente'])){
			$idu = $_POST['idusu'];
				$consulta = 'SELECT * FROM Cliente WHERE id_cliente="'.$idu.'"'; // Hacemos una consulta sobre la tabla Cliente
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				for ($i=1; $i<$cuantos+1; $i++)
				{
					echo "�Esta seguro que desea eliminarlo?";
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=3" method = "POST">';
					echo "<ul>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_cliente"){
							echo '<input type="hidden" name = "idusu" id ="idusu" value="'.$valor.'">'; 
						}
						if ($campo == "nombre"){
						echo "<li>";
						echo'<input type ="submit" value="Confirmar" name = "confirmacliente" id = "confirmacliente">';
						echo " --> ";
						echo "$valor";
						}
						if ($campo == "apellidos"){
						echo " $valor ";						
						}
						if ($campo == "dni"){
						echo " $valor";						
						echo "</li>";
						}
					}
					echo "</ul>";
					echo '</form>';
					echo "<br/>";					
				};
			}else if (isset ($_POST ['busquedadni'])){ // Sacamos los resultados de la b�squeda por dni
				$dni = $_POST['dni'];
				$consulta = 'SELECT * FROM Cliente WHERE dni="'.$dni.'"'; // Hacemos una consulta sobre la tabla Cliente
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				for ($i=1; $i<$cuantos+1; $i++)
				{
					echo "Cliente con DNI: $dni";
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=3" method = "POST">';
					echo "<ul>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_cliente"){
							echo '<input type="hidden" name = "idusu" id ="idusu" value="'.$valor.'">'; 
						}
						if ($campo == "nombre"){
						echo "<li>";
						echo'<input type ="submit" value="Eliminar" name = "eliminacliente" id = "eliminacliente">';
						echo " --> ";
						echo "$valor";
						}
						if ($campo == "apellidos"){
						echo " $valor ";						
						}
						if ($campo == "dni"){
						echo " $valor";						
						echo "</li>";
						}
					}
					echo "</ul>";
					echo '</form>';
					echo "<br/>";					
				};
				
			}
			else if (isset ($_POST ['busquedanombre'])){ // Sacamos los resultados de la b�squeda por nombre
				$nombre = $_POST['nombre'];
				$consulta = 'SELECT * FROM Cliente WHERE nombre="'.$nombre.'"'; // Hacemos una consulta sobre la tabla Cliente
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				for ($i=1; $i<$cuantos+1; $i++)
				{
					echo "Cliente con nombre: $nombre";
					$fila= $cursor -> FETCH_ASSOC();
					echo "<ul>";
					echo '<form action="index.php?op=3" method = "POST">';
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_cliente"){
							echo '<input type="hidden" name = "idusu" id ="idusu" value="'.$valor.'">'; 
						}
						if ($campo == "nombre"){
						echo "<li>";
						echo'<input type ="submit" value="Eliminar" name = "eliminacliente" id = "eliminacliente">';
						echo " --> ";
						echo "$valor";
						}
						if ($campo == "apellidos"){
						echo " $valor";						
						}
						if ($campo == "dni"){
						echo " $valor";						
						echo "</li>";
						}
					}
					echo "</ul>";
					echo '</form';
					echo "<br/>";					
				};
			}
				$consulta = 'SELECT * FROM Cliente ORDER BY nombre'; // Hacemos una consulta sobre la tabla Cliente
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				$cont = 0;
				echo '<form action="index.php?op=3" method = "POST">';
				echo 'B�squeda cliente por dni';
				echo "<br/>";
				echo 'DNI: ';
				echo '<input type="text" name = "dni" id ="dni">';
				echo' <input type ="submit" value="B�squeda" name = "busquedadni" id = "busquedadni">';	
				echo '</form>';
				echo '<form action="index.php?op=3" method = "POST">';
				echo 'B�squeda cliente por nombre';
				echo "<br/>";
				echo 'Nombre: ';
				echo '<input type="text" name = "nombre" id ="nombre">';
				echo' <input type ="submit" value="B�squeda" name = "busquedanombre" id = "busquedanombre">';	
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
					echo '<form action="index.php?op=3" method = "POST">';
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_cliente"){
							echo '<input type="hidden" name = "idusu" id ="idusu" value="'.$valor.'">';
						}
						if ($campo == "nombre"){
						echo "<li>";
						echo'<input type ="submit" value="Eliminar" name = "eliminacliente" id = "eliminacliente">';
						echo " --> ";
						echo "$valor";
						}
						if ($campo == "apellidos"){
						echo " $valor";						
						}
						if ($campo == "dni"){
						echo " $valor";						
						echo "</li>";
						}
					}
					echo '</form>';
					echo "<br/>";
					echo "</ul>";		
				};
				$cursor->FREE(); 
				$db->CLOSE();
?>
