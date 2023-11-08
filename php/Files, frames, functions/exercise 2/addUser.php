<form id="" action="addUser.php" method='POST' enctype='multipart/form-data'>
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
    $l = md5($_POST['login']);
    $pass = md5($_POST['password']);


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
        $result = fwrite($file, $l.'|'.$pass.'|'.PHP_EOL);
        
    }


    fclose($file);
}

?>

