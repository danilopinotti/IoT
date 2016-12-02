<?php
	$lamp_state = [];
	for($i = 2; $i < 8; $i++){
		$lamp_state[$i] = trim(shell_exec("py scripts/status.py ".$i));
	}
?>

<p>Lâmpadas</p>
<form action="actions.php" method="GET" name="lamps">
<?php for($i = 2; $i < 8; $i++): ?>

	<div class="lamp-desc"> 
		<button type="submit" name="lamp_toggle" value="<?= $i ?>" class="btn btn-default">Lâmpada <?= $i ?>	
			<span class="glyphicon glyphicon-lamp <?= ($lamp_state[$i]=="ON")?"warning-color":"" ?>"></span>
		</button>
	</div>
<?php endfor; ?>
</form>