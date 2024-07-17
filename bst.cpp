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
        // right part mein insert krna hai
        root->right = insertIntoBST(root->right, d);
    }
    else {
        // left part mein insert krna hai
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
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // purana level complete traverse ho chuka hai
            cout << endl;

            if (!q.empty()) {
                // queue still has some child
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left != NULL) {
                q.push(temp->left);
            }if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    Node* root = NULL;
    cout << "Enter data: ";
    takeInput(root);

    levelOrderTraversal(root);

    return 0;
}