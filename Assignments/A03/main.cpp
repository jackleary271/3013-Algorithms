// Comments with just the two slashes (//) signifiy changes made by me. The changes I made were to get a delete system up and running.
 // **🔴 Comments with the asterisks and red dot were made by ChatGPT. I asked ChatGPT to help me make a method that picks a random number from the tree to delete.

#include <iostream>
#include <iostream>
#include <vector> 
#include <ctime>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int x) {
    data = x;
    left = right = nullptr;
  }
};

class Bst {
private:
  Node *root;
  void _insert(Node *&sub_root, int x) {
    if (sub_root == nullptr) {
      sub_root = new Node(x);
    } else {
      if (x < sub_root->data) {
        _insert(sub_root->left, x);
      } else {
        _insert(sub_root->right, x);
      }
    }
  }

  void _print(Node *root) {
    if (!root) {
      return;
    }

    _print(root->right);
    cout << root->data << " ";
    _print(root->left);
  }

  // Helper function to find the minimum value node in a subtree
  Node* _minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
      current = current->left;
    }
    return current;
  }

  // Helper function to delete a node from the binary search tree
  Node* _delete(Node* root, int x) {
    if (root == nullptr) {
      return root;
    }

    // If the value to be deleted is smaller than the root's data, go left
    if (x < root->data) {
      root->left = _delete(root->left, x);
    }
    // If the value to be deleted is larger than the root's data, go right
    else if (x > root->data) {
      root->right = _delete(root->right, x);
    }
    // If the value to be deleted is the same as the root's data
    else {
      // Case 1: Node has no children (leaf node)
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr;
      }
      // Case 2: Node has one child
      else if (root->left == nullptr) {
        Node* temp = root->right;
        delete root;
        return temp;
      }
      else if (root->right == nullptr) {
        Node* temp = root->left;
        delete root;
        return temp;
      }
      // Case 3: Node has two children
      else {
        Node* temp = _minValueNode(root->right); // Find the inorder successor (smallest in the right subtree)
        root->data = temp->data; // Copy the inorder successor's value to this node
        root->right = _delete(root->right, temp->data); // Delete the inorder successor
      }
    }
    return root;
  }

 // **🔴 Helper function to collect all values in the tree**
  void _collectValues(Node* root, vector<int>& values) {
    if (root == nullptr) return;
    _collectValues(root->left, values);
    values.push_back(root->data);
    _collectValues(root->right, values);
  }

public:
  Bst() { root = nullptr; }
  void insert(int x) { _insert(root, x); }

  // **🔴 Method to delete a random node**
  void deleteRandomNode() {
    vector<int> values;
    _collectValues(root, values);

    if (values.empty()) {
      cout << "Tree is empty, nothing to delete.\n";
      return;
    }

    // **🔴 Seed random number generator**
    srand(time(nullptr)); 
    int randomIndex = rand() % values.size();
    int randomValue = values[randomIndex];

    cout << "Deleting random value: " << randomValue << endl;
    root = _delete(root, randomValue);
  }

  void print() { _print(root); }
};

int main() {
  std::cout << "Hello World!\n";
  Bst tree;
  tree.insert(8);
  tree.insert(3);
  tree.insert(1);
  tree.insert(11);
  tree.insert(7);
  tree.insert(15);

  tree.deleteRandomNode(); // **🔴 Delete a random node instead of a specific one**

  tree.print();
}
