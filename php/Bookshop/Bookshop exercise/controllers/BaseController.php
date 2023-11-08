<?php
include 'view/View.php';
include 'Services.php';

class BaseController {
    //MODELS
    protected $view;
    public function __construct()
    {  
        $this->view = new View();      
    }   
}
?>