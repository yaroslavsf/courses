<?php
class BasketModel{
  private $sqlConnection;
  private $table_name; 
  public function __construct() {
      $this->sqlConnection = new MySqlConnection();
      $this->table_name = 'basket';
  }
  public function insert($array_names, $array_values){  
    //TODO: automatization of insert with 2 arrays

    // $string_names = '\'';
    // foreach($array_names as $array_name => $val) {
    //   $string_names = $string_names.$val.'\',\'';
    // }
    // substr($string_names, 0, -3);

    // $string_values = '\'';
    // foreach($array_values as $array_value => $val) {
    //   $string_values = $string_values.$val.'\',\'';
    // }
    // substr($string_values, 0, -3);


    // $this->sqlConnection->conn->query("INSERT INTO {$this->table_name}
    // ({$string_names}) 
    // VALUES ({$string_values})");

    $this->sqlConnection->conn->query("INSERT INTO {$this->table_name}
    (`user_id`,`book_id`) 
    VALUES ('{$array_values[0]}','{$array_values[1]}')");
  }
  function delete($array_names, $array_values){
    return $this->sqlConnection->conn->query("DELETE FROM `basket` WHERE user_id={$array_values[0]} AND book_id=$array_values[1]");
  }
  function select($array_names, $find_name = 0, $find_value = 0){
    return $this->sqlConnection->conn->query("SELECT {$array_names[0]} FROM {$this->table_name} WHERE {$find_name} = '{$find_value}'");
  }
  function update(){}
}
?>