
<?php


//models
foreach(glob("controllers/*.php") as $filename) {
    include_once $filename;
}

$authController = new AuthController();
$shopController = new ShopController();
$basketController = new BasketController();
$moderController = new ModerController();
$adminController = new AdminController();

session_start();
$_SESSION["loggedIn"];
$role;

//AUTH PAGE 
    if ($_SESSION["loggedIn"] == 0)
    $authController->show_auth_page();
    
    //if "Sign in" is clicked
    if (isset($_POST['sign'])) {
        if (empty($_POST['email']) || empty($_POST['password'])) {
            echo ("all fields are required");
        } else {
            $email = $_POST['email'];
            $pass = trim($_POST['password']);

            if ($authController->check_user($email) == true) {        //check if user is in db(plugged)
                // $loggedIn = 1;
                $_SESSION["loggedIn"]=1;
                $_SESSION["email"] = $email;
                $_SESSION["role"] = $authController->check_for_role($email);    //returns 'admin', 'user', 'moder' (plugged)
            } else {
                echo ("password or email is not corect");
            }
        }
    }


    //if "Register" is clicked
    if (isset($_POST['reg'])) {
        $authController->show_reg_page();
        if (empty($_POST['reg_password']) || empty($_POST['reg_email']) || empty($_POST['firstname']) || empty($_POST['lastname']) || empty($_POST['phone_number'])) {
            echo ("all fields are required");
        } else {
            $email_reg = $_POST['reg_email'];
            $pass_reg = $_POST['reg_password'];
            $firstname = $_POST['firstname'];
            $lastname = $_POST['lastname'];
            $phone_number = $_POST['phone_number'];
            if ($authController->check_user($email_reg) == true) {            //plugged
                echo ("user already exists");
                
            } else {
                $authController->register_user($email_reg, $pass_reg, $firstname, $lastname, $phone_number);
                // $loggedIn = 1;
                $_SESSION["loggedIn"]=1;
                header( "Location: index.php" );
                exit();
            }
        }
    }


//SHOP ROUTER
if ($_SESSION["loggedIn"] == 1 ) {
    $shopController->show_catalog_page($_SESSION["role"]);

    $booksIdArray = $shopController->get_books_id_array();
    foreach($booksIdArray as $bookId){
        if (isset($_POST['descriptionBookBtn-'.strval($bookId)]))
        {
           $shopController->show_book_detail_page($bookId, $_SESSION["role"]);
        }
        if (isset($_POST['addToBasketBook-'.strval($bookId)])) {
            $basketController->add_book_to_basket($bookId, $_SESSION["email"]);
        }

    }
    foreach($booksIdArray as $bookId){
        if (isset($_POST['removeFromBasket-'.strval($bookId)])) {
            $basketController->remove_book_from_basket($bookId, $_SESSION["email"]);
            $basketController->show_basket_page($_SESSION["email"], $_SESSION["role"]);
        }
    }




    if (isset($_POST['catalog'])) {
        $shopController->show_catalog_page($_SESSION["role"]);
    }
    
    if (isset($_POST['basket'])) {
        $basketController->show_basket_page($_SESSION["email"], $_SESSION["role"]);
    }
    if (isset($_POST['admin_books'])) {
        $moderController->show_books_admin_page($_SESSION["role"]);      
    }
    if (isset($_POST['addBookAdmin'])) {
        $moderController->show_add_book_page($_SESSION["role"]);     
    }

    if (isset($_POST['addBookAdminButton'])) {
        $book_name_add = $_POST['addNameBook'];
        $book_author_add = $_POST['addAuthorBook'];
        $book_genre_add = $_POST['addSelectedGenreBook'];
        $book_description_add =  $_POST['addDescriptionBook']; 
        $moderController->add_book_moder($book_name_add, $book_author_add, $book_genre_add, $book_description_add);
        $moderController->show_books_admin_page($_SESSION["role"]);
    }

    if (isset($_POST['BackAddBookAdmin'])) {
        $moderController->show_books_admin_page($_SESSION["role"]);   
    }
    if (isset($_POST['admin_users'])) {
        $adminController->show_users_admin_page($_SESSION["role"]);
    }
}

?>