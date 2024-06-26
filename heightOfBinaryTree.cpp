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

    root = new node(data);

    cout << "Enter data for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
// height of binary tree
int heightOfTree(node* root) {
    // base case
    if (root == NULL) {
        return 0;
    }
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

int main() {
    node* root = NULL;
    root = buildTree(root);
    cout << root->data << endl;

    int height = heightOfTree(root);
    cout << "Height is: " << height;
    return 0;
}