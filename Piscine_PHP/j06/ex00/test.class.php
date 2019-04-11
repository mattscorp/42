<?php
class Exemple {

	function __construct(){
		print('Constrcutore'.PHP_EOL);
		return;
	}

	function __destruct(){
		print('destrcutore'.PHP_EOL);
		return;
	}
}
$instance = new Exemple();
?>