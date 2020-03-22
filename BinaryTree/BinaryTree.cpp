#include "BinaryTree.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void BinaryTree::_create_tree(TreeNode** node)
{
    int ch;
    cin >> ch;

    if (ch != -1) {
        if (!(*node)) {
            *node = new TreeNode(ch);
            (*node)->data = ch;
            (*node)->left = NULL;
            (*node)->right = NULL;
        }
        _create_tree(&(*node)->left);
        _create_tree(&(*node)->right);
    }
}

void BinaryTree::create_tree()
{
    int data;
    cin >> data;
    root = new TreeNode(data);
    _create_tree(&root);
}

int BinaryTree::create_a_node(TreeNode** node)
{
    int ch;

    if (*node) {
        return -1;
    }

    cin >> ch;
    if (ch == -2) {
        return -2;
    }
    if (ch == -1) {
        return -1;
    }

    (*node) = new TreeNode(ch);

    return 0;
}

void BinaryTree::layer_create_tree()
{
    queue<TreeNode*> q;
    TreeNode* node;
    int ret = 0;

    if (!create_a_node(&root)) {
        q.push(root);
    } else {
        return;
    }

    while (!q.empty()) {
        node = q.front();
        q.pop();

        if (!node->left) {
            if (!(ret = create_a_node(&node->left))) {
                q.push(node->left);
            } else if (ret == -2) {
                return;
            }
        }
        if (!node->right) {
            if (!(ret = create_a_node(&node->right))) {
                q.push(node->right);
            } else if (ret == -2) {
                return;
            }
        }
    }

    return;
}

void BinaryTree::_pre_traverse_tree(TreeNode* node)
{
    if (node) {
        cout << node->data << " ";
        _pre_traverse_tree(node->left);
        _pre_traverse_tree(node->right);
    }
}

void BinaryTree::pre_traverse_tree()
{
    cout << __func__ << ":" << endl;
    _pre_traverse_tree(root);
    cout << endl;
}

void BinaryTree::_in_traverse_tree(TreeNode* node)
{
    if (node) {
        _in_traverse_tree(node->left);
        cout << node->data << " ";
        _in_traverse_tree(node->right);
    }
}

void BinaryTree::in_traverse_tree()
{
    cout << __func__ << ":" << endl;
    _in_traverse_tree(root);
    cout << endl;
}

void BinaryTree::_post_traverse_tree(TreeNode* node)
{
    if (node) {
        _post_traverse_tree(node->left);
        _post_traverse_tree(node->right);
        cout << node->data << " ";
    }
}

void BinaryTree::post_traverse_tree()
{
    cout << __func__ << ":" << endl;
    _post_traverse_tree(root);
    cout << endl;
}

void BinaryTree::pre_traverse_tree_no_recursion()
{
    if (!root) {
        cout << "root is null" << endl;
        return;
    }

    stack<TreeNode*> s;
    TreeNode* node = root;

    cout << __func__ << ":" << endl;
    s.push(node);
    cout << node->data << " ";
    node = node->left;

    while (node || !s.empty()) {
        while (node) {
            cout << node->data << " ";
            s.push(node);
            node = node->left;
        }

        if (!s.empty()) {
            node = s.top();
            s.pop();
            node = node->right;
        }
    }

    cout << endl;

    return;
}

void BinaryTree::in_traverse_tree_no_recursion()
{
    if (!root) {
        cout << "root is null" << endl;
        return;
    }

    stack<TreeNode*> s;
    TreeNode* node = root;

    s.push(node);
    node = node->left;

    cout << __func__ << ":" << endl;
    while (node || !s.empty()) {
        while (node) {
            s.push(node);
            node = node->left;
        }

        if (!s.empty()) {
            node = s.top();
            cout << node->data << " ";
            s.pop();
            node = node->right;
        }
    }

    cout << endl;

    return;
}

void BinaryTree::post_traverse_tree_no_recursion()
{
    stack<TreeNode*> s;
    TreeNode* node = root;
    TreeNode* last_visit = nullptr;

    s.push(node);
    node = node->left;

    cout << __func__ << ":" << endl;
    while (node || !s.empty()) {
        while (node) {
            s.push(node);
            node = node->left;
        }

        if (!s.empty()) {
            node = s.top();
            s.pop();
            if (node->right == nullptr || node->right == last_visit) {
                cout << node->data << " ";
                last_visit = node;
                node = nullptr;
            } else {
                s.push(node);
                node = node->right;
            }
        }
    }

    cout << endl;

    return;
}

void BinaryTree::layer_traverse_tree()
{
    queue<TreeNode*> q;
    TreeNode* tmp;

    q.push(root);

    cout << __func__ << ":" << endl;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        cout << tmp->data << " ";
        if (tmp->left) {
            q.push(tmp->left);
        }
        if (tmp->right) {
            q.push(tmp->right);
        }
    }
    cout << endl;
}

void BinaryTree::print_leaf_node()
{
    queue<TreeNode*> q;
    TreeNode* tmp;

    q.push(root);

    cout << __func__ << ":" << endl;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        if (!tmp->left && !tmp->right) {
            cout << tmp->data << " ";
        }
        if (tmp->left) {
            q.push(tmp->left);
        }
        if (tmp->right) {
            q.push(tmp->right);
        }
    }
    cout << endl;
}

int BinaryTree::_tree_hight(TreeNode* node)
{
    if (!node) {
        return 0;
    }

    int left_hight = 0, right_hight = 0;

    left_hight = _tree_hight(node->left);
    right_hight = _tree_hight(node->right);

    return (left_hight > right_hight) ? left_hight + 1 : right_hight + 1;
}

int BinaryTree::tree_hight()
{
    return _tree_hight(root);
}

int BinaryTree::tree_hight_no_recursion()
{
    int hight = 0;
    queue<TreeNode*> q;
    TreeNode* tmp;

    q.push(root);

    while (!q.empty()) {
        hight++;
        for (int i = 0; i < q.size(); i++) {
            tmp = q.front();
            q.pop();
            if (tmp->left) {
                q.push(tmp->left);
            }
            if (tmp->right) {
                q.push(tmp->right);
            }
        }
    }

    return hight;
}

void BinaryTree::create_bst()
{
    TreeNode *node, *tmp = nullptr;

    if (!create_a_node(&root)) {
        node = root;
    } else {
        return;
    }

    while (1) {
        tmp = nullptr;
        if (!create_a_node(&tmp)) {
            while (node) {
                if (tmp->data > node->data) {
                    if (!node->right) {
                        node->right = tmp;
                        break;
                    } else {
                        node = node->right;
                    }
                } else {
                    if (!node->left) {
                        node->left = tmp;
                        break;
                    } else {
                        node = node->left;
                    }
                }
            }
            node = root;
        } else {
            break;
        }
    }

    return;
}

TreeNode* BinaryTree::_bst_find(TreeNode* node, int data)
{
    if (node->data > data) {
        return _bst_find(node->left, data);
    }
    if (node->data < data) {
        return _bst_find(node->right, data);
    }

    return node;
}

TreeNode* BinaryTree::bst_find(int data)
{
    return _bst_find(root, data);
}

TreeNode* BinaryTree::bst_find_no_recursion(int data)
{
    TreeNode* node = root;

    while (node) {
        if (node->data == data) {
            return node;
        } else if (node->data > data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    return NULL;
}

TreeNode* BinaryTree::_bst_find_min(TreeNode* node)
{
    if (node->left) {
        return _bst_find_min(node->left);
    }

    return node;
}

TreeNode* BinaryTree::bst_find_min()
{
    return _bst_find_min(root);
}

TreeNode* BinaryTree::_bst_find_max(TreeNode* node)
{
    if (node->right) {
        return _bst_find_max(node->right);
    }

    return node;
}

TreeNode* BinaryTree::bst_find_max()
{
    return _bst_find_max(root);
}

TreeNode* BinaryTree::bst_find_min_no_recursion()
{
    TreeNode* node = root;

    while (node->left) {
        node = node->left;
    }

    return node;
}

TreeNode* BinaryTree::bst_find_max_no_recursion()
{
    TreeNode* node = root;

    while (node->right) {
        node = node->right;
    }

    return node;
}

TreeNode* BinaryTree::_bst_delete_node(TreeNode* node, int data, TreeNode** del_node)
{
    TreeNode *tmp = NULL;

    if (!node) {
        cout << "Not find the node of " << data << endl;
    } else if (node->data > data) {
        node->left = _bst_delete_node(node->left, data, del_node);
    } else if (node->data < data) {
        node->right = _bst_delete_node(node->right, data, del_node);
    } else {
        if (node->left && node->right) {
            tmp = _bst_find_min(node->right);
            node->data = tmp->data;
            node->right = _bst_delete_node(node->right, node->data, del_node);
        } else {
            tmp = node;
            if (!node->left) {
                node = node->left;
            } else if (!node->right){
                node = node->right;
            }
            *del_node = tmp;
        }
    }

    return node;
}

TreeNode* BinaryTree::bst_delete_node(int data, TreeNode** del_node)
{
    return _bst_delete_node(root, data, del_node);
}

TreeNode* BinaryTree::bst_delete_node_no_recursion(int data)
{
    TreeNode* node = root;
    TreeNode* parent_node = root;
    int left = 0;

    while (node) {
        if (node->data == data) {
            if (!node->left && !node->right) {
                if (left) {
                    parent_node->left = NULL;
                } else {
                    parent_node->right = NULL;
                }
            } else if (!node->left) {
                if (left) {
                    parent_node->left = node->right;
                } else {
                    parent_node->right = node->right;
                }
            } else if (!node->right) {
                if (left) {
                    parent_node->left = node->left;
                } else {
                    parent_node->right = node->left;
                }
            } else {
                TreeNode* min = node->right;
                while (min->left && min->left->left) {
                    min = min->left;
                }
                if (!min->left) {
                    node->data = min->data;
                    node->right = min->right;
                    node = min;
                } else if (min->left->left) {
                    node->data = min->left->data;
                    min->left = min->left->right;
                    node = min->left;
                }
            }
            break;
        } else if (node->data > data) {
            left = 1;
            parent_node = node;
            node = node->left;
        } else {
            left = 0;
            parent_node = node;
            node = node->right;
        }
    }

    if (!node) {
        cout << "Not find the node of " << data << endl;
    }

    return node;
}