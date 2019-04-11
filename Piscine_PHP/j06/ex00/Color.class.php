<?php
class Color {

	public $red;
	public $green;
	public $blue;
	public static $verbose = FALSE;
	
	public function __Construct(array $tab_color){

		if (isset($tab_color['red']) AND isset($tab_color['green']) AND isset($tab_color['blue']) )
		{
			$this->red = intval($tab_color['red']);
			$this->green = intval($tab_color['green']);
			$this->blue = intval($tab_color['blue']);
		}
		else if (isset($tab_color['rgb']))
		{
			$this->red = intval(($tab_color['rgb'] >> 16) & 255);
			$this->green = intval(($tab_color['rgb'] >> 8) & 255);
			$this->blue = intval($tab_color['rgb'] & 255);

		}
		if (Self::$verbose == TRUE)
		{
			printf("Color( red: %3d, green: %3d, blue: %3d ) constructed.\n", $this->red, $this->green, $this->blue);
		}
		return;
	}
	public function __ToString() {
        return (vsprintf("Color( red: %3d, green: %3d, blue: %3d )", array($this->red, $this->green, $this->blue)));
    }
	public function __Destruct(){
		if (Self::$verbose == TRUE)
			return (printf("Color( red: %3d, green: %3d, blue: %3d ) destructed.\n", $this->red, $this->green, $this->blue));
	}
	public static function doc(){
		return file_get_contents("Color.doc.txt");
	}

	/*==============================================================================================*/

	public function add($couleur)
	{
		$nouvelle_couleur = new Color(array ('red' => $this->red + $couleur->red, 'green' => $this->green + $couleur->green, 'blue' => $this->blue + $couleur->blue));

		return $nouvelle_couleur;
	}

	public function sub($couleur)
	{
		$nouvelle_couleur = new Color(array ('red' => $this->red - $couleur->red, 'green' => $this->green - $couleur->green, 'blue' => $this->blue - $couleur->blue));

		return $nouvelle_couleur;
	}
	public function mult($couleur)
	{
		$nouvelle_couleur = new Color(array ('red' => $this->red * $couleur, 'green' => $this->green * $couleur, 'blue' => $this->blue * $couleur));

		return $nouvelle_couleur;
	}
}
?>