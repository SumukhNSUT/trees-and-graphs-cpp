// TRAVERSAL OF BINARY SEARCH TREE
// DFS AND BFS TRAVERSAL

// DFS includes preorder, inorder and postorder traversal
// BFS is also called level order traversal

/* DFS done using recursive and iterative approach and BFS also using both recursive and iterative approach, but recursive is better for DFS and iterative is better for BFS */

/* QUEUE used for iterative BFS and STACK used for iterative DFS */
// ITERATIVE - BFS (QUEUE)
// RECURSIVE - DFS

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to insert data into the BST
Node* insertBST(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insertBST(root->left, data);
    }
    else {
        root->right = insertBST(root->right, data);
    }
    return root;
}

// recursive DFS
void inorderRecursive(Node* root) {
    if (root) {
        inorderRecursive(root->left);
        cout << root->data << " ";
        inorderRecursive(root->right);
    }
}

void preorderRecursive(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void postorderRecursive(Node* root) {
    if (root) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout << root->data << " ";
    }
}

// iterative DFS
void inorderIterative(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

void preorderIterative(Node* root) {
    if (root == nullptr) return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        cout << current->data << " ";

        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
    }
}

void postorderIterative(Node* root) {
    if (root == nullptr) return;

    stack<Node*> s1, s2;
    s1.push(root);
    Node* node;

    while (!s1.empty()) {
        node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }

    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}

// iterative BFS
void bfsIterative(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

// recursive BFS
// Helper function for recursive BFS
void bfsRecursiveHelper(queue<Node*>& q) {
    if (q.empty()) return;

    Node* current = q.front();
    q.pop();
    cout << current->data << " ";

    if (current->left) q.push(current->left);
    if (current->right) q.push(current->right);

    bfsRecursiveHelper(q);
}

// Main BFS function that initializes the queue and starts the recursion
void bfsRecursive(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);
    bfsRecursiveHelper(q);
}

int main() {
    Node* root = nullptr;
    root = insertBST(root, 5);
    insertBST(root, 3);
    insertBST(root, 7);
    insertBST(root, 2);
    insertBST(root, 4);
    insertBST(root, 6);
    insertBST(root, 8);

    cout << endl;

    cout << "DFS TRAVERSAL OF BST (INORDER, PREORDER, POSTORDER):" << endl << endl;

    cout << "Inorder Traversal (Recursive): ";
    inorderRecursive(root);
    cout << endl;

    cout << "Preorder Traversal (Recursive): ";
    preorderRecursive(root);
    cout << endl;

    cout << "Postorder Traversal (Recursive): ";
    postorderRecursive(root);
    cout << endl;

    cout << "Inorder Traversal (Iterative): ";
    inorderIterative(root);
    cout << endl;

    cout << "Preorder Traversal (Iterative): ";
    preorderIterative(root);
    cout << endl;

    cout << "Postorder Traversal (Iterative): ";
    postorderIterative(root);
    cout << endl;

    cout << endl;

    cout << "BFS TRAVERSAL OF BST:" << endl << endl;

    cout << "BFS Traversal (Iterative): ";
    bfsIterative(root);
    cout << endl;

    cout << "BFS Traversal (Recursive): ";
    bfsRecursive(root);
    cout << endl << endl;

    return 0;
}