<?php
$bdd = new PDO('mysql:host=localhost;dbname=db_camagru', 'root', '123456');

if(isset($_POST['form_inscri'])) 
{
   $pseudo = htmlspecialchars($_POST['pseudo']);
   $mail = htmlspecialchars($_POST['mail']);
   $mail2 = htmlspecialchars($_POST['mail2']);
   $passw = sha1($_POST['passw']);
   $passw2 = sha1($_POST['passw2']);
   if(!empty($_POST['pseudo']) AND !empty($_POST['mail']) AND !empty($_POST['mail2']) AND !empty($_POST['passw']) AND !empty($_POST['passw2'])) {
      $pseudolength = strlen($pseudo);
      if($pseudolength <= 255) {
         $reqpseudo = $bdd->prepare("SELECT * FROM users WHERE pseudo = ?");
         $reqpseudo->execute(array($pseudo));
         $pseudoexist = $reqpseudo->rowCount();
         if($pseudoexist == 0) {
            if($mail == $mail2) {
               if(filter_var($mail, FILTER_VALIDATE_EMAIL)) {
                  $reqmail = $bdd->prepare("SELECT * FROM users WHERE mail = ?");
                  $reqmail->execute(array($mail));
                  $mailexist = $reqmail->rowCount();
                  if($mailexist == 0) {
                     if($passw == $passw2) {
                        $insertmbr = $bdd->prepare("INSERT INTO users(mail, pseudo, mdp) VALUES(?, ?, ?)");
                        $insertmbr->execute(array($mail, $pseudo, $passw));
                        $erreur = "Votre compte a bien été créé ! <a href=\"connexion.php\">Me connecter</a>";
                     } else {
                        $erreur = "Vos mots de passes ne correspondent pas !";
                     }
                  } else {
                     $erreur = "Adresse mail déjà utilisée !";
                  }
               } else {
                  $erreur = "Votre adresse mail n'est pas valide !";
               }
            } else {
               $erreur = "Vos adresses mail ne correspondent pas !";
            }
         } else {
            $erreur = "Votre pseudo est déjà utilisé";
         } 
      } else{
            $erreur = "Votre pseudo ne doit pas dépasser 255 caractères !";
         } 
   } else {
         $erreur = "Tous les champs doivent être complétés !";
   }
}
?>
<html>
<head>
   <title></title>

</head>
<body>


<div class="inscription" >

   <h3>Inscription</h3>
   <br><br>
   <form method="POST" action="">
      <table>
         <tr>
            <td><label for="pseudo">Pseudo :</label></td>
            <td><input type="text" id="pseudo" placeholder="Ton Pseudo" name="pseudo"></td>        
         </tr>
         <tr>
            <td><label for="mail">Mail :</label></td>
            <td><input type="email" id="mail" placeholder="Ton Mail" name="mail"></td>       
         </tr>
         <tr>
            <td><label for="mail2">Confirmer votre Mail :</label></td>
            <td><input type="email" id="mail2" placeholder="Confirme ton Mail" name="mail2"></td>        
         </tr>
         <tr>
            <td><label for="passw">Password :</label></td>
            <td><input type="Password" id="passw" placeholder="Ton Password" name="passw"></td>       
         </tr>
         <tr>
            <td><label for="passw2">Confirmer votre Password :</label></td>
            <td><input type="Password" id="passw2" placeholder="Confirme ton Password" name="passw2"></td>        
         </tr>
         <tr>
            <td></td>
            <td><input type="submit" name="form_inscri" value="Je m'inscris"></td>
         </tr>
      </table> 
   </form>
<?php
   if(isset($erreur))
   {
      echo $erreur;
   }
?>
</div>
</body>
</html>

