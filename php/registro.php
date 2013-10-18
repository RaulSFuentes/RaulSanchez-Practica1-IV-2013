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
<body id="bodyregistro">
<div id="centroregistro">
<?php
			include_once("./include/funciones.inc");
			$db = new mysqli(
$_ENV['OPENSHIFT_MYSQL_DB_HOST'],
$_ENV['OPENSHIFT_MYSQL_DB_USERNAME'],
$_ENV['OPENSHIFT_MYSQL_DB_PASSWORD'],
$_ENV['OPENSHIFT_APP_NAME'], // By default, app name == db name
$_ENV['OPENSHIFT_MYSQL_DB_PORT'],
$_ENV['OPENSHIFT_MYSQL_DB_SOCKET']
);
			if (isset ($_POST['Insertar'])){
				$fallo = false;
				$nombre = $_POST['nombre'];
				$ape= $_POST['ape'];
				$fe = $_POST['fecha'];
				$fecha = $fe;
				$dire = $_POST['dire'];
				$loca = $_POST['loca'];
				$prov = $_POST['prov'];
				$pais = $_POST['pais'];
				$cp = $_POST['cp'];
				$dni = $_POST['dni'];
				$tel = $_POST['tel'];
				$email = $_POST['email'];
				$contra = $_POST['contracli'];
				if (($contra == "" || $nombre == "" || $ape == "" || $fecha == "" || $dire == "" || $loca == "" || $prov == "" || $pais == "" || $cp == "" || $dni == "" || $tel == "" || $email == "") && $fallo == false){
					$fallo = "Todos los campos son obligatorios";
				}
				if (!validarcp($cp) && $fallo == false){
					$fallo = "Introduzca un C�digo Postal correcto";
				}
				if (comprobar_dni($dni) == 0 && $fallo == false){
					$fallo = "Introduzca un DNI correcto";
				}
				if (!validarTelefono($tel) && $fallo == false){
					$fallo = "Introduzca un n�mero de tel�fono correcto";
				}
				if (comprobar_email($email) == 0 && $fallo == false){
					$fallo = "Introduzca un email correcto";
				}
				
				$consulta2 = 'SELECT * FROM Cliente WHERE dni = "'.$dni.'"'; 
				$cursor2= $db->query($consulta2);
				$cuantos2 = $cursor2->num_rows;
				if ($cuantos2 > 0){
					$fallo = "Ya existe un Cliente con ese DNI, si persiste el error contacte con el administrador.";
				}
				
				if($fallo == false){

					$fecha = null;
					$fecha = cambiafamysql($fe);
				
					$consulta = "INSERT INTO Cliente (nombre,apellidos,fecha_nacimiento, direccion, localidad, provincia, pais, cp, dni, telefono, email, contrase�a) VALUES('".$nombre."', '".$ape."', '".$fecha."', '".$dire."', '".$loca."', '".$prov."', '".$pais."', '".$cp."', '".$dni."', '".$tel."', '".$email."', '".$contra."')";
					$cursor = $db->query($consulta);
					$cuerpo .= "Un cordial saludo $nombre \n\n";
					$cuerpo .= 'Lo primero es darle la bienvenida como cliente de "Pa Chuparse los Dedos", y agradecerle su confianza en nosotros.' . "\n\n";
					$cuerpo .= "Por medidas de seguridad, y para asegurar que los datos proporcionados son correctos, su contrase�a elegida ser� sustituida por su n�mero de DNI. Por ello sus datos de acceso son los siguientes:\n\n"; 
					$cuerpo .= "Datos De Cliente:\n"; 
					$cuerpo .= "Usuario: " . $nombre . "\n\n"; 
					$cuerpo .= "Contrase�a: " . $dni . "\n\n"; 
					$cuerpo .= "Con estos datos ya podra acceder a la web identificandose y podr� realizar sus compras.\n\n"; 
					$cuerpo .= "Un Saludo, el Administrador.\n\n"; 

					mail($email,"Pa chuparse los dedos",$cuerpo); 
					echo "<h3>Bienvenido/a $nombre.</h3>";
					echo "<br/>";
					echo "Se le ha enviado un correo a su email con los datos de acceso a la web, es necesario que lea ese correo para en ingreso en la web.";
					echo "<br/>";
					echo "Gracias: El Administrador.";
					echo "<br/>";
					$db->CLOSE();
				}else{
					echo "Revise:  $fallo"; 
					echo "<span><h3>Nuevo Cliente</h3></span>";
				echo '<form action="registro.php?op=1" method = "POST">
				Nombre: <input type="text" name = "nombre" id ="nombre" value="'.$nombre.'">
				<br/>
				<br/>
				Apellidos: <input type="text" name = "ape" id ="ape" value="'.$ape.'">
				<br/>
				<br/>
				Fecha de Nacimiento: <input type="text" name = "fecha" id ="fecha" value="'.$fecha.'">
				<br/>
				<br/>
				Direcci�n: <input type="text" name = "dire" id ="dire" value="'.$dire.'">
				<br/>
				<br/>
				Localidad: <input type="text" name = "loca" id ="loca" value="'.$loca.'">
				<br/>
				<br/>
				Provincia: <input type="text" name = "prov" id ="prov" value="'.$prov.'">
				<br/>
				<br/>
				Pa�s: <input type="text" name = "pais" id ="pais" value="'.$pais.'">
				<br/>
				<br/>
				C�digo Postal: <input type="text" name = "cp" id ="cp" value="'.$cp.'">
				<br/>
				<br/>
				DNI: <input type="text" name = "dni" id ="dni" value="'.$dni.'">
				<br/>
				<br/>
				Tel�fono: <input type="text" name = "tel" id ="tel" value="'.$tel.'">
				<br/>
				<br/>
				Email: <input type="text" name = "email" id ="email" value="'.$email.'">
				<br/>
				<br/>
				Contrase�a: <input type="text" name = "contracli" id ="contracli" value="'.$contracli.'">
				<br/>
				<br/>
				<input type ="submit" value="Insertar" name = "Insertar" id = "Insertar">
				</form>';
				}
			}else{
				echo "<span><h3>Nuevo Cliente</h3></span>";
				echo '<form action="registro.php?op=1" method = "POST">
				Nombre: <input type="text" name = "nombre" id ="nombre">
				<br/>
				<br/>
				Apellidos: <input type="text" name = "ape" id ="ape" value="'.$ape.'">
				<br/>
				<br/>
				Fecha de Nacimiento: <input type="text" name = "fecha" id ="fecha" value="01/01/0001">
				<br/>
				<br/>
				Direcci�n: <input type="text" name = "dire" id ="dire">
				<br/>
				<br/>
				Localidad: <input type="text" name = "loca" id ="loca">
				<br/>
				<br/>
				Provincia: <input type="text" name = "prov" id ="prov">
				<br/>
				<br/>
				Pa�s: <input type="text" name = "pais" id ="pais">
				<br/>
				<br/>
				C�digo Postal: <input type="text" name = "cp" id ="cp">
				<br/>
				<br/>
				DNI: <input type="text" name = "dni" id ="dni">
				<br/>
				<br/>
				Tel�fono: <input type="text" name = "tel" id ="tel">
				<br/>
				<br/>
				Email: <input type="text" name = "email" id ="email">
				<br/>
				<br/>
				Contrase�a: <input type="text" name = "contracli" id ="contracli">
				<br/>
				<br/>
				<input type ="submit" value="Insertar" name = "Insertar">
				</form>';
			}
			
?>
</div>
</body>
</html>
