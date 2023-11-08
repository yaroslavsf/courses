<?php
class DbWodrker {
    private $host = "localhost";
    private $username = "root";
    private $password = "";
    private $db = "prof_home_page";
    public $conn = null;

  public function __construct() {  
    $this->conn = new mysqli($this->host, $this->username, $this->password, $this->db);
  }      

  public function insert($table_name, $array_names, $array_values){  
     $string_names = '`';
    foreach($array_names as $array_name => $val) {
      $string_names = $string_names.$val.'`,`';
    }
    $string_names = substr($string_names, 0, -2);

    $string_values = '\'';
    foreach($array_values as $array_value => $val) {
      $string_values = $string_values.$val.'\',\'';
    }
    $string_values = substr($string_values, 0, -2);

    echo $string_names;
    echo $string_values;

    $this->conn->query("INSERT INTO {$table_name}
    ({$string_names}) 
    VALUES ({$string_values})");
  }
  function delete(){}
  function select($table_name, $array_names, $find_name = 0, $find_value = 0){
   return $this->conn->query("SELECT {$array_names[0]} FROM {$table_name} WHERE {$find_name} = '{$find_value}'");
  }
  function update($array_names, $array_values) {
      //TODO
    $this->conn->query("UPDATE `texts` SET `article1`='$array_values[0]',`article2`='$array_values[1]',`article3`='$array_values[2]',`main_article`='$array_values[3]',`photo`='$array_values[4]'");
  }
  function execute_query($query) {
     return $this->conn->query($query);
  }
        
}
?>