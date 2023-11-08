<?php
include_once('View.php');
include_once('dbWorker.php');
class BaseController {
    public $dbWorker;
    public function __construct() {
        $this->dbWorker = new DbWodrker();
    }
}
?>