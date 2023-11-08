<form action="index.php" method="POST" enctype='multipart/form-data'>
	<input type="text" name="country">
	<input type = "submit" value="Submit">
</form>

<?php

class Writer
{
	public $countries = [];
	public $dictPath = 'dictionary.txt';
	public $countrPath = 'countries.txt';
	public $input;


	public function __construct() {
		$this->input = $_POST['country'];
	}

	public function check()
	{
		$file = fopen($this->dictPath, 'a+');
		if (isset($this->input)) {
		
			
			
			$str = true;
			while ($str != false) {
				$str = fgets($file);
				if ($str != false)
				{
					$str = trim(preg_replace('/\s\s+/', ' ', $str));
					$this->countries []= $str;
				}
			}
		fclose($file);
		}
	}

	public function write()
	{
		$found = false;
		foreach($this->countries as $countr) {	
		
			if ($countr===$this->input)
			{
				$found = true;
			}
			
		}
		if ($found == false)
		{
			$file = fopen($this->countrPath, 'a+');
			fwrite($file, $this->input.PHP_EOL);
			fclose($file);
		}
	}
}


$wr = new Writer;
$wr->check();
$wr->write();

?>
