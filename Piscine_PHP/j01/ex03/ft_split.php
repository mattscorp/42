#!/usr/bin/php
<?php
function ft_split($string){

$my_tab = explode(" ", $string);
$my_tab = array_filter($my_tab, strlen);
sort($my_tab);
return $my_tab;
}
?>