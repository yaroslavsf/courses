<?php
include_once('BaseController.php');
class AuthController extends BaseController {
    public function check_for_role($email) {  
        $service = new Service();
        $user_model = new UserModel();
        $user = $service->get_user_by_email($user_model, $email);
        $row = $user->fetch_assoc();
        return $row['role'];            //admin moder user
    }

     public function register_user($reg_email, $reg_password, $firstname, $lastname, $phone_number) {
        $service = new Service();
        $user_model = new UserModel();
        $service->add_new_user($reg_email, $reg_password, $firstname, $lastname, $phone_number, $user_model);
    }

    public function check_user($email_reg) {
        $service = new Service();
        $user_model = new UserModel();
        $user = $service->get_user_by_email($user_model, $email_reg);
        if ($user->num_rows == 0){
            return false;
        } else {
            return true;
        }
    }


    public function show_auth_page() {
        $this->view->render_auth_page();
    }

    public function show_reg_page() {
        $this->view->render_reg_page();
    }
}
?>
