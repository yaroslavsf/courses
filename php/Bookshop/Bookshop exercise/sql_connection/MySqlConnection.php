<?php
class MySqlConnection {
    private $host = "localhost";
    private $username = "root";
    private $password = "";
    private $db = "bookshop_v2";
    public $conn = null;

  public function __construct() {  
    $this->conn = new mysqli($this->host, $this->username, $this->password, $this->db);
  }      
}
