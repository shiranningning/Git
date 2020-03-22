#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

void create_tree(TreeNode** node)
{
    char ch;
    cin >> ch;

    if (ch != '#') {
        *node = new TreeNode;
        (*node)->data = ch;
        (*node)->left = NULL;
        (*node)->right = NULL;
        create_tree(&(*node)->left);
        create_tree(&(*node)->right);
    }
}

int create_a_node(TreeNode** node)
{
    char data;

    cin >> data;

    if (data == '#') {
        return -1;
    }

    (*node) = new TreeNode;
    (*node)->data = data;
    (*node)->left = nullptr;
    (*node)->right = nullptr;

    return 0;
}

void layer_create_tree(TreeNode** root)
{
    queue<TreeNode*> q;
    TreeNode* node;
    int ret = 0;

    if (!create_a_node(root)) {
        q.push(*root);
    } else {
        return;
    }

    while (!q.empty()) {
        node = q.front();
        q.pop();

        if (!node->left) {
            if (!create_a_node(&node->left)) {
                q.push(node->left);
            }
        }
        if (!node->right) {
            if (!create_a_node(&node->right)) {
                q.push(node->right);
            }
        }
    }

    return;
}

void pre_traverse_tree(TreeNode* root)
{
    if (root) {
        cout << root->data << " ";
        pre_traverse_tree(root->left);
        pre_traverse_tree(root->right);
    }
}

void in_traverse_tree(TreeNode* root)
{
    if (root) {
        in_traverse_tree(root->left);
        cout << root->data << " ";
        in_traverse_tree(root->right);
    }
}

void post_traverse_tree(TreeNode* root)
{
    if (root) {
        post_traverse_tree(root->left);
        post_traverse_tree(root->right);
        cout << root->data << " ";
    }
}

void pre_traverse_tree_no_recursion(TreeNode* root)
{
    if (!root) {
        return;
    }

    stack<TreeNode*> s;
    TreeNode* node = root;

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

void in_traverse_tree_no_recursion(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* node = root;

    s.push(node);
    node = node->left;

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

void post_traverse_tree_no_recursion(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* node = root;
    TreeNode* last_visit = nullptr;

    s.push(node);
    node = node->left;

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

void layer_traverse_tree(TreeNode* root)
{
    queue<TreeNode*> q;
    TreeNode* tmp;

    q.push(root);

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

void print_leaf_node(TreeNode* root)
{
    queue<TreeNode*> q;
    TreeNode* tmp;

    q.push(root);

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

int tree_hight(TreeNode* root)
{
    if (!root) {
        return 0;
    }

    int left_hight = 0, right_hight = 0;

    left_hight = tree_hight(root->left);
    right_hight = tree_hight(root->right);

    return (left_hight > right_hight) ? left_hight + 1 : right_hight + 1;
}

int main1()
{
    TreeNode* root;

    //create_tree(&root);
    layer_create_tree(&root);

    pre_traverse_tree(root);
    cout << endl;
    pre_traverse_tree_no_recursion(root);

    in_traverse_tree(root);
    cout << endl;
    in_traverse_tree_no_recursion(root);

    post_traverse_tree(root);
    cout << endl;
    post_traverse_tree_no_recursion(root);

    print_leaf_node(root);

    //    layer_traverse_tree(root);

    cout << tree_hight(root) << endl;

    return 0;
}

#pragma pack(1)
struct test {
    char a;
    int b;
    int c;
    short d;
};

int main2()
{
    cout << sizeof(test) << endl;

    return 0;
}

class A {
public:
    A()
    {
        cout << "A" << endl;
        print();
    }
    virtual ~A()
    {
        cout << "A d" << endl;
    }
    virtual void print()
    {
        cout << "A called" << endl;
    }
};

class B : public A {
public:
    B()
    {
        cout << "B" << endl;
        print();
    }
    virtual ~B()
    {
        cout << "B d" << endl;
    }

    virtual void print()
    {
        cout << "B called" << endl;
    }
};

int main()
{
    A* pa = new B();
    delete pa;
    return 0;
}