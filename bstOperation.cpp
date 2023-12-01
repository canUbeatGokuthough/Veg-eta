#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if(root == nullptr) {
        return new Node(data);
    }
    if(data < root->data) {
        root->left = insert(root->left, data);
    }  
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

int height(Node* root) {
    if(root== nullptr) {
        return -1;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return 1 + max(leftheight,rightheight);
}

int countNode(Node* root) {
    if (root == nullptr){
        return 0;
    } 
    return 1+ countNode(root->left) + countNode(root->right);
}

int countLeafNode(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return countLeafNode(root->left) + countLeafNode(root->right);
}

Node* findMin(Node* root) {
    if(root==nullptr) {
        return nullptr;
    }
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
    
}

Node* findMax(Node* root) {
    if(root==nullptr) {
        return NULL;
    }
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

void printLeafNodes(Node* root) {
    if(root==nullptr) {
        return;
    }
    if( root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
        return;
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void printLevelOrder(Node* root) {
    if(root==nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left != nullptr) {
            q.push(temp->left);
        }

        if (temp->right != nullptr) {
            q.push(temp->right);
        }
    }
}

Node* mirrorImage(Node* root) {
    if(root == nullptr) {
        return nullptr;
    }
    Node* temp = root->left;
    root->left = mirrorImage(root->right);
    root->right = mirrorImage(temp);

    return root;
}

int main() {
    Node* root = nullptr;
    int choice;

    do
    {
        cout << "Enter an element to insert(-1 to exit) : ";
        cin >> choice;
        if(choice!=-1) {
            root = insert(root, choice);
        }

    } while (choice!=-1);

    cout << endl;

    cout << "Height of the binary Tree : " << height(root) << endl;
    cout << "Total no. of nodes in BST : " << countNode(root) << endl;
    cout << "Total no. of  leaf  Nodes : " << countLeafNode(root) << endl;
    cout << "Minimum value node in BST : " << findMin(root)->data << endl;
    cout << "Maximum value node in BST : " << findMax(root)->data << endl;

    cout << "Leaf  nodes  in  the  BST : ";
    printLeafNodes(root);
    cout << endl;

    cout << "Print levelwise Nodes in  : ";
    printLevelOrder(root);
    cout << endl;

    root = mirrorImage(root);
    cout << "Mirror image of the BST (nodes level wise): ";

    printLevelOrder(root);
    cout << endl;

    return 0;   
}