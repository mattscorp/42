<?php

class UnholyFactory
{
	public static $list_warriors;
	public static $list_name_warriors;
	public function absorb($sbire)
	{
		$la_liste = explode("|", UnholyFactory::$list_warriors);
	if ($sbire instanceof Fighter)
			{
				if (!in_array(get_class($sbire), $la_liste))
				{
					UnholyFactory::$list_warriors = UnholyFactory::$list_warriors."|".get_class($sbire);

					UnholyFactory::$list_name_warriors = UnholyFactory::$list_name_warriors."|".$sbire->name;
						
					echo "(Factory absorbed a fighter of type ".$sbire->name.")\n";	
				}
				elseif (in_array(get_class($sbire), $la_liste))
				{	
					echo "(Factory already absorbed a fighter of type ".$sbire->name.")\n";
				}
			}
		else
			{
				echo "(Factory can't absorb this, it's not a fighter)\n";
			}
	}
	public function fabricate($rf)
	{
		$absorbed = UnholyFactory::$list_name_warriors;
		$sbire_absorbed = explode("|", $absorbed);
		$class_warriors = explode("|", UnholyFactory::$list_warriors);
		if (in_array($rf, $sbire_absorbed))
		{
			$where = array_search($rf, $sbire_absorbed);
			echo "(Factory fabricates a fighter of type $rf)\n";
			return( new $class_warriors[$where]);
		}
		else
		{
			echo "(Factory hasn't absorbed any fighter of type $rf)\n";
		}
	}
}
?>