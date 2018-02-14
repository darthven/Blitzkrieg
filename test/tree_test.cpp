#include "../src/darthtree.h"

int main() {


    DarthBinarySearchTree<int> tree;

    tree.insert(5);
    tree.insert(5);
    tree.insert(5);
    tree.insert(2);
    tree.insert(20);
    tree.insert(-5);
    tree.insert(-3);
    tree.insert(10);
    tree.insert(8);      
    tree.insert(12);
    tree.insert(12);
    tree.insert(12);
    tree.insert(30); 
    tree.insert(30);  
    tree.insert(30); 
    tree.insert(25);
    tree.insert(35);    

    tree.print_values();

    std::cout << "Nodes' count: " << tree.get_node_count() << std::endl;
    std::cout << "Is in tree 35: " << tree.is_in_tree(35) << std::endl;
    std::cout << "Is in tree 28: " << tree.is_in_tree(28) << std::endl;
    std::cout << "Duplicates count of node `30`: " << tree.search(30)->duplicates << std::endl;
    std::cout << "Max: " << tree.get_max() << std::endl;
    std::cout << "Min: " << tree.get_min() << std::endl;
    std::cout << "Is leaf 5: " << tree.is_leaf(tree.search(5)) << std::endl;
    std::cout << "Is leaf 35: " << tree.is_leaf(tree.search(35)) << std::endl;

    std::cout << "Depth 5: " << tree.get_depth(5) << std::endl;
    std::cout << "Depth 35: " << tree.get_depth(35) << std::endl;
    std::cout << "Depth 30: " << tree.get_depth(30) << std::endl;
    std::cout << "Level 5: " << tree.get_level(5) << std::endl;
    std::cout << "Level 35: " << tree.get_level(35) << std::endl;
    std::cout << "Level 30: " << tree.get_level(30) << std::endl;    

    std::cout << "Height 5: " << tree.get_height(5) << std::endl;
    std::cout << "Height 35: " << tree.get_height(35) << std::endl;
    std::cout << "Height 30: " << tree.get_height(30) << std::endl;    
    std::cout << "Tree height: " << tree.get_tree_height() << std::endl;    
    std::cout << "Parent of -5: " << tree.search(-5)->parent->value << std::endl;  

    tree.remove(-5);      
    tree.remove(30);    
    tree.remove(25);  
    tree.remove(8); 
    tree.remove(12);  
    tree.remove(-3);  
    tree.remove(30);  
    tree.remove(30); 
    tree.print_values();



    return 0;
}