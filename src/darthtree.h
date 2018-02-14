#include <iostream> 
#include <iomanip>

template<class T>
class DarthNode {     
    public:
        T value; 
        DarthNode<T> *parent;
        DarthNode<T> *right;
        DarthNode<T> *left;  
        int duplicates;
        DarthNode<T>(T value);
        ~DarthNode<T>();                   
};

template<class T>
class DarthBinarySearchTree {
    private:
        DarthNode<T> *root;   
        int children_count(DarthNode<T> *node);
        bool node_exists(T value, DarthNode<T> *node);      
        void print_node(DarthNode<T> *node, int indent = 0);
        void remove_leaf(DarthNode<T> *node);
        void remove_node_with_single_child(DarthNode<T> *node);
        void remove_node(DarthNode<T> *node);
        void insert_node(T value, DarthNode<T> *node);     
        DarthNode<T>* get_max_node(DarthNode<T> *node);
        DarthNode<T>* get_min_node(DarthNode<T> *node);
        DarthNode<T>* get_node(T value, DarthNode<T> *node);
        int get_depth_node(T value, DarthNode<T> *node);
        int get_height_node(DarthNode<T> *node);        
    public:   
        DarthBinarySearchTree<T>();
        ~DarthBinarySearchTree<T>();  
        int get_node_count();
        void print_values();
        void delete_tree();
        bool is_leaf(DarthNode<T> *node);
        bool is_in_tree(T value);
        int get_height(T value);  
        int get_tree_height();     
        int get_depth(T value);
        int get_level(T value);
        T get_min();
        T get_max();
        bool is_binary_search_tree();
        T get_successor(T value);
        void insert(T value);
        void remove(T value);
        DarthNode<T>* search(T value);     
};

template<typename T>
DarthNode<T>::DarthNode(T value) {
    this->value = value;
    this->duplicates = 0;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template<typename T>
DarthNode<T>::~DarthNode() {
    delete this->left;
    delete this->right;
}

template<typename T>
DarthBinarySearchTree<T>::DarthBinarySearchTree() {
    this->root = nullptr;
}

template<typename T>
DarthBinarySearchTree<T>::~DarthBinarySearchTree() {
    delete this->root;
}    

template<typename T>
int DarthBinarySearchTree<T>::children_count(DarthNode<T> *node) {
    int children_count = 0;
    if(node->left != nullptr) {
        children_count += node->left->duplicates + this->children_count(node->left) + 1;
    }
    if(node->right != nullptr) {        
        children_count += node->right->duplicates + this->children_count(node->right) + 1;
    }
    return children_count;
}      

template<typename T>
int DarthBinarySearchTree<T>::get_node_count() {    
    return this->children_count(this->root) + this->root->duplicates + 1;
}  

template<typename T>
bool DarthBinarySearchTree<T>::is_leaf(DarthNode<T> *node) {
    return node != nullptr && node->left == nullptr && node->right == nullptr;
}

template<typename T>
DarthNode<T>* DarthBinarySearchTree<T>::get_node(T value, DarthNode<T> *node) {
    if(node->value > value) {
        return this->get_node(value, node->left);
    } else if(node->value < value) {
        return this->get_node(value, node->right); 
    }
    return node;   
}

template<typename T>
DarthNode<T>* DarthBinarySearchTree<T>::search(T value) {
    return this->get_node(value, this->root);
}

template<typename T>
DarthNode<T> * DarthBinarySearchTree<T>::get_max_node(DarthNode<T> *node) {   
    if(node != nullptr) {
        if(node->right != nullptr) {
            return get_max_node(node->right);
        } else {
            return node;
        }
    }    
    return nullptr;
}

template<typename T>
T DarthBinarySearchTree<T>::get_max() {    
    return this->get_max_node(this->root)->value;
}


template<typename T>
DarthNode<T> * DarthBinarySearchTree<T>::get_min_node(DarthNode<T> *node) {    
    if(node != nullptr) {
        if(node->left != nullptr) {
            return get_min_node(node->left);
        } else {
            return node;
        }
    }    
    return nullptr;
}

template<typename T>
T DarthBinarySearchTree<T>::get_min() {
    return this->get_min_node(this->root)->value;
}

template<typename T>
int DarthBinarySearchTree<T>::get_height_node(DarthNode<T> *node) {
    if(node != nullptr && !this->is_leaf(node)) {
       int height = 1;
       int left = get_height_node(node->left);
       int right = get_height_node(node->right);
       if(left > right) {
            return height + left;
       } else {
            return height + right;
       }      
    } 
    return 0;
}

template<typename T>
int DarthBinarySearchTree<T>::get_height(T value) {
    return this->get_height_node(this->search(value)); 
}

template<typename T>
int DarthBinarySearchTree<T>::get_tree_height() {
    return this->get_height(this->root->value); 
}


template<typename T>
int DarthBinarySearchTree<T>::get_depth_node(T value, DarthNode<T> *node) {   
    if(!this->is_leaf(this->search(value))) {
        int depth = 0;  
        if(node->value > value) {           
            depth++;        
            return depth + this->get_depth_node(value, node->left); 
        } else if(node->value < value) {
            depth++;       
            return depth + this->get_depth_node(value, node->right);  
        } else {
            return depth;
        }
    }   
    return -1;
}

template<typename T>
int DarthBinarySearchTree<T>::get_depth(T value) {
    return this->get_depth_node(value, this->root);
}

template<typename T>
int DarthBinarySearchTree<T>::get_level(T value) {
    return this->get_depth(value) + 1;
}

template<typename T>
bool DarthBinarySearchTree<T>::node_exists(T value, DarthNode<T> *node) {   
    if(node != nullptr) {
        if(node->value == value) {
            return true;
        } else {
            return this->node_exists(value, node->left) || this->node_exists(value, node->right);
        }
    }
    return false;
}

template<typename T>
bool DarthBinarySearchTree<T>::is_in_tree(T value) {   
    return this->node_exists(value, this->root);
}      
    

template<typename T>
void DarthBinarySearchTree<T>::insert_node(T value, DarthNode<T> *node) {
    if(node->value > value) {
        if(node->left == nullptr) {            
            node->left = new DarthNode<T>(value);
            node->left->parent = node;
        } else {
            this->insert_node(value, node->left);
        }        
    } else if(node->value < value) {
        if(node->right == nullptr) {
            node->right = new DarthNode<T>(value);
            node->right->parent = node;
        } else {
            this->insert_node(value, node->right);
        }           
    } else {      
        node->duplicates++;
    }    
}

template<typename T>
void DarthBinarySearchTree<T>::insert(T value) {
    if(this->root == nullptr) {
        this->root = new DarthNode<T>(value);
        this->root->parent = nullptr;
        this->root->left = nullptr;
        this->root->right = nullptr;
    } else {
        this->insert_node(value, this->root);
    }
}

template<typename T>
void DarthBinarySearchTree<T>::remove_leaf(DarthNode<T> *node) {
    DarthNode<T> *parent = node->parent;  
    if(parent->left == node) {
        parent->left = nullptr;       
    } else {
        parent->right = nullptr;
    }
    node = nullptr;
}

template<typename T>
void DarthBinarySearchTree<T>::remove_node_with_single_child(DarthNode<T> *node) {
    DarthNode<T> *parent = node->parent;  
    if(parent->left == node) {       
        if(node->right != nullptr) {
            node->right->parent = parent;
            parent->left = node->right;
        } else {
            node->left->parent = parent;
            parent->left = node->left;
        }      
    } else {      
        if(node->right != nullptr) {
            node->right->parent = parent;
            parent->right = node->right;
        } else {
            node->left->parent = parent;
            parent->right = node->left;
        }          
    }     
    node = nullptr;
}

template<typename T>
void DarthBinarySearchTree<T>::remove_node(DarthNode<T> *node) {
    DarthNode<T> *parent = node->parent;  
    if(parent->left == node) {       
        DarthNode<T> *min = this->get_min_node(node->right);
        std::cout << "Min: " << min->value << std::endl;
        // parent->left = min;
        // min->parent = parent;
        // min->left = node->left;
        // min->right = node->right;               
    } else {      
        DarthNode<T> *max = this->get_max_node(node->left);  
        std::cout << "Max: " << max->value << std::endl;
        parent->right = max;
        max->parent = parent;
        // max->left = node->left;
        max->right = node->right;        
    }     
    node = nullptr;
}

template<typename T>
void DarthBinarySearchTree<T>::remove(T value) {
    DarthNode<T> *node = this->search(value); 
    if(node != nullptr) {
        if(node->duplicates >= 1) {
            node->duplicates--;
        } else if(this->is_leaf(node)) {          
            this->remove_leaf(node);        
        } else if(node->left == nullptr ^ node->right == nullptr) {
            this->remove_node_with_single_child(node);           
        } else {
            this->remove_node(node);
        }
    }
}

template<typename T>
void DarthBinarySearchTree<T>::print_node(DarthNode<T> *node, int indent) {
    if(node != nullptr) {      
        std::cout << std::setw(indent) << ' ';
        std::cout << "(" << node->value << ", " << (node->duplicates) << ")" << std::endl;    
        if(node->left != nullptr) {                         
            print_node(node->left, indent + 4);
        }
        if(node->right != nullptr) {                  
            print_node(node->right,  indent + 4);
        }                         
    }  
}

template<typename T>
void DarthBinarySearchTree<T>::print_values() {      
    this->print_node(this->root);
}
