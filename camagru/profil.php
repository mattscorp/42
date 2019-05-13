<?php
session_start();
$bdd = new PDO('mysql:host=localhost;dbname=db_camagru', 'root', '123456');

if(isset($_GET['id']) AND $_GET['id'] > 0)
{
   $getid = intval($_GET['id']);
   $requser = $bdd->prepare('SELECT * FROM users WHERE id = ?');
   $requser->execute(array($getid));
   $userinfo = $requser->fetch();
?>
<html>
<head>
   <title>Mon Profil</title>

</head>
<body>


<div class="inscription" >
   <table>
<tr>
   <td><h3>Profil de <?php echo $userinfo['pseudo']; ?></h3></td>
 </tr>
 <tr>
   <td>Pseudo =  <?php echo $userinfo['pseudo']; ?></td>
 </tr>
 <tr>
   <td>Mail =  <?php echo $userinfo['mail']; ?></td>
 </tr>
<?php
if(isset($_SESSION['id']) AND $userinfo['id'] == $_SESSION['id'])
{
?>
<tr>
   <td><a href="edition_profil.php">EDITER MON PROFIL</a></td>
 </tr>
<tr>
   <td><a href="deconnexion.php">SE DECONNECTER</a></td>
 </tr>
</table>
<?php
}
?>
</div>

<div>
      <video id="video" width="640" height="480" autoplay></video>
      <button id="snap">Snap Photo</button>
      <canvas id="canvas" width="640" height="480"></canvas>
   </div>

   <script type="text/javascript">
      // Grab elements, create settings, etc.
   var video = document.getElementById('video');

   // Get access to the camera!
   if(navigator.mediaDevices && navigator.mediaDevices.getUserMedia) {
    // Not adding `{ audio: true }` since we only want video now
    navigator.mediaDevices.getUserMedia({ video: true }).then(function(stream) {
        //video.src = window.URL.createObjectURL(stream);
        video.srcObject = stream;
        video.play();
    });
   }
   var canvas = document.getElementById('canvas');
   var context = canvas.getContext('2d');
   var video = document.getElementById('video');

      // Trigger photo take
   document.getElementById("snap").addEventListener("click", function() {
   context.drawImage(video, 0, 0, 640, 480);
   });
   </script>
</body>
</html>
<?php
}
?>