<?php
include_once('BaseController.php');
class AuthController extends BaseController {
    public function check_user($login, $password) {  //assumes only one user in table
        $query_result = $this->dbWorker->select('admin', ['*']);
        $row = $query_result->fetch_assoc();
        if ($row['login'] == $login && $row['password'] == $password) {
            return true;
        }
        return false;
    }
}
?>