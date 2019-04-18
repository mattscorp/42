<?php

/*********************************************************************/
/*********************************************************************/
/****                                                             ****/
/****              Connection and request functions               ****/
/****                                                             ****/
/*********************************************************************/
/*********************************************************************/

function connect_mysql_serveur()
{
    $url = '127.0.0.1';
    $user = 'root';
    $pass = '123456';

    $con = mysqli_connect($url, $user, $pass);
    if (!$con) {
        die(' Connexion serveur impossible : ' . mysqli_error($con));
    }

    return ($con);
}

function connect_db()
{
    $url = '127.0.0.1';
    $user = 'root';
    $pass = '123456';
    $dbname = "camagru";

    $con = mysqli_connect($url, $user, $pass, $dbname);
    if (!$con) {
        die(' Connexion db impossible : ' . mysqli_error($con));
    }
    return ($con);
}

function test_input($data)
{
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}

?>