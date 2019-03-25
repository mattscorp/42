#!/usr/bin/php
<?php
function ft_split($string){

$my_tab = explode(" ", $string);
sort($my_tab);
return $my_tab;
}
?>