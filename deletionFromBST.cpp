#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node*& root, int d) {
    // base case
    if (root == NULL) {
        root = new Node(d);
        return root;
    }

    if (d > root->data) {
        // insert into the right subtree
        root->right = insertIntoBST(root->right, d);
    }
    else {
        // insert into the left subtree
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;

    while (data != -1) {
        insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // previous level completed
            cout << endl;

            if (!q.empty()) {
                // queue still has some child nodes
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}

Node* minVal(Node* root) {
    Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// deletion of node from BST
Node* deleteFromBST(Node* root, int val) {
    // base case
    if (root == NULL) {
        return root;
    }
    if (root->data == val) {
        // 0 child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        // right child
        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // left child
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 2 children
        if (root->left != NULL && root->right != NULL) {
            // take min from right subtree or max value from left subtree
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val) {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else {
        // root->data < val
        root->right = deleteFromBST(root->right, val);
        return root;
    }

    // Ensure the function returns root in all cases
    return root;
}

int main() {
    Node* root = NULL;
    cout << "Enter data: ";
    takeInput(root);

    levelOrderTraversal(root);

    cout << "Enter value to delete: ";
    int val;
    cin >> val;

    root = deleteFromBST(root, val);

    cout << "Level order traversal after deletion:" << endl;
    levelOrderTraversal(root);

    return 0;
}