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
			if (isset ($_POST['modcompra'])){
				$esta = true;
				$fallo = false;
				$comp = $_POST['idcomp'];
				$paga = $_POST['pagad'];
				if ($paga == "si"){
					$paga = 1;
				}else{
						$paga = 0;
				}
				$envia= $_POST['enviad'];
				if ($envia == "si"){
					$envia = 1;
				}else{
						$envia = 0;
				}				
					$consulta = 'UPDATE Compra SET pagado = "'.$paga.'", enviado = "'.$envia.'" WHERE id_compra = "'.$comp.'"';
					$cursor = $db->query($consulta);
					echo "<h3>Noticia Modificada: $titulo.</h3>";
					echo "<br/>";

					$consulta3 = 'SELECT * FROM Compra ORDER BY fecha DESC';
				$cursor3= $db->query($consulta3);
				$cuantos3 = $cursor3->num_rows;
				echo '<form action="index.php?op=12" method = "POST">';
				echo 'B�squeda Compra por Id compra:';
				echo "<br/>";
				echo 'Id compra: ';
				echo '<input type="text" name = "idcompra" id ="idcompra">';
				echo' <input type ="submit" value="B�squeda" name = "busquedaidcompra" id = "busquedaidcompra">';	
				echo '</form>';
				echo "<br/>";
				echo '<form action="index.php?op=12" method = "POST">';
				echo 'B�squeda Compra por Id cliente:';
				echo "<br/>";
				echo 'Id cliente: ';
				echo '<input type="text" name = "idcliente" id ="idcliente">';
				echo' <input type ="submit" value="B�squeda" name = "busquedaidcliente" id = "busquedaidcliente">';	
				echo '</form>';
				echo "<br/>";
				echo "Listado Completo de Compras:";
				echo "<br/>";
				echo "<br/>";
				echo '<table id="tablacompra">';
				echo "<tr>";
				echo "<th>Id Compra</th>";
				echo "<th>Id Cliente</th>";
				echo "<th>Nombre Cliente</th>";
				echo "<th>Fecha</th>";
				echo "<th>Pagado</th>";
				echo "<th>Enviado</th>";
				echo "<th>Productos</th>";
				echo "<th>Precio</th>";
				echo "</tr>";
				for ($i=1; $i<$cuantos3+1; $i++)
				{
					$fila3= $cursor3 -> FETCH_ASSOC();
					echo '<form action="index.php?op=12" method = "POST">';
					echo "<tr>";
					foreach ($fila3 as $campo => $valor)
					{
						if ($campo == "id_compra"){
							echo '<input type="hidden" name = "idcomp" id ="idcomp" value="'.$valor.'">';
							echo "<td>";
							echo "$valor";
							echo "</td>";
						}
						if ($campo == "id_cliente"){
							echo "<td>";
							echo "$valor";
							echo "</td>";
							echo "<td>";
								$consulta2 = 'SELECT * FROM Cliente WHERE id_cliente= '.$valor.''; 
								$cursor2= $db->query($consulta2);
								$cuantos2 = $cursor2->num_rows;
								$cade = "";
								for ($j=1; $j<$cuantos2+1; $j++)
								{
									$fila2= $cursor2 -> FETCH_ASSOC();
									foreach ($fila2 as $campo2 => $valor2)
											{
												if ($campo2 == "nombre"){
													$cade .= $valor2;
												}
												if ($campo2 == "apellidos"){
													$cade .= " " . $valor2;
												}
											}
								};
								echo "$cade";
							echo "</td>";
						}
						if ($campo == "fecha"){
						$fech = cambiaf_a_normal($valor);
							echo "<td>";
							echo "$fech";
							echo "</td>";
						}
						if ($campo == "pagado"){
							if ($valor == 0){
								$valor1 = "no";
								$valor2 = "si";
							}else{
								$valor2 = "no";
								$valor1 = "si";
							}
							echo "<td>";
							echo '<select name="pagad">';
									echo '<option selected>'.$valor1.'';
									echo '<option >'.$valor2.'';
							echo '</select>';
							echo "</td>";
							echo '<input type="hidden" name = "paga" id ="paga" value="'.$valor.'">';
						}
						if ($campo == "enviado"){
									if ($valor == 0){
								$valor1 = "no";
								$valor2 = "si";
							}else{
								$valor2 = "no";
								$valor1 = "si";
							}
							echo "<td>";
							echo '<select name="enviad">';
									echo '<option selected>'.$valor1.'';
									echo '<option >'.$valor2.'';
							echo '</select>';
							echo "</td>";
							echo '<input type="hidden" name = "envia" id ="envia" value="'.$valor.'">';
						}
						if ($campo == "productos"){
							echo "<td>";
							echo "$valor";
							echo "</td>";
						}
						if ($campo == "precio"){
							echo "<td>";
							echo "$valor";
							echo "</td>";
						}
					}
					echo "<td>";
					echo '<input type ="submit" value="Cambiar" name = "modcompra" id = "modcompra">';
					echo "</td>";
					echo "</tr>";	
					echo '</form>';
				};
				echo "</table>";
				
			}else
			if (isset ($_POST['busquedaidcompra'])){ 
				$esta = true;
				$comp = $_POST['idcompra'];
				$consulta = 'SELECT * FROM Compra WHERE id_compra = "'.$comp.'"';
				$cursor = $db->query($consulta);
				$cuantos = $cursor->num_rows;
				echo '<form action="index.php?op=12" method = "POST">';
				echo 'B�squeda Compra por Id compra:';
				echo "<br/>";
				echo 'Id compra: ';
				echo '<input type="text" name = "idcompra" id ="idcompra">';
				echo' <input type ="submit" value="B�squeda" name = "busquedaidcompra" id = "busquedaidcompra">';	
				echo '</form>';
				echo "<br/>";
				echo '<form action="index.php?op=12" method = "POST">';
				echo 'B�squeda Compra por Id cliente:';
				echo "<br/>";
				echo 'Id cliente: ';
				echo '<input type="text" name = "idcliente" id ="idcliente">';
				echo' <input type ="submit" value="B�squeda" name = "busquedaidcliente" id = "busquedaidcliente">';	
				echo '</form>';
				echo "<br/>";
				echo "Listado Completo de Compras:";
				echo "<br/>";
				echo "<br/>";
				echo '<table id="tablacompra">';
				echo "<tr>";
				echo "<th>Id Compra</th>";
				echo "<th>Id Cliente</th>";
				echo "<th>Nombre Cliente</th>";
				echo "<th>Fecha</th>";
				echo "<th>Pagado</th>";
				echo "<th>Enviado</th>";
				echo "<th>Productos</th>";
				echo "<th>Precio</th>";
				echo "</tr>";
				for ($i=1; $i<$cuantos+1; $i++)
				{
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=12" method = "POST">';
					echo "<tr>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_compra"){
							echo '<input type="hidden" name = "idcomp" id ="idcomp" value="'.$valor.'">';
							echo "<td>";
							echo "$valor";
							echo "</td>";
						}
						if ($campo == "id_cliente"){
							echo "<td>";
							echo "$valor";
							echo "</td>";
							echo "<td>";
								$consulta2 = 'SELECT * FROM Cliente WHERE id_cliente= '.$valor.''; 
								$cursor2= $db->query($consulta2);
								$cuantos2 = $cursor2->num_rows;
								$cade = "";
								for ($j=1; $j<$cuantos2+1; $j++)
								{
									$fila2= $cursor2 -> FETCH_ASSOC();
									foreach ($fila2 as $campo2 => $valor2)
											{
												if ($campo2 == "nombre"){
													$cade .= $valor2;
												}
												if ($campo2 == "apellidos"){
													$cade .= " " . $valor2;
												}
											}
								};
								echo "$cade";
							echo "</td>";
						}
						if ($campo == "fecha"){
						$fech = cambiaf_a_normal($valor);
							echo "<td>";
							echo "$fech";
							echo "</td>";
						}
						if ($campo == "pagado"){
							if ($valor == 0){
								$valor1 = "no";
								$valor2 = "si";
							}else{
								$valor2 = "no";
								$valor1 = "si";
							}
							echo "<td>";
							echo '<select name="pagad">';
									echo '<option selected>'.$valor1.'';
									echo '<option >'.$valor2.'';
							echo '</select>';
							echo "</td>";
							echo '<input type="hidden" name = "paga" id ="paga" value="'.$valor.'">';
						}
						if ($campo == "enviado"){
									if ($valor == 0){
								$valor1 = "no";
								$valor2 = "si";
							}else{
								$valor2 = "no";
								$valor1 = "si";
							}
							echo "<td>";
							echo '<select name="enviad">';
									echo '<option selected>'.$valor1.'';
									echo '<option >'.$valor2.'';
							echo '</select>';
							echo "</td>";
							echo '<input type="hidden" name = "envia" id ="envia" value="'.$valor.'">';
						}
						if ($campo == "productos"){
							echo "<td>";
							echo "$valor";
							echo "</td>";
						}
						if ($campo == "precio"){
							echo "<td>";
							echo "$valor";
							echo "</td>";
						}
					}
					echo "<td>";
					echo '<input type ="submit" value="Cambiar" name = "modcompra" id = "modcompra">';
					echo "</td>";
					echo "</tr>";	
					echo '</form>';
				};
				echo "</table>";
				$db->CLOSE();
				
				
			}
			else
			if (isset ($_POST['busquedaidcliente'])){ 
				$esta = true;
				$clie = $_POST['idcliente'];
				$consulta = 'SELECT * FROM Compra WHERE id_cliente = "'.$clie.'"';
				$cursor = $db->query($consulta);
				$cuantos = $cursor->num_rows;
				echo '<form action="index.php?op=12" method = "POST">';
				echo 'B�squeda Compra por Id compra:';
				echo "<br/>";
				echo 'Id compra: ';
				echo '<input type="text" name = "idcompra" id ="idcompra">';
				echo' <input type ="submit" value="B�squeda" name = "busquedaidcompra" id = "busquedaidcompra">';	
				echo '</form>';
				echo "<br/>";
				echo '<form action="index.php?op=12" method = "POST">';
				echo 'B�squeda Compra por Id cliente:';
				echo "<br/>";
				echo 'Id cliente: ';
				echo '<input type="text" name = "idcliente" id ="idcliente">';
				echo' <input type ="submit" value="B�squeda" name = "busquedaidcliente" id = "busquedaidcliente">';	
				echo '</form>';
				echo "<br/>";
				echo "Listado Completo de Compras:";
				echo "<br/>";
				echo "<br/>";
				echo '<table id="tablacompra">';
				echo "<tr>";
				echo "<th>Id Compra</th>";
				echo "<th>Id Cliente</th>";
				echo "<th>Nombre Cliente</th>";
				echo "<th>Fecha</th>";
				echo "<th>Pagado</th>";
				echo "<th>Enviado</th>";
				echo "<th>Productos</th>";
				echo "<th>Precio</th>";
				echo "</tr>";
				for ($i=1; $i<$cuantos+1; $i++)
				{
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=12" method = "POST">';
					echo "<tr>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_compra"){
							echo '<input type="hidden" name = "idcomp" id ="idcomp" value="'.$valor.'">';
							echo "<td>";
							echo "$valor";
							echo "</td>";
						}
						if ($campo == "id_cliente"){
							echo "<td>";
							echo "$valor";
							echo "</td>";
							echo "<td>";
								$consulta2 = 'SELECT * FROM Cliente WHERE id_cliente= '.$valor.''; 
								$cursor2= $db->query($consulta2);
								$cuantos2 = $cursor2->num_rows;
								$cade = "";
								for ($j=1; $j<$cuantos2+1; $j++)
								{
									$fila2= $cursor2 -> FETCH_ASSOC();
									foreach ($fila2 as $campo2 => $valor2)
											{
												if ($campo2 == "nombre"){
													$cade .= $valor2;
												}
												if ($campo2 == "apellidos"){
													$cade .= " " . $valor2;
												}
											}
								};
								echo "$cade";
							echo "</td>";
						}
						if ($campo == "fecha"){
						$fech = cambiaf_a_normal($valor);
							echo "<td>";
							echo "$fech";
							echo "</td>";
						}
						if ($campo == "pagado"){
							if ($valor == 0){
								$valor1 = "no";
								$valor2 = "si";
							}else{
								$valor2 = "no";
								$valor1 = "si";
							}
							echo "<td>";
							echo '<select name="pagad">';
									echo '<option selected>'.$valor1.'';
									echo '<option >'.$valor2.'';
							echo '</select>';
							echo "</td>";
							echo '<input type="hidden" name = "paga" id ="paga" value="'.$valor.'">';
						}
						if ($campo == "enviado"){
									if ($valor == 0){
								$valor1 = "no";
								$valor2 = "si";
							}else{
								$valor2 = "no";
								$valor1 = "si";
							}
							echo "<td>";
							echo '<select name="enviad">';
									echo '<option selected>'.$valor1.'';
									echo '<option >'.$valor2.'';
							echo '</select>';
							echo "</td>";
							echo '<input type="hidden" name = "envia" id ="envia" value="'.$valor.'">';
						}
						if ($campo == "productos"){
							echo "<td>";
							echo "$valor";
							echo "</td>";
						}
						if ($campo == "precio"){
							echo "<td>";
							echo "$valor";
							echo "</td>";
						}
					}
					echo "<td>";
					echo '<input type ="submit" value="Cambiar" name = "modcompra" id = "modcompra">';
					echo "</td>";
					echo "</tr>";	
					echo '</form>';
				};
				echo "</table>";
				$db->CLOSE();
			}
			if ($esta == false){  
				$consulta = 'SELECT * FROM Compra ORDER BY fecha DESC';
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				echo '<form action="index.php?op=12" method = "POST">';
				echo 'B�squeda Compra por Id compra:';
				echo "<br/>";
				echo 'Id compra: ';
				echo '<input type="text" name = "idcompra" id ="idcompra">';
				echo' <input type ="submit" value="B�squeda" name = "busquedaidcompra" id = "busquedaidcompra">';	
				echo '</form>';
				echo "<br/>";
				echo '<form action="index.php?op=12" method = "POST">';
				echo 'B�squeda Compra por Id cliente:';
				echo "<br/>";
				echo 'Id cliente: ';
				echo '<input type="text" name = "idcliente" id ="idcliente">';
				echo' <input type ="submit" value="B�squeda" name = "busquedaidcliente" id = "busquedaidcliente">';	
				echo '</form>';
				echo "<br/>";
				echo "Listado Completo de Compras:";
				echo "<br/>";
				echo "<br/>";
				echo '<table id="tablacompra">';
				echo "<tr>";
				echo "<th>Id Compra</th>";
				echo "<th>Id Cliente</th>";
				echo "<th>Nombre Cliente</th>";
				echo "<th>Fecha</th>";
				echo "<th>Pagado</th>";
				echo "<th>Enviado</th>";
				echo "<th>Productos</th>";
				echo "<th>Precio</th>";
				echo "</tr>";
				for ($i=1; $i<$cuantos+1; $i++)
				{
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=12" method = "POST">';
					echo "<tr>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_compra"){
							echo '<input type="hidden" name = "idcomp" id ="idcomp" value="'.$valor.'">';
							echo "<td>";
							echo "$valor";
							echo "</td>";
						}
						if ($campo == "id_cliente"){
							echo "<td>";
							echo "$valor";
							echo "</td>";
							echo "<td>";
								$consulta2 = 'SELECT * FROM Cliente WHERE id_cliente= '.$valor.''; 
								$cursor2= $db->query($consulta2);
								$cuantos2 = $cursor2->num_rows;
								$cade = "";
								for ($j=1; $j<$cuantos2+1; $j++)
								{
									$fila2= $cursor2 -> FETCH_ASSOC();
									foreach ($fila2 as $campo2 => $valor2)
											{
												if ($campo2 == "nombre"){
													$cade .= $valor2;
												}
												if ($campo2 == "apellidos"){
													$cade .= " " . $valor2;
												}
											}
								};
								echo "$cade";
							echo "</td>";
						}
						if ($campo == "fecha"){
						$fech = cambiaf_a_normal($valor);
							echo "<td>";
							echo "$fech";
							echo "</td>";
						}
						if ($campo == "pagado"){
							if ($valor == 0){
								$valor1 = "no";
								$valor2 = "si";
							}else{
								$valor2 = "no";
								$valor1 = "si";
							}
							echo "<td>";
							echo '<select name="pagad">';
									echo '<option selected>'.$valor1.'';
									echo '<option >'.$valor2.'';
							echo '</select>';
							echo "</td>";

						}
						if ($campo == "enviado"){
									if ($valor == 0){
								$valor1 = "no";
								$valor2 = "si";
							}else{
								$valor2 = "no";
								$valor1 = "si";
							}
							echo "<td>";
							echo '<select name="enviad">';
									echo '<option selected>'.$valor1.'';
									echo '<option >'.$valor2.'';
							echo '</select>';
							echo "</td>";

						}
						if ($campo == "productos"){
							echo "<td>";
							echo "$valor";
							echo "</td>";
						}
						if ($campo == "precio"){
							echo "<td>";
							echo "$valor";
							echo "</td>";
						}
					}
					echo "<td>";
					echo '<input type ="submit" value="Cambiar" name = "modcompra" id = "modcompra">';
					echo "</td>";
					echo "</tr>";	
					echo '</form>';
				};
				echo "</table>";
				$db->CLOSE();
			}
?>
