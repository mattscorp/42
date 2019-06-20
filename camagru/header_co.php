<?php
$id = $_SESSION['id'];
$link = "profil.php?id=".$id;
?>
	<div class="nav_bar">
		<ul>
		 <li><a href="index.php" class="active" >Home Page</a></li>
		 <li><a href= '<?php echo $link; ?>'>Mon Profil</a></li>
		 <li><a href="capture.php">Faire une photo</a></li>
		 <li><a href="edition_profil.php">Modifier mon Profil</a></li>
		 <li><a href="deconnexion.php">Me deconnecter</a></li>
		</ul>
	</div>
<div class="footer">
  <p>Footer</p>
</div>