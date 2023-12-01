#include <iostream>
#include <algorithm>

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int data) {
    if (root == nullptr)
        return new Node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;
    

    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void updateHeight(Node* root) {
    if (root == nullptr)
        return;

    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

    updateHeight(root->left);
    updateHeight(root->right);
}

void verifyBalanceFactor(Node* root) {
    if (root == nullptr)
        return;

    int balance = getBalanceFactor(root);

    std::cout << "Balance Factor for Node with data " << root->data << ": " << balance << std::endl;

    verifyBalanceFactor(root->left);
    verifyBalanceFactor(root->right);
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    int choice;
    do {
        std::cout << "Enter an element to insert (or -1 to exit): ";
        std::cin >> choice;
        if (choice != -1) {
            root = insert(root, choice);
        }
    } while (choice != -1);

    updateHeight(root);

    verifyBalanceFactor(root);

    std::cout << "In-order Traversal of AVL Tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
