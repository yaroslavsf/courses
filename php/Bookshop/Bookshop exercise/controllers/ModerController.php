<?php
include_once('BaseController.php');
class ModerController extends BaseController{
    public function show_books_admin_page($role) {
        $book_model = new BookModel();
        $service = new Service();

        $books = $service->get_books($book_model);
        $this->view->render_books_admin_page($books, $role);
    }

    public function show_add_book_page($role) {
        $genre_model = new GenreModel();
        $service = new Service();
        
        $genres = $service->get_genres($genre_model); 
        $this->view->render_add_book_page($genres,$role); 
    }

    public function add_book_moder($name, $author, $genre, $desctiption) {
        $book_model = new BookModel();
        $genre_model = new GenreModel();
        $service = new Service();

        $service->add_new_book($name, $author, $genre, $desctiption, $book_model, $genre_model);
    }
}
?>