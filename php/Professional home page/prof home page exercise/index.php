<?php
foreach(glob("controllers/*.php") as $filename) {
    include_once $filename;
}


class Router {
    public $controller;
    public function __construct()
    {
        $this->controller = new PageController();
    }

    public function route() {               
        switch($_GET['action']) {
            case 'main_page':
                $this->controller->show_main_page();
                break;                   
            case 'about_me_page':
                $this->controller->show_aboutme_page();
                break;
            case 'issues_page';
                $this->controller->show_issues_page();
                break;
            case 'make_issue_page';
                $this->controller->show_make_issue_page();
                break;
            default:
                $this->controller->default_page();
        }
    }
}

$router = new Router();
$router->route();
?>