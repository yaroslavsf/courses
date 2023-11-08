<form action="index.php" method="POST" enctype='multipart/form-data'>
	<input type="text" name="country">
	<input type = "submit" value="Submit">
</form>

<?php
$file = fopen('countries.txt', 'a+');
if (isset($_POST['country'])) {
	$country = $_POST['country'];
	
	$countries = [];
	$str = true;
	while ($str != false) {
		$str = fgets($file);
		if ($str != false)
		{
			$str = trim(preg_replace('/\s\s+/', ' ', $str));
			$countries []= $str;
		}
	}

	$found = false;
	foreach($countries as $countr) {	
		echo ($countr);
		echo ($country);
		if ($countr===$country)
		{
			$found = true;
		}
		
	}
	if ($found == false)
	{
		fwrite($file, $country.PHP_EOL);
	}
}

?>
