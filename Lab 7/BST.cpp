#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

node* findMin(node* root){
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root; 
}

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == nullptr){
    return;
  }
  else{
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
    return;
  }
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
    if (root == nullptr){
        root = new node;
        root->key = key;
        root->left = nullptr;
        root->right = nullptr; 
    }
    if (key < root->key){
        root->left = insertNode(root->left, key);
    }
    else if (key > root->key){
        root->right = insertNode(root->right, key);
    }
    return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == nullptr){
        return root;
    }
    else if (key < root->key){
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key){
        root->right = deleteNode(root->right, key);
    }
    else{
        // Case - 1 : No leaves
        if (root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
        }

        // Case - 2 : Only one leaf
        else if (root->left == nullptr){
            node * temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr){
            node * temp = root;
            root = root->left;
            delete temp;
        }

        // Case - 3 : Has two leaves
        else{
            node * temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}