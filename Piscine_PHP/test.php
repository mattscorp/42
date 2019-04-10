<?php
$user['login'] = '1'; // change de valeur a chaques essais
$user['passwd'] = '2'; // change de valeur a chaques essais
echo "tableau de lutilisateurs\n";
print_r($user);
$tab = unserialize(file_get_contents('ess'));
echo "tableau de recuperer du fichier\n";
print_r($tab);
$tab[count($tab)] = $user;
echo "tableau de recuperer du fichier avec lutilisateur en plus\n";
print_r($tab);
$tab = serialize($tab);
file_put_contents('ess', $tab, FILE_USE_INCLUDE_PATH);
?>