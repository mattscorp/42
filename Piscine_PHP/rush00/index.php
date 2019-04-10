<?php

session_start();

$user='root';
$password_def='root';

if(isset($_POST['submit'])){
    $username = $_POST['username'];
    $password = $_POST['password'];
    if($username&&$password){
        if($username==$user&&$password==$password_def){
            
            $_SESSION['username']=$username;
            header('Location: admin.php');
        }
        else
            echo "Identifiants éronnés.";
    }
    else{
        echo "Veuillez replir tous les champs!";
    }
}

?>

<h1>Administration - Connexion</h1>
<form action="" method="POST">
<h3>Pseudo :</h3><input type="text" name="username"/><br/><br/>
<h3>Mot-de-passe :</h3><input type="password" name="password"/><br/><br/>
<input type="submit" name="submit"/><br/><br/>
</form>