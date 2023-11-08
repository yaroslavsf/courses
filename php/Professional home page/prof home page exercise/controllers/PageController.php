<?php

include_once('BaseController.php');
class Issue{
    public $id;
    public $issue_description;
    public $rate;
    public $author;
    public $tags = [];
    public function __construct($id, $is, $rate, $author, $tags)
    {
        $this->id = $id;
        $this->issue_description = $is;
        $this->rate = $rate;
        $this->author = $author;
        $this->tags = $tags;
    }
}

class PageController extends BaseController{
    public function show_main_page() {
        View::render_main_page();           
    }

    //where all post data are manipulated (also default render of main page)
    public function default_page() {

        if (isset($_POST['add_issue'])) {
            echo 'qwe';
            $tags = [];
            $description = $_POST['add_description'];
            $author = $_POST['add_author'];
            $rate = $_POST['add_rate'];
            if (isset($_POST['technical_issue'])) {
                $tags[] = 1;
            }
            if (isset($_POST['complaint_issue'])) {
                $tags[] =  2;
            }
            if (isset($_POST['review_issue'])) {
                $tags[] =  3;
            }

            $this->dbWorker->insert("text_issue", ["issue_description","rate","author"], [$description, $rate, $author]);

            $query_result_issue = $this->dbWorker->execute_query("SELECT * FROM `text_issue` ORDER BY id DESC LIMIT 1;");
            $issue_id = ($query_result_issue->fetch_assoc())['id'];
            foreach($tags as $tag_id => $tag) {
                $this->dbWorker->insert("intermediate_issue_tag", ["issue_id", "tag_id"], [$issue_id, $tag]);
            }
        }


        if (isset($_POST['aboutme_admin_button_submit'])) {
            $authControl = new AuthController();
            if (isset($_POST['login']) && isset($_POST['password'])) {
                if ($authControl->check_user($_POST['login'], $_POST['password']) == true) {              
                    $query_result = $this->dbWorker->select('texts', ['*']);
                    $row = $query_result->fetch_assoc();
                    View::render_aboutme_page_admin($row['article1'], $row['article2'], $row['article3'], $row['main_article'], $row['photo']);
                return;
                }
            }               
        }

       
        if (isset($_POST['save_changes_aboutme'])) {
           $article1 = $_POST['article1'];
           $article2 = $_POST['article2'];
           $article3 = $_POST['article3'];
           $main_article = $_POST['main_article'];
           $photo = $_POST['photo'];

           $array_names = [`article1`, `article2`, `article3`, `main_article`, `photo`];
           $array_values = [$article1, $article2, $article3, $main_article, $photo];
           $this->dbWorker->update($array_names, $array_values);
        }


        if (!isset($_GET['action'])) {
            View::render_main_page();
           }
        
    }

    public function show_aboutme_page() {
        $query_result = $this->dbWorker->select('texts', ['*']);
                    $row = $query_result->fetch_assoc();
                    View::render_aboutme_page($row['article1'], $row['article2'], $row['article3'], $row['main_article'], $row['photo']);
        if (isset($_POST['aboutme_admin_button'])) {
            View::render_modal_aboutme_page();
        } 
    }


    // public function show_aboutme_page_admin() {
    //     View::render_aboutme_page_admin();
    // }


    public function show_issues_page() {
        //issues
        $query_result_issues = $this->dbWorker->select('text_issue',['*']);
        $issues = [];
        while($row = $query_result_issues->fetch_assoc()) {

            //intermediate
            $query_result_issues_tags = $this->dbWorker->select('intermediate_issue_tag', ['*'], 'issue_id', $row['id']);           
            $index_tags = [];
            while($row2 = $query_result_issues_tags->fetch_assoc()) {
                $index_tags[] = $row2['tag_id'];
            }
            $tags = [];
            foreach($index_tags as $smth => $index) {
                $query_result_tags = $this->dbWorker->select('issue_tags', ['*'], 'id', $index);
                $row3 = $query_result_tags->fetch_assoc(); 
                $tags[] = $row3['issue_tag'];
                
            }
            $issues[] = new Issue($row['id'], $row['issue_description'], $row['rate'], $row['author'], $tags);
            
            
        }


        View::render_issues_page($issues);
    }
    public function show_make_issue_page() {
        View::render_make_issue_page();
    }
}
?>