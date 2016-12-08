<?php
	$lamp_state = [];
	for($i = 2; $i < 8; $i++){
		$lamp_state[$i] = trim(shell_exec("py scripts/status.py ".$i));
	}
?>

<p>Lâmpadas</p>
<form action="actions.php" method="POST">
<?php for($i = 2; $i < 8; $i++): ?>

	<div class="lamp-desc"> 
		<button type="submit" name="lamptoggle" value="<?= $i ?>" class="btn btn-default col-md-4">Lâmpada <?= $i ?>	
			<span class="glyphicon glyphicon-lamp <?= ($lamp_state[$i]=="ON")?"warning-color":"" ?>"></span>
		</button>
	</div>
<?php endfor; ?>
</form>
<form action="actions.php" method="POST">
		<button type="submit" name="customaction" value="toggleall" class="btn btn-default">Alternar todas</button>
		<button type="submit" name="customaction" value="turnonall" class="btn btn-default">Ligar todas</button><br>
		<button type="submit" name="customaction" value="turnoffall" class="btn btn-default">Desligar todas</button>
		<button type="submit" name="customaction" value="blink" class="btn btn-default disabled" disabled>Todas piscarem</button>
</form>