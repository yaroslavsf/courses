<?php
include_once('BaseController.php');
class BasketController extends BaseController{   
    public function show_basket_page($email, $role) {
        $basket_model = new BasketModel();
        $user_model = new UserModel();
        $book_model = new BookModel();
        $service = new Service();

        $books = $service->get_basket_books_by_email($email, $basket_model, $user_model, $book_model);
        if (count($books) == 0) {
            $this->view->render_no_books_in_basket($role);
        } else {
            $this->view->render_basket_page($books, $role);
        }
        
    }
    public function add_book_to_basket($book_id, $email) {
        $basket_model = new BasketModel();
        $user_model = new UserModel();
        $service = new Service();

        $service->add_book_to_basket($book_id, $email, $basket_model, $user_model);
    }
    public function remove_book_from_basket($book_id, $email) {
        $basket_model = new BasketModel();
        $user_model = new UserModel();
        $service = new Service();

        $service->remove_book_from_basket($book_id, $email, $basket_model, $user_model);
    }
}
?>