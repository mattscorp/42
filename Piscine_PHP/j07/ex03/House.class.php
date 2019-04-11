<?php

class House {
	public function introduce(){
		echo "House ";
		print($this->getHouseName());
		echo " of ";
		print($this->getHouseSeat());
		echo " : ";
		echo "\"";
		print($this->getHouseMotto());
		echo "\"";
		echo "\n";
		}
}
?>