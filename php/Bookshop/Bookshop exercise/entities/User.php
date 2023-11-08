<?php
class User {
    public $id;
    public $firstname;
    public $lastname;
    public $phone_number;
    public $email;  
  
    // MD5 generates a 128-bit hash value. You can use CHAR(32) or BINARY(16)
    public $password; 
    public function __construct($i, $f, $l, $p, $e, $pass)
    {
        $this->id = $i;
        $this->firstname = $f;
        $this->lastname = $l;
        $this->phone_number = $p;
        $this->email = $e;
        $this->password = $pass;
        
    }
}
?>