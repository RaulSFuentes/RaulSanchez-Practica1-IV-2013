<?php
				$db = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
				$consulta = 'SELECT * FROM Producto WHERE id_tipo = 6';
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				for ($i=1; $i<$cuantos+1; $i++)
				{
					echo '<div id="produc">';
					$fila= $cursor -> FETCH_ASSOC();
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_producto"){
							$idpro = $valor;
						}
						if ($campo == "nombre_p"){
						echo '<div id="nombrepro">';
						echo "<b>Producto:</b> $valor";
						echo "<br/>";
						echo "<br/>";
						}
						if ($campo == "precio"){
						echo "<b>Precio:</b> $valor €";
						echo "<br/>";
						echo "<br/>";
						echo "</div>";
						}
						if ($campo == "imagen"){
						echo '<div id="imagenpro">';
						if ($valor == null){
						echo '<img id="imgpro" src="./fondo/nodisponible.jpg">';
						}else{
						echo '<p><img id="imgpro" src="../Administrador/imagenes/'.$valor.'" alt="'.$valor.'"></p>';
						}
						echo "</div>";
						}
						if ($campo == "descripcion"){
						echo '<div id="descripcionpro">';
						echo "<b>Descripción:</b> $valor";
						echo "<br/>";
						}
					}
					$uuu = $_SESSION['usuario'];
					if ($uuu != null) {
						echo '<form action="carrito.php" method = "POST" target="blank">';
							echo '<select name="cantidad">';
								for ($j= 1; $j<30;$j++){
									if ($j ==1){
										echo '<option selected>'.$j.'';
									}else{
										echo '<option>'.$j.'';
									}
								}
							echo '</select>';
							echo '<input type="hidden" id="idpro" name="idpro" value="'.$idpro.'">';
							echo '<input type ="submit" value="Añadir" name = "Insertar">';
						echo "</form>";
					}
					else{
						echo "<br/>";
						echo "<b>Debe de estar logeado para comprar</b>";
					}
					echo "</div>";
					echo "<br/>";
					echo "<br/>";
					echo '</div>';
					echo "<p>";
					echo "&nbsp;";
					echo "</p>";
				};
				$db->CLOSE();
?>
