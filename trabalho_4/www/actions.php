<?php
	print_r($_POST);
	if (isset($_POST['lamptoggle']))
		shell_exec("py scripts/toggle.py toggle ".$_POST['lamptoggle']);

	if (isset($_POST['customaction'])){
		if ($_POST['customaction'] == "toggleall")
			shell_exec("py scripts/toggle.py");
		elseif($_POST['customaction'] == "turnonall")
			shell_exec("py scripts/toggle.py on");
		elseif($_POST['customaction'] == "turnoffall")
			shell_exec("py scripts/toggle.py off");
		elseif($_POST['customaction'] == "blink")
			shell_exec("py scripts/blink_all.py");	
	
	}
//	echo shell_exec("py scripts/toggle.py on 5");
	header("Location: /#lamps");

?>