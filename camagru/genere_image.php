<?php
include("coco.php");

$result = $bdd->query("SELECT * FROM img WHERE id = {$_GET['id']}");
    echo $_GET['id'];
    header("Content-type: image/jpg"); 
    echo $imgData['img_data']; 

?>