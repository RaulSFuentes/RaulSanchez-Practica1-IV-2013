<html>
<head>
<link href="stylo.css" rel="stylesheet" type="text/css" />
</head>
<body id="noticiasbody">
<div id ="centralnoticia">
<?php
			$idn = $_GET['id'];
			include_once("./include/funciones.inc");
			$db = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
			$consulta = 'SELECT * FROM Noticia WHERE id_noticia = '.$idn.'';
			$cursor= $db->query($consulta);
			$cuantos = $cursor->num_rows;
			for ($i=1; $i<2; $i++)
				{
					$cont++;
					$fila= $cursor -> FETCH_ASSOC();
					foreach ($fila as $campo => $valor)
					{
						if ($campo == "titulo"){
							echo'<div id="titulonoticia">
								<h1>'.$valor.'</h1>
							</div>
								';
						}
						if ($campo == "contenido"){
							echo'<div id="contenidonoticia">
								<p>'.$valor.'</p>
							</div>
								';
						}
						if ($campo == "fecha"){
							$fech = cambiaf_a_normal($valor);
							echo'<div id="fechanoticia">
								<p>Fecha: '.$fech.'</p>
							</div>
								';
						}
					}
			}
		?>
</div>
</body>
</html>
