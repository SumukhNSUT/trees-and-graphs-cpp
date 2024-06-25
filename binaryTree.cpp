#include<iostream>
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

node* buildTree(node* root) {
    cout << "Enter data: " << endl;
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    node* root = new node(data);

    cout << "Enter data for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int main() {
    node* root = NULL;
    root = buildTree(root);
    cout << root->data << endl;
    return 0;
}