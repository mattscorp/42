<?php
	//print_r($_SERVER);
	if (!isset($_SERVER['PHP_AUTH_USER'])) {
   header('WWW-Authenticate: Basic realm="Espace membres"');
   header('HTTP/1.0 401 Unauthorized');
	}
	if ($_SERVER[PHP_AUTH_USER] === "zaz" AND $_SERVER[PHP_AUTH_PW] === "jaimelespetitsponeys")
	{
		$image = file_get_contents("../img/42.png");
		$image64 = base64_encode($image);
		echo "<html><body>\nBonjour Zaz<br />\n<img src='data:image/png;base64,$image64'>\n</body></html>";
	}
    else
    {
    	echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n";
    }
?>
