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
			if (isset ($_POST['mod'])){
				$esta = true;
				$fallo = false;
				$pro = $_POST['idpro'];
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
				if (($nombre == "" || $precio == "") && $fallo == false){
					$fallo = "Todos los campos son obligatorios";
				}
				if (!is_numeric($precio) && $fallo == false){
					$fallo = "Introduzca un Precio correcto";
				}
				if($fallo == false){
						include_once('clasesubirarchivo.inc');
						$arch = new subearchivo();
						$arch->nombre=$nombre_archivo = $_FILES [ 'ima' ] [ 'name' ];
						$arch->tipo=$tipo_archivo = $_FILES [ 'ima' ] [ 'type' ];
						$arch->tamanho=$tamano_archivo = $_FILES [ 'ima'] [ 'size' ];
						$arch->nombretmp=$nombre_temp = $_FILES [ 'ima' ] [ 'tmp_name' ];
					if ($arch->nombre == ""){
						$consulta = 'UPDATE Producto SET nombre_p = "'.$nombre.'", precio = "'.$precio.'", id_tipo = "'.$tip.'", descripcion = "'.$desc.'" WHERE id_producto = "'.$pro.'"';
					}
					else{
						$arch->sube();					
						$consulta = 'UPDATE Producto SET nombre_p = "'.$nombre.'", precio = "'.$precio.'", id_tipo = "'.$tip.'", imagen= "'.$arch->nombre.'", descripcion = "'.$desc.'" WHERE id_producto = "'.$pro.'"';
					}
					$cursor = $db->query($consulta);
					echo "<h3>Modificado $nombre.</h3>";
					echo "<br/>";
					$db->CLOSE();
				}else{
					echo "Revise:  $fallo"; 
					echo "<span><h3>Datos Producto</h3></span>";
				echo '<form action="index.php?op=5" method = "POST" enctype="multipart/form-data">
				Nombre: <input type="text" name = "nombre" id ="nombre" value="'.$nombre.'">
				<br/>
				<br/>
				Precio: <input type="text" name = "precio" id ="precio" value="'.$precio.'">
				<br/>
				<br/>
				Contenido: <br/>
				<textarea name="descrip" id="descrip"></textarea> 
				<br/>
				<br/>
				<br/>';
								if ($tip == 1){
									echo '
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
										';
								}
								if ($tip == 2){
								echo '
										<br/>
										<br/>
										<fieldset style="width:100px">
										<legend>Tipo</legend>
										<input type="radio" name = "tipo" value="Aceites"> Aceites 
										<br/>
										<input type ="radio" name = "tipo" value="Jamones" checked="checked"> Jamones
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
										';
								}
								if ($tip == 3){
								echo '
										<br/>
										<br/>
										<fieldset style="width:100px">
										<legend>Tipo</legend>
										<input type="radio" name = "tipo" value="Aceites"> Aceites 
										<br/>
										<input type ="radio" name = "tipo" value="Jamones"> Jamones
										<br/>
										<input type ="radio" name = "tipo" value="Vinos" checked="checked"> Vinos
										<br/>
										<input type ="radio" name = "tipo" value="Quesos"> Quesos
										<br/>
										<input type ="radio" name = "tipo" value="Embutidos"> Embutidos	
										<br/>
										<input type ="radio" name = "tipo" value="Varios"> Varios
										</fieldset>
										<br/>
										<br/>
										';
								}
								if ($tip == 4){
								echo '
										<br/>
										<br/>
										<fieldset style="width:100px">
										<legend>Tipo</legend>
										<input type="radio" name = "tipo" value="Aceites"> Aceites 
										<br/>
										<input type ="radio" name = "tipo" value="Jamones"> Jamones
										<br/>
										<input type ="radio" name = "tipo" value="Vinos"> Vinos
										<br/>
										<input type ="radio" name = "tipo" value="Quesos" checked="checked"> Quesos
										<br/>
										<input type ="radio" name = "tipo" value="Embutidos"> Embutidos	
										<br/>
										<input type ="radio" name = "tipo" value="Varios"> Varios
										</fieldset>
										<br/>
										<br/>
										';
								}
								if ($tip == 5){
								echo '
										<br/>
										<br/>
										<fieldset style="width:100px">
										<legend>Tipo</legend>
										<input type="radio" name = "tipo" value="Aceites"> Aceites 
										<br/>
										<input type ="radio" name = "tipo" value="Jamones"> Jamones
										<br/>
										<input type ="radio" name = "tipo" value="Vinos"> Vinos
										<br/>
										<input type ="radio" name = "tipo" value="Quesos"> Quesos
										<br/>
										<input type ="radio" name = "tipo" value="Embutidos" checked="checked"> Embutidos	
										<br/>
										<input type ="radio" name = "tipo" value="Varios"> Varios
										</fieldset>
										<br/>
										<br/>
										';
								}
								if ($tip == 6){
								echo '
										<br/>
										<br/>
										<fieldset style="width:100px">
										<legend>Tipo</legend>
										<input type="radio" name = "tipo" value="Aceites"> Aceites 
										<br/>
										<input type ="radio" name = "tipo" value="Jamones"> Jamones
										<br/>
										<input type ="radio" name = "tipo" value="Vinos"> Vinos
										<br/>
										<input type ="radio" name = "tipo" value="Quesos"> Quesos
										<br/>
										<input type ="radio" name = "tipo" value="Embutidos"> Embutidos	
										<br/>
										<input type ="radio" name = "tipo" value="Varios" checked="checked"> Varios
										</fieldset>
										<br/>
										<br/>
										';
								}
				echo "*Seleccione una imagen solo en caso de querer modificarla.";
				echo "<br/>";
				echo 'Imagen: <input type ="file" name="ima" id="ima" value="'.$ima.'">
				<br/>
				<br/>';
				echo '
				<input type ="submit" value="Modificar Datos" name = "mod" id = "mod">
				</form>';
				}
			}else
			if (isset ($_POST['modificaproducto'])){ 
				$esta = true;
				$pro = $_POST['idpro'];
				$consulta = 'SELECT * FROM Producto WHERE id_producto = "'.$pro.'"';
				$cursor = $db->query($consulta);
				$cuantos = $cursor->num_rows;
				echo "<span><h3>Datos Producto</h3></span>";
				for ($i=1; $i<$cuantos+1; $i++)
				{
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=5" method = "POST" enctype="multipart/form-data">';
					foreach ($fila as $campo => $valor)
					{
							echo '<input type="hidden" name = "idpro" id ="idpro" value="'.$pro.'">';
							if ($campo == "nombre_p"){							
							echo 'Nombre: <input type="text" name = "nombre" id ="nombre" value="'.$valor.'">
							<br/>
							<br/>';
							};
							if ($campo == "precio"){
							echo 'Precio: <input type="text" name = "precio" id ="precio" value="'.$valor.'"><br/>
							<br/>';
							};
							if ($campo == "descripcion"){
								echo'Contenido: <br/>
								<textarea name="descrip" id="descrip">'.$valor.'</textarea> 
								<br/>
								<br/>
								<br/>';
							}
							if ($campo == "id_tipo")
							{
								$tip = $valor;
								if ($tip == 1){
										echo '
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
											';
									}
									if ($tip == 2){
									echo '
											<br/>
											<br/>
											<fieldset style="width:100px">
											<legend>Tipo</legend>
											<input type="radio" name = "tipo" value="Aceites"> Aceites 
											<br/>
											<input type ="radio" name = "tipo" value="Jamones" checked="checked"> Jamones
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
											';
									}
									if ($tip == 3){
									echo '
											<br/>
											<br/>
											<fieldset style="width:100px">
											<legend>Tipo</legend>
											<input type="radio" name = "tipo" value="Aceites"> Aceites 
											<br/>
											<input type ="radio" name = "tipo" value="Jamones"> Jamones
											<br/>
											<input type ="radio" name = "tipo" value="Vinos" checked="checked"> Vinos
											<br/>
											<input type ="radio" name = "tipo" value="Quesos"> Quesos
											<br/>
											<input type ="radio" name = "tipo" value="Embutidos"> Embutidos	
											<br/>
											<input type ="radio" name = "tipo" value="Varios"> Varios
											</fieldset>
											<br/>
											<br/>
											';
									}
									if ($tip == 4){
									echo '
											<br/>
											<br/>
											<fieldset style="width:100px">
											<legend>Tipo</legend>
											<input type="radio" name = "tipo" value="Aceites"> Aceites 
											<br/>
											<input type ="radio" name = "tipo" value="Jamones"> Jamones
											<br/>
											<input type ="radio" name = "tipo" value="Vinos"> Vinos
											<br/>
											<input type ="radio" name = "tipo" value="Quesos" checked="checked"> Quesos
											<br/>
											<input type ="radio" name = "tipo" value="Embutidos"> Embutidos	
											<br/>
											<input type ="radio" name = "tipo" value="Varios"> Varios
											</fieldset>
											<br/>
											<br/>
											';
									}
									if ($tip == 5){
									echo '
											<br/>
											<br/>
											<fieldset style="width:100px">
											<legend>Tipo</legend>
											<input type="radio" name = "tipo" value="Aceites"> Aceites 
											<br/>
											<input type ="radio" name = "tipo" value="Jamones"> Jamones
											<br/>
											<input type ="radio" name = "tipo" value="Vinos"> Vinos
											<br/>
											<input type ="radio" name = "tipo" value="Quesos"> Quesos
											<br/>
											<input type ="radio" name = "tipo" value="Embutidos" checked="checked"> Embutidos	
											<br/>
											<input type ="radio" name = "tipo" value="Varios"> Varios
											</fieldset>
											<br/>
											<br/>
											';
									}
									if ($tip == 6){
									echo '
											<br/>
											<br/>
											<fieldset style="width:100px">
											<legend>Tipo</legend>
											<input type="radio" name = "tipo" value="Aceites"> Aceites 
											<br/>
											<input type ="radio" name = "tipo" value="Jamones"> Jamones
											<br/>
											<input type ="radio" name = "tipo" value="Vinos"> Vinos
											<br/>
											<input type ="radio" name = "tipo" value="Quesos"> Quesos
											<br/>
											<input type ="radio" name = "tipo" value="Embutidos"> Embutidos	
											<br/>
											<input type ="radio" name = "tipo" value="Varios" checked="checked"> Varios
											</fieldset>
											<br/>
											<br/>
											';
									}
								}
								if ($campo == "imagen"){
										echo 'Imagen: <input type ="file" name="ima" id="ima" value="'.$value.'">
										<br/>
										<br/>';
								};
							};
					}
					echo '<input type ="submit" value="Modificar Datos" name = "mod" id = "mod">';
					echo '</form>';
				}else if (isset ($_POST ['busquedanombre'])){ // Sacamos los resultados de la b\FAsqueda por nombre
				$nombre = $_POST['nombre'];
				$consulta = 'SELECT * FROM Producto WHERE nombre_p = "'.$nombre.'" ORDER BY id_tipo ASC'; // Hacemos una consulta sobre la tabla producto
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				
				for ($i=1; $i<$cuantos+1; $i++)
				{
					echo "Producto con nombre : $nombre";
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=5" method = "POST" enctype="multipart/form-data">';
					echo "<ul>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_producto"){
							echo '<input type="hidden" name = "idpro" id ="idpro" value="'.$valor.'">'; 
						}
						if ($campo == "nombre_p"){
						echo "<li>";
						echo'<input type ="submit" value="Modificar" name = "modificaproducto" id = "modificaproducto">';
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
			else if (isset ($_POST ['busquedatipo'])){ // Sacamos los resultados de la b\FAsqueda por tipo
				$tipo = $_POST['tipo'];
				if ($tipo == "aceite" || $tipo == "Aceite"){
					$tt = 1;
				}else if ($tipo == "jamon" || $tipo == "Jamon"){
					$tt = 2;
				}else if ($tipo == "vino" || $tipo == "Vino"){
					$tt = 3;
				}else if ($tipo == "queso" || $tipo == "Queso"){
					$tt = 4;
				}else if ($tipo == "embutido" || $tipo == "Embutido"){
					$tt = 5;
				}else if ($tipo == "varios" || $tipo == "Varios"){
					$tt = 6;
				}
				$consulta = 'SELECT * FROM Producto WHERE id_tipo="'.$tt.'" ORDER BY id_tipo ASC'; // Hacemos una consulta sobre la tabla Cliente
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
					echo "Productos del tipo : $tipo";
				for ($i=1; $i<$cuantos+1; $i++)
				{
					$fila= $cursor -> FETCH_ASSOC();
					echo '<form action="index.php?op=5" method = "POST" enctype="multipart/form-data">';
					echo "<ul>";
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_producto"){
							echo '<input type="hidden" name = "idpro" id ="idpro" value="'.$valor.'">'; 
						}
						if ($campo == "nombre_p"){
						echo "<li>";
						echo'<input type ="submit" value="Modificar" name = "modificaproducto" id = "modificaproducto">';
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
			if ($esta == false){  // Listado de todo los Productos y opciones de b\FAsqueda
				$consulta = 'SELECT * FROM Producto ORDER BY id_tipo ASC'; // Hacemos una consulta sobre la tabla Producto
				$cursor= $db->query($consulta);
				$cuantos = $cursor->num_rows;
				$cont = 0;
				echo '<form action="index.php?op=5" method = "POST" enctype="multipart/form-data">';
				echo 'B\FAsqueda producto por nombre';
				echo "<br/>";
				echo 'Nombre: ';
				echo '<input type="text" name = "nombre" id ="nombre">';
				echo' <input type ="submit" value="B\FAsqueda" name = "busquedanombre" id = "busquedanombre">';	
				echo '</form>';
				echo '<form action="index.php?op=5" method = "POST">';
				echo 'B\FAsqueda producto por tipo';
				echo "<br/>";
				echo 'Tipo: ';
				echo '<input type="text" name = "tipo" id ="tipo">';
				echo' <input type ="submit" value="B\FAsqueda" name = "busquedatipo" id = "busquedatipo">';	
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
					echo '<form action="index.php?op=5" method = "POST" enctype="multipart/form-data">';
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "id_producto"){
							echo '<input type="hidden" name = "idpro" id ="idpro" value="'.$valor.'">';
						}
						if ($campo == "nombre_p"){
						echo "<li>";
						echo'<input type ="submit" value="Modificar" name = "modificaproducto" id = "modificaproducto">';
						echo " --> ";
						echo "$valor";
						}
						if ($campo == "tipo"){
						echo " , tipo: $valor";						
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
