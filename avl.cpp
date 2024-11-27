#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int value)
    {
        data = value;
        left = right = nullptr;
        height = 0;
    }
};
Node *root = nullptr;

int getHeight(Node *temp)
{
    if (temp == nullptr)
    {
        return 0;
    }
    else
    {
        return temp->height;
    }
}

int balanceFactor(Node *temp)
{
    return getHeight(temp->left) - getHeight(temp->right);
}

Node *leftRotate(Node *temp)
{
    Node *child = temp->right;
    Node *childleft = child->left;
    child->left = temp;
    temp->right = childleft;
    temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *rightRotate(Node *temp)
{
    Node *child = temp->left;
    Node *childright = child->right;
    child->right = temp;
    temp->left = childright;
    temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

void insertNode(Node *&temp, int value)
{
    if (temp == nullptr)
    {
        temp = new Node(value);
        return;
    }
    else if (value < temp->data)
    {
        insertNode(temp->left, value);
    }
    else if (value > temp->data)
    {
        insertNode(temp->right, value);
    }
    else
    {
        cout << "Value already exists.\n";
    }

    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;

    int bf = balanceFactor(temp);

    // Perform rotations if necessary
    if (bf > 1 && value < temp->left->data)
    {
        temp = rightRotate(temp);
    }
    else if (bf < -1 && value > temp->right->data)
    {
        temp = leftRotate(temp);
    }
    else if (bf > 1 && value > temp->left->data)
    {
        temp->left = leftRotate(temp->left);
        temp = rightRotate(temp);
    }
    else if (bf < -1 && value < temp->right->data)
    {
        temp->right = rightRotate(temp->right);
        temp = leftRotate(temp);
    }
}

void inorder(Node *temp)
{
    if (temp == nullptr)
    {
        return;
    }
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

int main()
{
    int choice, value;

    while (true)
    {
        cout << "\nAVL Tree Operations Menu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Display In-order Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertNode(root, value);
            cout << "Node inserted successfully.\n";
            break;

        case 2:
            if (root == nullptr)
            {
                cout << "Tree is empty.\n";
            }
            else
            {
                cout << "In-order Traversal: ";
                inorder(root);
                cout << endl;
            }
            break;

        case 3:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
