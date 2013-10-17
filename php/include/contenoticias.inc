<?php
$db = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
			$consulta = 'SELECT * FROM Noticia ORDER BY fecha DESC';
			$cursor= $db->query($consulta);
			$cuantos = $cursor->num_rows;
			for ($i=1; $i<6; $i++)
				{
					$cont++;
					$fila= $cursor -> FETCH_ASSOC();
					if ($cuantos >= $i){
						echo '<form action="noticia.php" method = "GET">';
						foreach ($fila as $campo => $valor)
						{
							if ($campo == "id_noticia"){
								$idnot = $valor;
							}
							if ($campo == "titulo"){
								echo "<b>$valor</b>";
								echo "<br/>";
								echo "<br/>";
							}
							if ($campo == "contenido"){
								$conte = $valor;
								$conten= substr($conte,0,250);
								echo "  $conten";
								echo "<br/>";
								echo '<b><a href="noticias.php?id='.$idnot.'" id="ennoticia" target=_blank>Leer más--></a></b>';
								echo "<br/>";
								echo "<br/>";
							}
							if ($campo == "fecha"){
								$fech = cambiaf_a_normal($valor);
								echo "Fecha: $fech";						
							}
						}
						echo "</form>";
						echo "<br/>";
						echo "<p>----------------------------------------</p>";
					}
					
			}
		?>
