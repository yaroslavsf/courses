<form id="" action="index.php" method='POST' enctype='multipart/form-data'>
    <input type="hidden" name="csr_token" value="1">
    <div>
        <input type="text" name="login" value="">
    </div>
    <div>
        <input type="password" name="password" value="">
    </div>
    <input type="submit" value="Click_me"> 
</form>


<?php

if (isset($_POST['login']) || isset($_POST['password'])) {
$l = $_POST['login'];
$pass = $_POST['password'];



$file = fopen('users.txt', 'a+');

$str = true;
while ($str != false) {
    $str = fgets($file);

    $array = explode('|', $str);
    // if (strcmp($_POST['login'], $array[0])) {
    //     $found = true;
    // }
    $users []= $array;
}

$found = false;
foreach($users as $user) {
    foreach($user as $key=> $option)
    {
        if ($user[$key] == $l || $user[$key] == $pass)
        {
            $found = true;
        }
    }
    
}

if ($found == false)
{
    fwrite($file, $l.'|'.$pass.'|'.PHP_EOL);
}


fclose($file);
}
// if ($found) {
//     echo('Opps, already exists');
// } else {


?>

