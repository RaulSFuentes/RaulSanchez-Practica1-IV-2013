<?php
			$esta = false;
			$db = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
				if (isset ($_POST['modad'])){
				$esta = true;
				$fallo = false;
				$admin = $_POST['idadmin'];
				$usuario = $_POST['usuar'];
				$contra= $_POST['contr'];
				if (($usuario == "" || $contra == "" ) && $fallo == false){
					$fallo = "Todos los campos son obligatorios";
				}
				if($fallo == false){
					$consulta = 'UPDATE Administrador SET nombre_a = "'.$usuario.'", contraseņa = "'.$contra.'" WHERE id_administrador = "'.$admin.'"';
					$cursor = $db->query($consulta);
					echo "<h3>Administrador Modificado: $usuario.</h3>";
					echo "<br/>";
					$db->CLOSE();
				}else{
					echo "Revise:  $fallo"; 
					echo "<span><h3>Datos Administrador</h3></span>";
				echo '<form action="index.php?op=10" method = "POST">
				Usuario: <input type="text" name = "usuar" id ="usuar" value="'.$usuario.'">
				<br/>
				<br/>
				Contraseņa: <input type="text" name = "contr" id ="contr" value="'.$contra.'">
				<br/>
				<br/>';
				echo '
				<input type ="submit" value="Modificar Datos" name = "modad" id = "modad">
				</form>';
				}
				}else{
				$esta = true;
				$admin = 1;
				$consulta = 'SELECT * FROM Administrador';
				$cursor = $db->query($consulta);
				$cuantos = $cursor->num_rows;
				echo "<span><h3>Datos Administrador</h3></span>";
				for ($i=1; $i<$cuantos+1; $i++)
				{
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=10" method = "POST">';
					foreach ($fila as $campo => $valor)
					{
							echo '<input type="hidden" name = "idadmin" id ="idadmin" value="'.$admin.'">';
							if ($campo == "nombre_a"){							
							echo 'Usuario: <input type="text" name = "usuar" id ="usuar" value="'.$valor.'">
							<br/>
							<br/>';
							};
							if ($campo == "contraseņa"){
							echo 'Contraseņa: <input type="text" name = "contr" id ="contr" value="'.$valor.'">
							<br/>
							<br/>';
							};
					}
					echo '<input type ="submit" value="Modificar Datos" name = "modad" id = "modad">';
					echo '</form>';
				}
				}
?>
