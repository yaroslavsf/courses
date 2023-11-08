<?php
include_once('ModerController.php');
class AdminController extends ModerController {
    public function show_users_admin_page($role) {
        $user_model = new UserModel();
        $service = new Service();
        
        $users = $service->get_user_by_model($user_model);
        $this->view->render_user_admin_page($users, $role);
    }
}
?>