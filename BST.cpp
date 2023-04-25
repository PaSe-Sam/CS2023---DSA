#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {

  if (root == NULL){ //Empty
    return;
  }

  else{
    traverseInOrder(root->left); 
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node *insertNode(struct node *root, int key) {

  if (root == NULL) { //for an empty tree
    struct node *temp = new node;
    return temp;
  }
  
  if (key < root->key) {  
    root->left = insertNode(root->left, key); //Insert recursively to the left subtree if key is less than root's key
  } 
  
  else if (key > root->key) {  
    root->right = insertNode(root->right, key); //Insert recursively to the right subtree if key is greater than root's key
  }
  
  return root;
}

//Find the minimum value node in the tree
struct node *minValNode(struct node *node) {  
  
  struct node *curr = node; 
  
  while (curr->left && curr) {
    curr = curr->left; 
  }
  
  return curr;
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {

  if (root == NULL) { //For an empty tree 
    return root;
  }
  
  if (key < root->key) { 
    root->left = deleteNode(root->left, key); //Delete recursively from the left subtree if key is less the root's key 
  } 
  
  else if (key > root->key) {
    root->right = deleteNode(root->right, key); //Delete recursively from the right subtree if key is greater than root's key 
  } 
  
  else { //Delete root node if key is equal to the root's key
    if (root->left == NULL) { 
      struct node *temp = root->right;
      delete root;
      return temp;
    } 
    
    else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }
    
    struct node *temp = minValNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);

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
