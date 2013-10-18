<?php
/*
http://myapp-raulsanchez.rhcloud.com/

Copyright (C) 2013  Raúl Sánchez Fuentes

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
?>
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
