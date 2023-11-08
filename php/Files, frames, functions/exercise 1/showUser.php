<?php
$file = fopen('users.txt', 'a+');
$str = true;


$users = [];
while ($str != false) {
    $str = fgets($file);
    $array = explode('|', $str);
    $users []= $array;
}

fclose($file);

?>

<table>
    <?php
        foreach($users as $user) {
            echo('<tr>');
                foreach ($user as $column) {
                    echo(sprintf('<td>%s</td>', $column));
                }
            echo('</tr>');
        }

       $date = new DateTime();
    ?>
</table>
