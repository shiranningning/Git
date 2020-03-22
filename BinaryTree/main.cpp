#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
    BinaryTree bt;
    TreeNode* node;

    //create_tree(&root);
    //bt.layer_create_tree();

    int data;
    bt.create_bst();

   /*
    cin >> data;
    cout << bt.bst_find(data)->data << endl;
    cout << bt.bst_find_no_recursion(data)->data << endl;
    cout << bt.bst_find_min()->data << endl;
    cout << bt.bst_find_max()->data << endl;
    cout << bt.bst_find_min_no_recursion()->data << endl;
    cout << bt.bst_find_max_no_recursion()->data << endl;
    */

    bt.pre_traverse_tree();
    bt.pre_traverse_tree_no_recursion();

    bt.in_traverse_tree();
    bt.in_traverse_tree_no_recursion();

    bt.post_traverse_tree();
    bt.post_traverse_tree_no_recursion();

    bt.layer_traverse_tree();

    bt.print_leaf_node();

    cout << bt.tree_hight() << endl;
    cout << bt.tree_hight_no_recursion() << endl;

    cin >> data;
    node = bt.bst_delete_node_no_recursion(data);
    cout << node->data << endl;
    bt.in_traverse_tree();

    cin >> data;
    bt.bst_delete_node(data, &node);
    cout << node->data << endl;
    bt.in_traverse_tree();

    delete node;

    return 0;
}