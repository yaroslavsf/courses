<?php
class BookModel {
  public $sqlConnection;
  public $table_name; 
  public function __construct() {
      $this->sqlConnection = new MySqlConnection();
      $this->table_name = 'book';
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
    (`name`, `description`, `genre_id`, `author`) 
    VALUES ('{$array_values[0]}','{$array_values[1]}','{$array_values[2]}','{$array_values[3]}')");
  }
  public function delete(){}
  function select($array_names, $find_name = 0, $find_value = 0){
    return $this->sqlConnection->conn->query("SELECT {$array_names[0]} FROM {$this->table_name} WHERE {$find_name} = '{$find_value}'");
   }
  public function update(){}
}
?>