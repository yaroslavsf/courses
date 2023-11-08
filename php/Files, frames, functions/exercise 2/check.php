<?php

session_start();

$l = md5($_SESSION["login"]);
$pass = md5($_SESSION["password"]);


$file = fopen('users.txt', 'a+');

$str = true;
while ($str != false) {
    $str = fgets($file);

    $array = explode('|', $str);
    $users []= $array;
}

$found = false;
foreach($users as $user) {
    foreach($user as $key=> $option)
    {
        if ($user[$key] == $l && $user[$key] == $pass)
        {
            $found = true;
            break;
        }
    } 
}

if ($found == false)
{
   echo("Not registred");
}
else if ($found == true)
{
    echo("Welcome");
}


fclose($file);

?>