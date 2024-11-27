//Complete "Multi-node tree" searchNode, addNode, inOrderTraversal, preOrderTraversal, postOrderTraversal, breadthFirstTraversal, DeleteNode
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node{
public:
    int value;
    Node* left;
    Node* right;
    Node* mid;

    Node(int val = 0): value(val), left(nullptr), right(nullptr), mid(nullptr){}
};

Node* root = nullptr;

Node* searchNode(int value){
    if(!root) return nullptr;
    stack<Node*>stk;
    stk.push(root);
    while(!stk.empty()){
        Node* currentNode = stk.top();
        if(currentNode->value==value) return currentNode;
        stk.pop();
        if(currentNode->right) stk.push(currentNode->right);
        if(currentNode->mid) stk.push(currentNode->mid);
        if(currentNode->left) stk.push(currentNode->left);
    }
    return nullptr;
}

void addNode(int parent, int value, int location){
    Node* parentNode = searchNode(parent);
    Node* temp = new Node(value);
    if(!root) {
        root = temp;
        return;
    }
    if(parentNode){
        if(location == 1){   //Use switch case for better readability.
            temp->left = parentNode->left;
            parentNode->left = temp;
        }
        else if(location == 2){
            temp->left = parentNode->mid;
            parentNode->mid = temp;
        }
        else if(location == 3){
            temp-> left = parentNode->right;
            parentNode->right = temp;
        }
        else{
            delete temp;
            cout<<"Invalid location."<<endl;
        }
    }
    else{
        delete temp;
    }
    return;
}

void addNode(int value){
    Node* temp = new Node(value);
    if(!root){
        root = temp;
        return;
    }
    queue<Node*>que;
    que.push(root);
    while(!que.empty()){
        Node* currentNode = que.front();
        que.pop();
        if(!currentNode->left) {
            currentNode->left = temp;
            return;
        }
        else {
            que.push(currentNode->left);
        }
        if(!currentNode->mid) {
            currentNode->mid = temp;
            return;
        }
        else {
            que.push(currentNode->mid);
        }
        if(!currentNode->right) {
            currentNode->right = temp;
            return;
        }
        else {
            que.push(currentNode->right);
        }
    }    
}

void breadthFirstTraversal(Node* start){
    if(!start) return;
    queue<Node*>que;
    que.push(start);
    while(!que.empty()){
        Node* currentNode = que.front();
        que.pop();
        cout<<currentNode->value<<" ";
        if(currentNode->left) que.push(currentNode->left);
        if(currentNode->mid) que.push(currentNode->mid);
        if(currentNode->right) que.push(currentNode->right);
    }
    cout<<endl;
    return;
}

void inOrderTraversal(Node* start){
    if(!start) return;
    stack<Node*>stk;
    stk.push(start);
    Node* lastVisitedNode = start;
    while(!stk.empty()){
        Node* currentNode = stk.top();
        stk.pop();
        if(currentNode->left != nullptr && currentNode->left != lastVisitedNode && currentNode->mid != lastVisitedNode && currentNode->right != lastVisitedNode){
            stk.push(currentNode);
            stk.push(currentNode->left);
        }
        else if(currentNode->mid != nullptr && currentNode->mid != lastVisitedNode && currentNode->right != lastVisitedNode){
            cout<<currentNode->value<<" ";
            stk.push(currentNode);
            stk.push(currentNode->mid);
        }
        else if(currentNode->right != nullptr && currentNode->right != lastVisitedNode){
            if(currentNode->mid == nullptr) cout<<currentNode->value<<" "; 
            stk.push(currentNode);
            stk.push(currentNode->right);
        }
        else if(currentNode->mid != lastVisitedNode && currentNode->right != lastVisitedNode){
            cout<<currentNode->value<<" ";
        }
        lastVisitedNode = currentNode;
    }
}

void preOrderTraversal(Node* start){
    if(!start) return;
    stack<Node*>stk;
    stk.push(start);
    Node* lastVisitedNode = start;
    while(!stk.empty()){
        Node* currentNode = stk.top();
        stk.pop();
        if(currentNode->left != nullptr && currentNode->left != lastVisitedNode && currentNode->mid != lastVisitedNode && currentNode->right != lastVisitedNode){
            cout<<currentNode->value<<" ";
            stk.push(currentNode);
            stk.push(currentNode->left);
        }
        else if(currentNode->mid != nullptr && currentNode->mid != lastVisitedNode && currentNode->right != lastVisitedNode){
            if(currentNode->left == nullptr) cout<<currentNode->value<<" ";
            stk.push(currentNode);
            stk.push(currentNode->mid);
        }
        else if(currentNode->right != nullptr && currentNode->right != lastVisitedNode){
            if(currentNode->left == nullptr && currentNode->mid == nullptr) cout<<currentNode->value<<" ";
            stk.push(currentNode);
            stk.push(currentNode->right);
        }
        else if(currentNode->left != lastVisitedNode && currentNode->mid != lastVisitedNode && currentNode->right != lastVisitedNode){
            cout<<currentNode->value<<" ";
        }
        lastVisitedNode = currentNode;
    }
}

void postOrderTraversal(Node* start){
    if(!start) return;
    stack<Node*>stk;
    stk.push(start);
    Node* lastVisitedNode = start;
    while(!stk.empty()){
        Node* currentNode = stk.top();
        stk.pop();
        if(currentNode->left != nullptr && currentNode->left != lastVisitedNode && currentNode->mid != lastVisitedNode && currentNode->right != lastVisitedNode){
            stk.push(currentNode);
            stk.push(currentNode->left);
        }
        else if(currentNode->mid != nullptr && currentNode->mid != lastVisitedNode && currentNode->right != lastVisitedNode){
            stk.push(currentNode);
            stk.push(currentNode->mid);
        }
        else if(currentNode->right != nullptr && currentNode->right != lastVisitedNode){
            stk.push(currentNode);
            stk.push(currentNode->right);
        }
        else{
            cout<<currentNode->value<<" ";
        }
        lastVisitedNode = currentNode;
    }
}

Node* find_parent(int value){
    if(!root || root->value == value) return nullptr;
    queue<Node*>que;
    que.push(root);
    while(!que.empty()){
        Node* currentNode = que.front();
        que.pop();
        if((currentNode->left && currentNode->left->value == value) || (currentNode->mid && currentNode->mid->value == value) || (currentNode->right && currentNode->right->value == value)){
            return currentNode;
        }
        else{
            if(currentNode->left) que.push(currentNode->left);
            if(currentNode->mid) que.push(currentNode->mid);
            if(currentNode->right) que.push(currentNode->right);
        }
    }
    return nullptr;
}

void deleteNode(int value){
    Node* parent = find_parent(value);
    //cout<<endl<<parent->value<<endl;
    Node* nodeToDelete = nullptr;
    
    if(!parent && root->value != value){
        cout<<"Node not found."<<endl;
        return;
    }
    if(root->value != value){ 
        if(parent->left && parent->left->value == value) nodeToDelete = parent->left;
        else if(parent->mid && parent->mid->value == value) nodeToDelete = parent->mid;
        else nodeToDelete = parent->right;
    }
    else nodeToDelete = root;

    Node* newRoot = nullptr;
    
    queue<Node*>que;
    if(nodeToDelete->left){ 
        newRoot = nodeToDelete->left;
        que.push(nodeToDelete->left);
        Node* mid_subtree = nodeToDelete->mid;
        Node* right_subtree = nodeToDelete->right;
        while(mid_subtree != nullptr || right_subtree != nullptr){
            Node* currentNode = que.front();
            que.pop(); 
            if(!currentNode->left){
                if(mid_subtree) {
                    currentNode->left = mid_subtree;
                    que.push(mid_subtree);
                    mid_subtree = nullptr;
                }
                else {
                    currentNode->left = right_subtree;
                    break;
                }
            }
            else que.push(currentNode->left);
            if(!currentNode->mid){
                if(mid_subtree) {
                    currentNode->mid = mid_subtree;
                    que.push(mid_subtree);
                    mid_subtree = nullptr;
                }
                else {
                    currentNode->mid = right_subtree;
                    break;
                }
            }
            else que.push(currentNode->mid);
            if(!currentNode->right){
                if(mid_subtree){
                    currentNode->right = mid_subtree;
                    que.push(mid_subtree);
                    mid_subtree = nullptr;
                }
                else {
                    currentNode->right = right_subtree;
                    break;
                }
            }
            else que.push(currentNode->right);
        }
    }
    else if(nodeToDelete->mid){
        newRoot = nodeToDelete->mid;
        que.push(nodeToDelete->mid);
        Node* right_subtree = nodeToDelete->right;
        while(right_subtree){
            Node* currentNode = que.front();
            que.pop();
            if(currentNode->left) que.push(currentNode->left);
            else {
                currentNode->left = right_subtree;
                break;
            }
            if(currentNode->mid) que.push(currentNode->mid);
            else {
                currentNode->mid = right_subtree;
                break;
            }
            if(currentNode->right) que.push(currentNode->right);
            else {
                currentNode->right = right_subtree;
                break;
            }
        }
    }
    else{
        newRoot = nodeToDelete->right;
    }
    
    if(nodeToDelete == root) root = newRoot;
    else if(parent->left == nodeToDelete) parent->left = newRoot;
    else if(parent->mid == nodeToDelete) parent->mid = newRoot;
    else parent->right = newRoot;
    delete nodeToDelete;
    return;
}

int main(){
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);
    addNode(6);
    addNode(7);
    addNode(8);
    addNode(9);
    addNode(10);
    addNode(11);
    addNode(12);
    addNode(13);
    deleteNode(3);
    
    cout<<"Breadth First Traversal: ";
    breadthFirstTraversal(root);
    cout<<endl<<"In Order Traversal: ";
    inOrderTraversal(root);
    cout<<endl<<"Pre Order Traversal: ";
    preOrderTraversal(root);
    cout<<endl<<"Post Order Traversal: ";
    postOrderTraversal(root);
    cout<<endl<<"End"<<endl;
    return 0;
}

