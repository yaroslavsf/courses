<?php

//sql connection
include("sql_connection/MySqlConnection.php");

//entities
foreach(glob("entities/*.php") as $filename) {
    include_once $filename;
}

//models
foreach(glob("models/*.php") as $filename) {
    include_once $filename;
}

class Service {    
    
    public function remove_book_from_basket($book_id, $email, $basket_model, $user_model) {
        $query_result_userId = $user_model->select(['*'], 'email', $email);
        $user_id = ($query_result_userId->fetch_assoc())['id'];

        $array_names = [`user_id`, `book_id`];
        $array_values = [$user_id, $book_id];
        $basket_model->delete($array_names, $array_values);
    }

    public function add_book_to_basket($book_id, $email, $basket_model, $user_model) {
        $query_result_userId = $user_model->select(['*'], 'email', $email);
        $user_id = ($query_result_userId->fetch_assoc())['id'];

        $array_names = [`user_id`, `book_id`];
        $array_values = [$user_id, $book_id];
        $basket_model->insert($array_names, $array_values);
    }

    public function add_new_user($reg_email, $reg_password, $firstname, $lastname, $phone_number, $user_model) {        
        $hash_pass = md5($reg_password);
        $array_names = [`email`, `password`, `firstname`, `lastname`, `phone_number`, `role`];
        $array_values = [$reg_email, $hash_pass, $firstname, $lastname, $phone_number];

        $user_model->insert($array_names, $array_values);
    }

    public function get_basket_books_by_email($email, $basket_model, $user_model, $book_model) {
        $query_result_userId = $user_model->select(['*'], 'email', $email);
        $user_id = ($query_result_userId->fetch_assoc())['id'];
        
        $books_id = [];
        $query_result_basket_books = $basket_model->select(['*'], 'user_id', $user_id);
        while($row = $query_result_basket_books->fetch_assoc()) {
            $books_id[]=  $row['book_id'];
        }
        $books = [];        
        foreach($books_id as $book_index => $book_id) {
            $query_result_book = $book_model->select(['*'], 'id', $book_id);
            $row = $query_result_book->fetch_assoc();
            $books[]= new Book($row['id'], $row['name'], $row['author'],  $row['genre_id'], $row['description']);
        }

        return $books;
    }
     
    public function get_books($book_model) {
        $query_result = $book_model->select(['*']);
        $books = [];
        while($row = $query_result->fetch_assoc()) {
            $books[]= new Book($row['id'], $row['name'], $row['author'],  $row['genre_id'], $row['description']);
        }
        return $books;
    }

    public function get_books_id_array($book_model) {
        $query_result=$book_model->select(['*']);
        $booksId = [];
        while($row = $query_result->fetch_assoc()) {
            $booksId[]= $row['id'];
        }

        return $booksId;
    }

    public function get_book_info_by_id($id,$book_model) {
        $query_result = $book_model->select(['*'], 'id', $id);
        $books = [];
        while($row = $query_result->fetch_assoc()) {
            $books[]= new Book($row['id'], $row['name'], $row['author'],  $row['genre_id'], $row['description']);
        }
        return $books[0];
    }

    public function get_user_by_model($user_model) {
        $users = [];
        $query_result  = $user_model->select(['*']);

        while($row = $query_result->fetch_assoc()) {
            $users[]= new User($row['id'], $row['firstname'], $row['lastname'], $row['phone_number'], $row['email'], $row['password']);
        }
        return $users; 
    }

    public function get_user_by_email($user_model, $email) {
        return $user_model->select(['*'],'email', $email);
        
    }

    public function get_genres($genre_model) {
        $query_result = $genre_model->select(['*']);
        $genres = [];
        while($row = $query_result->fetch_assoc()) {
            $genres[]= new Genre($row['id'],$row['name']);
        }
        return $genres;
    }

    public function add_new_book($name, $author, $genre, $desctiption, $book_model, $genre_model) {
        $genre_id = 1;
        $array_names = ['name', 'author', 'genre_id', 'description'];
        $array_values = [$name,  $author, $genre_id, $desctiption];

        $book_model->insert($array_names, $array_values);
    }
}
?>