#include <iostream>
#include <limits> // For numeric limits
#define TABLE_SIZE 10
using namespace std;

class node {
private:
    int data;
    node* next;


    node(int d) {
        data = d;
        next = NULL;
    }

    int getData() { // Getter to access private 'data'
        return data;
    }

    friend class Hashing; // Allow 'Hashing' class to access private members
};

class Hashing {
    node* table[TABLE_SIZE];

public:
    Hashing() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        node* newNode = new node(key);
        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            node* temp = table[index];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "\nIndex: " << i << " : ";
            node* temp = table[i];
            while (temp != NULL) {
                cout << temp->getData() << " -> "; // Use getter to access 'data'
                temp = temp->next;
            }
            cout << "NULL";
        }
        cout << endl;
    }
};

bool isValidNumber(int& n) {
    if (cin >> n) {
        return true;
    }
    cin.clear(); // Clear the error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    return false;
}

int main() {
    Hashing ht;
    char ch;
    do {
        cout << "\nEnter 1: For Insert\nEnter 2: For Display\nEnter 3: For Exit\n";
        cin >> ch;

        switch (ch) {
        case '1': {
            int n;
            cout << "\nEnter any number: ";
            if (isValidNumber(n)) {
                ht.insert(n);
            } else {
                cout << "Invalid input! Please enter a valid number.\n";
            }
            break;
        }
        case '2':
            ht.display();
            break;
        case '3':
            break;
        default:
            cout << "\nInvalid choice! Please select a valid option.\n";
            break;
        }
    } while (ch != '3');

    return 0;
}
