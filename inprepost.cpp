void inorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
        
    stack<Node *> s;
    Node *temp = root;

    while (temp != nullptr)
    {
        s.push(temp);
        temp = temp->left;
    }
    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        cout << temp->data << " ";
        temp = temp->right;

        while (temp != nullptr) {            
            s.push(temp);
            temp = temp->left;
        }
    }
}


// PRE


void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        std::cout << current->data << " ";

        if (current->right) {
            s.push(current->right);
        }
        if (current->left) {
            s.push(current->left);
        }
    }
}


//POST


void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::stack<Node*> s;
    std::stack<Node*> output;
    s.push(root);
    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        output.push(current);

        if (current->left) {
            s.push(current->left);
        }
        if (current->right) {
            s.push(current->right);
        }
    }
    while (!output.empty()) {
        Node* current = output.top();
        output.pop();
        std::cout << current->data << " ";
    }
}



