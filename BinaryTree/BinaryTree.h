#ifndef __BINARY_TREE__
#define __BINARY_TREE__

typedef struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data)
        : data(data)
        , left(nullptr)
        , right(nullptr)
    {
    }
} TreeNode;

class BinaryTree {
public:
    BinaryTree() { root = nullptr; }

    void _create_tree(TreeNode** node);
    void create_tree();

    int create_a_node(TreeNode** node);
    void layer_create_tree();

    void _pre_traverse_tree(TreeNode* node);
    void pre_traverse_tree();

    void _in_traverse_tree(TreeNode* node);
    void in_traverse_tree();

    void _post_traverse_tree(TreeNode* node);
    void post_traverse_tree();

    void pre_traverse_tree_no_recursion();
    void in_traverse_tree_no_recursion();
    void post_traverse_tree_no_recursion();
    void layer_traverse_tree();

    void print_leaf_node();

    int _tree_hight(TreeNode* node);
    int tree_hight();

    int tree_hight_no_recursion();

public:
    void create_bst();
    TreeNode* _bst_find(TreeNode* node, int data);
    TreeNode* bst_find(int data);
    TreeNode* bst_find_no_recursion(int data);

    TreeNode* _bst_find_min(TreeNode* node);
    TreeNode* bst_find_min();
    TreeNode* _bst_find_max (TreeNode* node);
    TreeNode* bst_find_max();
    TreeNode* bst_find_min_no_recursion();
    TreeNode* bst_find_max_no_recursion();
    TreeNode* _bst_delete_node(TreeNode* node, int data, TreeNode** del_node);
    TreeNode* bst_delete_node(int data, TreeNode** del_node);
    TreeNode* bst_delete_node_no_recursion(int data);

private:
    TreeNode* root;
};

#endif
