#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root) {
    cout << "Enter data: ";
    int data;
    cin >> data;

    root = new node(data);
    if (data == -1) {
        return NULL;
    }
    cout << "Enter data for left: ";
    root->left = buildTree(root->left);

    cout << "Enter data for right: ";
    root->right = buildTree(root->right);

    return root;
}

int main() {
    node* root = NULL;
    root = buildTree(root);
    return 0;
}