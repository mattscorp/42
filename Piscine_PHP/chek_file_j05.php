<?php

echo "\033[35m ---------------------------------------------------------------------------------------\033[0m\n";
echo "\033[35m ---------------------------------------------------------------------------------------\033[0m\n";
echo "\033[35m|                                CREATED by ==> AGASPARO <==                          |\033[0m\n";
echo "\033[35m ---------------------------------------------------------------------------------------\033[0m\n";
echo "\033[35m|                           Testors: lpelissi ceaudouy mascorpi                        |\033[0m\n";
echo "\033[35m----------------------------------------nom_fichier------------------------------------\033[0m\n";


$i = 0;

while ($i < 22) {
	if ($i < 10)
		$dos = "j05/ex0".$i;
	else
		$dos = "j05/ex".$i;
	if ($dos) {

		$commande = "ls -a ".$dos;
		if ($i < 10)
			$req = ".\n..\nex0".$i.".sql";
		else
			$req = ".\n..\nex".$i.".sql";
		$rep = shell_exec($commande);
		if (trim($rep) == trim($req)) {
			echo $dos." : \033[32m[Tous les fichiers sont en regles]\033[0m\n";
		} else {
			echo $dos." : \033[31m[Fichier non valide trouve]\033[0m\n";
		}
	} else {
		echo $dos." : \033[31m[Dossier non trouve]\033[0m\n";
	}
	$i++;
}

echo "\033[35m----------------------------------------nom_racine------------------------------------\033[0m\n";

$dir = "j05";
$i = 0;
if (is_dir($dir)){
  if ($dh = opendir($dir)){
    while (($file = readdir($dh)) !== false){
    	if ($file[0] != '.') {
    		if ($file[0] == "e" || $file[1] == "x") {
    			echo $file." : \033[32m[Dossier trouve]\033[0m\n";
    		} else {
    			echo "\033[31m[Le dossier / fichier ".$file." n'est pas valide]\033[0m\n";
    		}
    	}
    }
    closedir($dh);
  }
}

?>