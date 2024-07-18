#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        // Traverse the left subtree
        inorderTraversal(root->left);

        // Visit the root node
        cout << root->val << " ";

        // Traverse the right subtree
        inorderTraversal(root->right);
    }
};

int main() {
    // Create a simple binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    BinaryTree tree;
    tree.inorderTraversal(root);

    // Clean up the allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}