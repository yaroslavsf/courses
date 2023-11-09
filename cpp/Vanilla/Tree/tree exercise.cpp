#include <iostream>
template <class T>
class Tree
{
private:
    struct Node
    {
        T value;
        Node* parent;
        Node* right;
        Node* left;
    };
    Node* root;
public:
    Tree() : root{ nullptr } { }
    Node* getRoot() const
    {
        return root;
    }
    void add(T value_add) //добавление узла node_add
    {
        Node* node_add = new Node;
        node_add->value = value_add;

        node_add->right = nullptr;
        node_add->left = nullptr;

        Node* future_parent = nullptr; // будущий родитель для нового элемента
        Node* node_temp = root; //переменная для обхода по дереву

        while (node_temp != nullptr)
        {
            future_parent = node_temp;
            if (node_add->value < node_temp->value)
                node_temp = node_temp->left;
            else
                node_temp = node_temp->right;
        }

        node_add->parent = future_parent;

        if (future_parent == nullptr)
            root = node_add;

        else if (node_add->value < future_parent->value)
            future_parent->left = node_add;
        else
            future_parent->right = node_add;
    }
    Node* min(Node* node) //ищет минимум от узла(параметра)
    {
        if (node != nullptr)
        {
            while (node->left != nullptr)
                node = node->left;
        }
        return node;
    }
    //мин и макс
    T min_value(Node* node) //ищет минимум от узла(параметра)
    {
        if (node != nullptr)
        {
            while (node->left != nullptr)
                node = node->left;
        }
            return node->value;
    }
    T max_value(Node* node)
    {
        if (node != nullptr)
        {
            while (node->right != nullptr)
                node = node->right;
        }
        return node->value;
    }


    //след. и пред. узлы
    Node* next(Node* node)
    {
        Node* future_next = nullptr;
        if (node != nullptr)
        {
            if (node->right != nullptr)
                return min(node->right);

            future_next = node->parent;
            while (future_next != nullptr && node == future_next->right)
            {
                node = future_next;
                future_next = future_next->parent;
            }
        }
        return future_next;
    }
    Node* prev(Node* node)
    {
        Node* future_prev = nullptr;
        if (node != nullptr)
        {
            if (node->left != nullptr)
                return min(node->left);

            future_prev = node->parent;
            while (future_prev != nullptr && node == future_prev->left)
            {
                node = future_prev;
                future_prev = future_prev->parent;
            }
        }
        return future_prev;
    }
    Node*& find(const T find_value)
    {
        Node* temp = root;
        while (temp)
        {
            if (temp->value == find_value)
            {
                return temp;
            }
            else if (temp->value > find_value)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return temp;
    }
    void delete_node(const T key)
    {

        Node* deleted_node = find(key);


        if (!deleted_node)//если элементов вообще нету
            return;

        if (deleted_node->right == nullptr && deleted_node->left == nullptr) //удаляем лист 
        {
            if (deleted_node->parent->left == deleted_node)
            {
                deleted_node->parent->left = nullptr;
            }
            else
            {
                deleted_node->parent->right = nullptr;
            }
            delete deleted_node;
        }

        else if (deleted_node->left == nullptr || deleted_node->right == nullptr)
        {
            Node* d_node_child = (deleted_node->left != nullptr) ? deleted_node->left : deleted_node->right;
            
            if (deleted_node->parent->left == deleted_node)
            {
                deleted_node->parent->left = d_node_child;
            }
            else
            {
                deleted_node->parent->right = d_node_child;
            }
            delete deleted_node;
        }
        else
        {
            Node* deleted_node_next = next(deleted_node);
            std::swap(deleted_node->value, deleted_node_next->value);
            if (deleted_node->parent->left == deleted_node_next)
            {
                deleted_node->parent->left = nullptr;
            }
            else
            {
                deleted_node->parent->right = nullptr;
            }
            delete deleted_node;
        }

    }


    void delete_tree(Node *node)//удаление всего дерева(отдельная функция нужна для рекурсии)
    {
        if (node)
        {
            delete_tree(node->left);
            delete_tree(node->right);
            delete node;
        }
    }

    void preorder_print() {
        preorder_print(root);
        std::cout << "\n";
    }
    void preorder_print(Node* leaf) {
        if (leaf != nullptr) {
            std::cout << leaf->value << ",";
            inorder_print(leaf->left);
            inorder_print(leaf->right);
        }
    }
    void inorder_print(Node* leaf) {
        if (leaf != NULL) {
            inorder_print(leaf->left);
            std::cout << leaf->value << ",";
            inorder_print(leaf->right);
        }
    }

    ~Tree()
    {
        delete_tree(root);
    }

};
int main()
{ 
    Tree<int> mas;
    mas.add(1);
    mas.add(2);
    mas.add(3);
    /*mas.preorder_print();*/
    std::cout << (mas.max_value(mas.getRoot())) << std::endl;
    mas.delete_node(3);
    std::cout << (mas.max_value(mas.getRoot()));
    /*mas.preorder_print();*/
	return 0;
}
