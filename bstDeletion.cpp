#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int data) {
    if (root == nullptr) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {

        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children, get the inorder successor
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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

    // Display the original BST
    std::cout << "Original BST (Inorder Traversal): ";
    inorderTraversal(root);
    std::cout << std::endl;

    int deletionNode;

    do {
        std::cout << "Enter data of node to delete (or -1 to exit): ";
        std::cin >> deletionNode;
        if (deletionNode != -1) {
            root = deleteNode(root, deletionNode);

            // Display the updated BST
            std::cout << "Updated BST (Inorder Traversal): ";
            inorderTraversal(root);
            std::cout << std::endl;
        }
    } while (deletionNode != -1);

    return 0;
}