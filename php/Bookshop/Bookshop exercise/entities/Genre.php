<?php
class Genre {
    public $id;
    public $name;
    public function __construct($i,$n)
    {
        $this->id = $i;
        $this->name = $n;
    }

}
?>