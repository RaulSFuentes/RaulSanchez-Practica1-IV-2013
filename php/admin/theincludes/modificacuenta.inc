<?php
			$esta = false;
			include_once("./theincludes/funciones.inc");
			$db = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
			if (isset ($_POST['modcu'])){
				$esta = true;
				$fallo = false;
				$cuenta = 1;
				$numero = $_POST['numero'];
				$descripcion= $_POST['descripcion'];
				if(!validarCuenta($numero)&& $fallo == false){
					$fallo = "En el número de cuenta deben de ser 20 dígitos";
				}				
				if($fallo == false ){
					$consulta = 'UPDATE Cuenta SET numero = "'.$numero.'", descripcion = "'.$descripcion.'" WHERE id_cuenta = "'.$cuenta.'"';
					$cursor = $db->query($consulta);
					echo "<h3>Cuenta Modificada.</h3>";
					echo "<br/>";
					$db->CLOSE();
				}else{
					echo "Revise:  $fallo"; 
					echo "<span><h3>Datos Cuenta</h3></span>";
				echo '<form action="index.php?op=11" method = "POST">
				Número: <input type="text" name = "numero" id ="numero" value="'.$numero.'">
				<br/>
				<br/>
				Descripción: <input type="text" name = "descripcion" id ="descripcion" value="'.$descripcion.'">
				<br/>
				<br/>';
				echo '
				<input type ="submit" value="Modificar Datos" name = "modcu" id = "modcu">
				</form>';
				}
			}else{ 
				$esta = true;
				$cuenta = 1;
				$consulta = 'SELECT * FROM Cuenta';
				$cursor = $db->query($consulta);
				$cuantos = $cursor->num_rows;
				echo "<span><h3>Datos Cuenta</h3></span>";
				for ($i=1; $i<$cuantos+1; $i++)
				{
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=11" method = "POST">';
					foreach ($fila as $campo => $valor)
					{
							echo '<input type="hidden" name = "idcuenta" id ="idcuenta" value="'.$cuenta.'">';
							if ($campo == "numero"){							
							echo 'Número: <input type="text" name = "numero" id ="numero" value="'.$valor.'">
							<br/>
							<br/>';
							};
							if ($campo == "descripcion"){
							echo 'Descripción: <textarea name="descripcion" id="descripcion">'.$valor.'</textarea>
							<br/>
							<br/>';
							};
					}
					echo '<input type ="submit" value="Modificar Datos" name = "modcu" id = "modcu">';
					echo '</form>';
				}
			}
?>
