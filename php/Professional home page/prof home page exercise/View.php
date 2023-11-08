<?php
class View {
    static public function render_nav() {
        include("header.php");
        echo ('
        <form action="index.php" method=\'GET\' enctype=\'multipart/form-data\'>
        <nav class="navbar navbar-expand-lg navbar-light bg-light">
        <div class="container-fluid"> 
            <a class="navbar-brand" href="#">PHP</a>
            <button
            class="navbar-toggler"
            type="button"
            data-mdb-toggle="collapse"
            data-mdb-target="#navbarNav"    
            aria-controls="navbarNav"
            aria-expanded="false"
            aria-label="Toggle navigation">
            <i class="fas fa-bars"></i>
            </button>
            <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav ">
                <li class="nav-item mx-2">
                <a  href="http://localhost/index.php?action=main_page">Main page
                </li>
                <li class="nav-item mx-2">
                <a  href="http://localhost/index.php?action=about_me_page">About me
                </li>
                <li class="nav-item mx-2">
                <a  href="http://localhost/index.php?action=issues_page">Issues
                </li>
                <li class="nav-item mx-2">
                <a href="http://localhost/index.php?action=make_issue_page">Make an issue
                </li>
                </ul>
            </div>
        </div>
        </nav>
        </form>');
    }

    static public function render_main_page() {
        ob_clean();
        View::render_nav();
        echo '
        
        <a></a>
        <div class = "container text-center">
            <main role="main" class="inner cover">
                <h1 class="cover-heading">Greetings!</h1>
                <p>That\'s my first professional home page, i\'m eager to show you what you can do here.</p>
                <p> btw login:"admin" password:"123"</p>
            </main>
            </div>           
        </div>
    
        ';
    }
    
    static public function render_modal_aboutme_page() {
        echo '
        <form action="index.php" method=\'POST\' enctype=\'multipart/form-data\'>
          <label for="InputName" class="mt-5">Name</label>
          <input type="text" class="form-control" placeholder="Enter login" name ="login">       
          <label for="InputAuthor" class="mt-5">Author</label>
          <input type="text" class="form-control" placeholder="Enter password" name="password">
          <input type="submit" class="btn btn-primary" value="submit" name="aboutme_admin_button_submit">
        </form>
        ';
    }
    static public function render_aboutme_page($article1, $article2, $article3, $main_article, $photo) {
        ob_clean();
        View::render_nav();
        echo '
        <a></a>
      <div class="container">
        <!-- Three columns of text below the carousel -->
        <div class="row">
          <div class="col-lg-4">         
            <h2>Фио</h2>
            ' ;  echo sprintf('%s', $article1); echo '
          </div> 
          <div class="col-lg-4">             
            <h2>Место учебы</h2>
            ' ;  echo sprintf('%s', $article2); echo '
          </div> 
          <div class="col-lg-4">         
            <h2>Где программирование?</h2>
            ' ;  echo sprintf('%s', $article3); echo '
          </div> 
        </div>
        <!-- START THE FEATURETTES -->
        <hr class="featurette-divider">
        <div class="row featurette">
          <div class="col-md-7">
            <h2 class="featurette-heading">Обо мне<span class="text-muted"></span></h2>
            ' ;  echo sprintf('%s', $main_article); echo '
          </div>
          <div class="col-md-5">
            <img class="featurette-image img-fluid mx-auto" data-src="holder.js/500x500/auto" alt="500x500" style="width: 500px; height: 500px;" src="' ;  echo sprintf('%s', $photo); echo '" data-holder-rendered="true">
          </div>
        </div>
        <!-- /END THE FEATURETTES -->
      </div>
      <form action="index.php?action=about_me_page" method=\'POST\' enctype=\'multipart/form-data\'> 
      <input type="submit" class="btn btn-primary" value="edit" name="aboutme_admin_button">
      </form>
        ';
    }

    static public function render_aboutme_page_admin($article1, $article2, $article3, $main_article, $photo) {
      ob_clean();
      View::render_nav();
      echo('
        <a></a>
        <form action="index.php" method=\'POST\' enctype=\'multipart/form-data\'> 
          <div class="container">
            <!-- Three columns of text below the carousel -->
            <div class="row">
              <div class="col-lg-4">         
                <h2>ФИО</h2>
                <input type="text" class="form-control" name="article1" value = "');  echo sprintf('%s', $article1); echo('">
              </div> 
              <div class="col-lg-4">             
                <h2>Место учебы</h2>
                <input type="text" class="form-control" name="article2" value = "');  echo sprintf('%s', $article2); echo('">
                </div> 
              <div class="col-lg-4">         
                <h2>Где программирование?</h2>
                <input type="text" class="form-control" name="article3" value = "');  echo sprintf('%s', $article3); echo('">
                </div> 
            </div>
            <!-- START THE FEATURETTES -->
            <hr class="featurette-divider">
            <div class="row featurette">
              <div class="col-md-7">
                <h2 class="featurette-heading">Обо мне<span class="text-muted"></span></h2>
                <input type="text" class="form-control" name="main_article" value = "');  echo sprintf('%s', $main_article); echo('">
                </div>
              <div class="col-md-5">
                <img class="featurette-image img-fluid mx-auto" alt="500x500" style="width: 500px; height: 500px;" src="');  echo sprintf('%s', $photo); echo('" data-holder-rendered="true">
                <input type="text" class="form-control" name="photo" value ="');  echo sprintf('%s', $photo); echo('">
              </div>
            </div>
            <!-- /END THE FEATURETTES -->
          </div>     
      <input type="submit" class="btn btn-primary" value="save" name="save_changes_aboutme">
      </form>
        ');
  }

    static public function render_issues_page($issues) {
        ob_clean();
        View::render_nav();
        echo '
        <a></a>
        <ul class="list-group">';
        foreach($issues as $issue_id => $issue) {
          echo '<li class="list-group-item">';
          echo sprintf('Description: %s', $issue->issue_description);
          echo sprintf('; Rate: %s', $issue->rate);
          echo sprintf('; Author:%s', $issue->author);
          echo '; Tags: ';
          foreach($issue->tags as $tag_index => $tag) {
            echo sprintf(' %s', $tag);
          }
          echo '</li>';
        }    
  echo '</ul>
      
        ';
    }

    static public function render_make_issue_page() {
        ob_clean();
        View::render_nav();
        echo ('
        <a></a>
        <form action="index.php" method=\'POST\' enctype=\'multipart/form-data\'>
            <label for="InputName" class="mt-5">Despription</label>
            <input type="text" class="form-control" placeholder="Enter description" name ="add_description">
                
            <label for="InputAuthor" class="mt-5">Author</label>
            <input type="text" class="form-control" placeholder="Author" name="add_author">
        
            <label  for="InputGenre" class="mt-5">Rate</label>
            <select class="form-select"  name="add_rate">
              <option>1</option>
              <option>2</option>
              <option>3</option>
              <option>4</option>
              <option>5</option>
            </select>  
      
           

            <input type="checkbox" name="technical_issue">
            <label for="contactChoice1">Technical</label>

            <input type="checkbox" name="complaint_issue" >
            <label for="contactChoice2">Complaint</label>

            <input type="checkbox"  name="review_issue" >
            <label for="contactChoice3">Review</label>
            
            <input type="submit" class="btn btn-primary" name="add_issue" value="Submit">
        </form>
    ');
    }
}
