<?php
class Book {
    public $id;
    public $name;
    public $author;
    public $genre_id;
    public $description;
    public function __construct($i, $n, $a, $g, $d)
    {
        $this->id = $i;
        $this->name = $n;
        $this->author = $a;
        $this->genre_id = $g;
        $this->description = $d;
        
    }
}
?>