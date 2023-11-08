<form id="" action="check.php" method='POST' enctype='multipart/form-data'>
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

session_start();

if (isset($_POST['login']) || isset($_POST['password'])) {
$l = $_POST['login'];
$pass = trim($_POST['password']);


$_SESSION["login"]=$l;
$_SESSION["password"]=$pass;

}



?>  