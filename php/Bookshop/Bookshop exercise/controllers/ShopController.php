<?php
include_once('BaseController.php');
class ShopController extends BaseController{
    //VIEW and MODELS interaction methods
    public function show_catalog_page($role)
    {
        $book_model = new BookModel();
        $service = new Service();
     
        //method that gives me an array of books
        $books = $service->get_books($book_model);                                                               //plugged
        $this->view->renderCatalogPage($books, $role);//param as an array that came from service   
    }

    public function show_book_detail_page($id, $role) {
        $book_model = new BookModel();
        $service = new Service();

        $book = $service->get_book_info_by_id($id,$book_model);
        $this->view->render_book_info_page($book, $role);
    }

    public function get_books_id_array() {
        $service = new Service();
        $book_model = new BookModel();
        return $service->get_books_id_array($book_model);
    }

}
?>