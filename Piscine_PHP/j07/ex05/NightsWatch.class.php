<?php 

class NightsWatch{
	public static $list_fighter = "";
	public function recruit($person)
	{
		NightsWatch::$list_fighter = NightsWatch::$list_fighter."|".get_class($person);
	}

	public function fight()
	{
			$tab_recru = explode("|", NightsWatch::$list_fighter);
			foreach ($tab_recru as $key => $value) 
			{
				if (class_exists($value))
				{
					$tab_recru_ok = new $value;
					if(method_exists($tab_recru_ok, fight))
					{
						print($tab_recru_ok->fight());
					}
				
				}
			}
	}
}
?>