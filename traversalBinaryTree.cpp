#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* right;
    node* left;

    node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build tree
node* buildTree(node* root) {
    cout << "Enter data:" << endl;
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new node(data);

    cout << "Enter data for inserting in left of " << data << ":" << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << ":" << endl;
    root->right = buildTree(root->right);

    return root;
}

// Inorder traversal (left, root, right)
void inorder(node* root) {
    // Base case
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder traversal (root, left, right)
void preorder(node* root) {
    // Base case
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal (left, right, root)
void postorder(node* root) {
    // Base case
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    node* root = NULL;
    root = buildTree(root);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}