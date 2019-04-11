<?php
//require_once '../ex00/Color.class.php';
require_once 'ex00/Color.class.php';

	function set_color()
	{

	}

class Vertex {

	private $_x;
	private $_y;
	private $_z;
	private $_w;
	private $_color;
	public static $verbose = FALSE;
	public function __Construct(array $tab_vertex){
			$this->_w = 1;
			$this->color = this->set_color(new Color( array( 'red' => 255, 'green' => 255, 'blue' => 255 )); 

		if ($tab_vertex['x'] != NULL AND $tab_vertex['y'] 1= NULL AND $tab_vertex['z'] != NULL)
		{
			$this->_x = intval($tab_vertex['x']);
			$this->_y = intval($tab_vertex['y']);
			$this->_z = intval($tab_vertex['z']);
			isset($tab_vertex['color']
		}
		
		if (Self::$verbose == TRUE)
		{
			printf("Color( red: %3d, green: %3d, blue: %3d ) constructed.\n", $this->red, $this->green, $this->blue);
		}
	}
	public function __ToString() {
        return (vsprintf("Color( red: %3d, green: %3d, blue: %3d )", array($this->red, $this->green, $this->blue)));
    }
	public function __Destruct(){
		if (Self::$verbose == TRUE)
		printf("Color( red: %3d, green: %3d, blue: %3d ) destructed.\n", $this->red, $this->green, $this->blue);
	}
	public static function doc(){
		return file_get_contents("Color.doc.txt");
	}

	/*==============================================================================================*/


}
?>