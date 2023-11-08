<?php
class View
{
  public function render_no_books_in_basket($role) {
    ob_clean();
    $this->render_nav($role);
    echo("<h3>No books</h3>");
  }
  public function render_user_admin_page($users, $role)
  {
    ob_clean();
    $this->render_nav($role);

    echo ('<form action="index.php" method=\'POST\' enctype=\'multipart/form-data\'>
    <input type="submit" class="btn btn-lg btn-primary" value="Add User" name="addBtn">
    <ul class="list-group">');
    for ($i = 0; $i < count($users); $i++) {
      echo sprintf('<li class="list-group-item">%s 
            <div style="text-align: right">
            <input type="submit" class="btn btn-lg btn-secondary" value="Delete" name="deleteBtn">

            <input type="submit" class="btn btn-lg btn-secondary" value="Info" name="descriptionUserBtn-%d">
            </div>
        </li>', $users[$i]->email,  $users[$i]->id);
    }
    echo ('</ul></form>');
  }

  public function render_books_admin_page($books, $role)
  {
    ob_clean();
    $this->render_nav($role);
    echo ('<form action="index.php" method=\'POST\' enctype=\'multipart/form-data\'>
    <input type="submit" class="btn btn-lg btn-primary" value="Add book" name="addBookAdmin">
    <ul class="list-group">');
    for ($i = 0; $i < count($books); $i++) {
      echo sprintf('<li class="list-group-item">%s 
            <div style="text-align: right">
            <input type="submit" class="btn btn-lg btn-secondary" value="Delete" name="deleteBtn">

            <input type="submit" class="btn btn-lg btn-info" value="Description" name="descriptionBookBtn-%d">
            </div>
        </li>', $books[$i]->name,  $books[$i]->id);
    }
    echo ('</ul></form>');
  }

  public function render_add_book_page($genres, $role)
  {
    ob_clean();
    $this->render_nav($role);
    echo ('<form action="index.php" method=\'POST\' enctype=\'multipart/form-data\'>

      <label for="InputName" class="mt-5">Name</label>
      <input type="text" class="form-control" placeholder="Enter book name" name ="addNameBook">
        
      <label for="InputAuthor" class="mt-5">Author</label>
      <input type="text" class="form-control" placeholder="Author" name="addAuthorBook">
  
      <label  for="InputGenre" class="mt-5">Password</label>
      <select class="form-select" name="addSelectedGenreBook"> ');
    foreach ($genres as $genre_id => $genre) {
      echo sprintf('<option>%s</option>', $genre->name);
    }
    echo ('</select>  
      <label  for="InputDescription" class="mt-5">Description</label>
      <input type="text" class="form-control" placeholder="Desctiption :3"name="addDescriptionBook">
  
    <button type="submit" class="btn btn-danger mt-2" name="BackAddBookAdmin">Back</button>
    <button type="submit" class="btn btn-primary" name="addBookAdminButton">Submit</button>
  </form>
    ');
  }

  public function render_basket_page($books, $role)
  {
    ob_clean();
    $this->render_nav($role);
    echo ('<form action="index.php" method=\'POST\' enctype=\'multipart/form-data\'>
    <ul class="list-group">');
    for ($i = 0; $i < count($books); $i++) {
      echo sprintf('<li class="list-group-item">
        %s
        <div style="text-align: right">
        <input type="submit" class="btn btn-lg btn-secondary" value="Buy" name="buyButton">        
        <input type="submit" class="btn btn-lg btn-info" value="Description" name="descriptionBookBtn-%d">
        <input type="submit" class="btn btn-lg btn-danger" value="Remove from basket" name="removeFromBasket-%d">
        </div>
        </li>', $books[$i]->name,  $books[$i]->id, $books[$i]->id);
    }
    echo ('</ul></form>');
  }

  public function render_nav($role)
  {
    include("header.php");
    echo ('
   <form action="index.php" method=\'POST\' enctype=\'multipart/form-data\'>
   <nav class="navbar navbar-expand-lg navbar-light bg-light">
   <div class="container-fluid"> 
     <a class="navbar-brand" href="#">Bookshop</a>
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
       <ul class="navbar-nav">
         <li class="nav-item">
         <input type="submit" class="btn btn-lg btn-light" value="Catalog" name = "catalog">
         </li>
         <li class="nav-item">
         <input type="submit" class="btn btn-lg btn-light" value="Basket" name = "basket">
         </li>');
    if ($role == 'admin' || $role == 'moder')
      echo ('<li class="nav-item">
    <input type="submit" class="btn btn-lg btn-light" value="Books(moder)" name = "admin_books">
         </li>');
    if ($role == 'admin')
      echo ('<li class="nav-item">
    <input type="submit" class="btn btn-lg btn-light" value="Users(admin)" name = "admin_users">
         </li>');
    echo ('</ul>
     </div>
   </div>
 </nav>
 </form>');
  }

  public function renderCatalogPage($books, $role) //array of books
  {
    ob_clean();
    $this->render_nav($role);
    echo ('<form action="index.php" method=\'POST\' enctype=\'multipart/form-data\'>
    <ul class="list-group">');
    for ($i = 0; $i < count($books); $i++) {
      echo sprintf('<li class="list-group-item">
        %s
        <div style="text-align: right">
        <input type="submit" class="btn btn-lg btn-secondary" value="Buy" name="buyButton">
        <input type="submit" class="btn btn-lg btn-primary" value="Add to basket" name="addToBasketBook-%d">
        <input type="submit" class="btn btn-lg btn-info" value="Description" name="descriptionBookBtn-%d">
        </div>
        </li>', $books[$i]->name, $books[$i]->id, $books[$i]->id);
    }
    echo ('</ul></form>');
  }

  public function render_book_info_page($book, $role)
  {
    ob_clean();
    $this->render_nav($role);
    echo sprintf(' 
    <div class="jumbotron mx-4">
     <h1 class="display-4">%s</h1>
      <p class="lead">%s</p>
      <hr class="my-4">
      <p>%s</p>
      <p class="lead">
        <a class="btn btn-primary btn-lg" href="#" role="button">Learn more</a>
      </p>
   </div>   
    ', $book->name, $book->author, $book->description);
  }



  public function render_auth_page()
  {
    ob_clean();
    include('header.php');
    echo ('
    <div class="container" style="display:flex;height:98%">
    <div class="container" style="display:flex; justify-content:center; flex-direction:column; width:30%">

    <form action="index.php" method="POST" enctype="multipart/form-data">
    <div class="input-group mb-3">
    <div class="input-group-prepend">
      <span class="input-group-text" id="basic-addon1">@</span>
    </div>
    <input type="email" placeholder="email" name="email">
  </div>
  
  <div class="input-group mb-3">
  <input type="password" placeholder="password" name="password">
  </div>
  <div class="action">
  <input type="submit" class="btn btn-primary btn-lg" value="Register" name="reg">
  <input type="submit" class="btn btn-primary btn-lg" value="Sign in" name="sign">
  </div>
  </form>
  </div>
  </div>
  
    ');
  }  
  public function render_reg_page()
  {
  
    ob_clean();
    include('header.php');
    echo ('
    <div class="container" style="display:flex;justify-content:center;height:98%">
    <div class="container" style="display:flex; justify-content:center; flex-direction:column; width:30%">

    <form action="index.php" method="POST" enctype="multipart/form-data">
    <div class="input-group mb-3">
    <div class="input-group-prepend">
      <span class="input-group-text" id="basic-addon1">@</span>
    </div>
    <input type="email" placeholder="email" name="reg_email">
  </div>

  <div class="input-group mb-3">
  <input type="text" placeholder="firstname" name="firstname">
  </div>


  <div class="input-group mb-3">
  <input type="text" placeholder="lastname" name="lastname">
  </div>

  <div class="input-group mb-3">
  <input type="text" placeholder="phone number" name="phone_number">
  </div>

  <div class="input-group mb-3">
  <input type="password" placeholder="password" name="reg_password">
  </div>
  <div class="action">
  <input type="submit" class="btn btn-primary btn-lg" value="Register" name="reg">
  <input type="submit" class="btn btn-primary btn-lg" value="Sign in" name="sign">
  </div>
  </form>
  </div>
  </div>
  
    ');
  }
}

