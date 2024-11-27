#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    Node* newNode = new Node(value);
    if (root == nullptr) {
        return newNode;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left == nullptr) {
            current->left = newNode;
            break;
        } else {
            q.push(current->left);
        }

        if (current->right == nullptr) {
            current->right = newNode;
            break;
        } else {
            q.push(current->right);
        }
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

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

void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        cout << current->data << " ";

        if (current->right != nullptr) {
            s.push(current->right);
        }

        if (current->left != nullptr) {
            s.push(current->left);
        }
    }
}

void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left != nullptr) {
            s1.push(current->left);
        }

        if (current->right != nullptr) {
            s1.push(current->right);
        }
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;

            case 2:
                cout << "Inorder Traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder Traversal: ";
                preorderTraversal(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder Traversal: ";
                postorderTraversal(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
