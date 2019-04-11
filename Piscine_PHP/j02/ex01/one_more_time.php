#!/usr/bin/php
<?php
date_default_timezone_set("Europe/Paris");
if ($argc < 2)
	exit;
$full_date = explode(" ", $argv[1]);
$day_let = $full_date[0];
$full_date[0][0] = strtolower($full_date[0][0]);
$full_date[2][0] = strtolower($full_date[2][0]);
$full_date[2] = str_replace("é", "e", $full_date[2]);
$full_date[2] = str_replace("û", "u", $full_date[2]);
$day_num = $full_date[1];
$month = $full_date[2];
$year = $full_date[3];
$time = $full_date[4];
$time_sep = explode(":", $time);
$hour = $time_sep[0];
$min = $time_sep[1];
$sec = $time_sep[2];
$month_tab = array("janvier" => 1, "fevrier" => 2, "mars" => 3, "avril" => 4, "mai" => 5, "juin" => 6, "juillet" => 7, "aout" => 8, "septembre" => 9, "octobre" => 10, "novembre" => 11, "decembre" => 12);
$verif_month = array("janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre");
$verif_day = array("lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche");

//print_r($verif_day);

if (array_search($full_date[0], $verif_day) && array_search($full_date[2], $verif_month) && $time_sep[0] <= 24 && $time_sep[1] < 60 && $time_sep[2] < 60)
{
	$full_date[2] = $month_tab[$full_date[2]];

//print_r($full_date);

$ret = mktime($time_sep[0], $time_sep[1], $time_sep[2], $full_date[2], $full_date[1], $full_date[3]);
echo "$ret\n";
}
else
echo "Wrong Format\n";
?>