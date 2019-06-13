<html>
<head>
	<title>CAMAGRU HOME PAGE</title>
	<link href="styles.css" rel="stylesheet">
</head>
<body>
	<?php
	session_start();
	include("coco.php");
	if(isset($_SESSION['id']) AND $_SESSION['id'] > 0)
	{
		include("header_co.php");
	}
	else
		include("header.php");
	$lesposts = $bdd->prepare('SELECT * FROM images ORDER BY id_img DESC');
	$lesposts->execute();
	
	
	while ($donnees = $lesposts->fetch())
	{
	?>
	<div class="container">
	<p>
		<strong>Photo de : </strong>
		<?php 

		$id = $donnees['id_user_img'];
		$pseudo = $bdd->prepare('SELECT * FROM users WHERE id = ?');
		$pseudo->execute(array($id));
		$e = $pseudo->fetch();
		echo $e['pseudo'];
		?> <br>
		<?php 
			//$imageurl = $bdd->prepare("SELECT * FROM images");
		//	$test = base64_decode($donnees['img_data']);
		//	$linkimg = "genere_image.php?id=".$donnees['id_img'];

			echo  "$image"."\n";
			echo "$linkimg";
			echo '<img class="" src="'.$donnees['link_img'].'"/>';

		?>
	</p>
	</div>
	<?php
	}
	?>
</body>
</html>