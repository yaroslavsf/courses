<?php
class GenreModel {
  private $sqlConnection;
  private $table_name; 
  public function __construct() {
      $this->sqlConnection = new MySqlConnection();
      $this->table_name = 'genre';
  }

  function insert(){}
  function delete(){}
  function select($array_names, $find_name = 0, $find_value = 0){
    return $this->sqlConnection->conn->query("SELECT {$array_names[0]} FROM {$this->table_name} WHERE {$find_name} = '{$find_value}'");
   }
  function update(){}
}
?>