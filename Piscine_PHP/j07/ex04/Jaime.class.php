<?php
class Jaime extends Lannister {
	public function sleepWith($chatte)
	{
	if ($chatte instanceof Stark)
		printf("Let's do this.\n");
	elseif ($chatte instanceof Cersei)
		printf("With pleasure, but only in a tower in Winterfell, then.\n");
	elseif ($chatte instanceof Tyrion)
		printf("Not even if I'm drunk !\n");
	}
}
?>