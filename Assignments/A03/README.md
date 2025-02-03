## A03 - BST Delete
### Jack Leary
### Description:
My (and ChatGPT's) additions to Professor Griffin's BST code to add a delete file.

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [main.cpp](https://github.com/jackleary271/2143-OOP/blob/main/Assignments/PO1/main.cpp)        | driver program for user interaction and operations |

## Cases for Deleting a Node in a Binary Search Tree

### Case 1: Deleting a Leaf Node (No Children)  
- If the node to be deleted has no left or right children, simply remove it and free its memory.
- Example:

### Case 2: Deleting a Node with One Child  
- If the node has **only one child**, the child takes the place of the deleted node.  
- Two scenarios:  
- **Left child only** → Replace node with its left child.  
- **Right child only** → Replace node with its right child.  
- Example:

### Case 3: Deleting a Node with Two Children  
- Find the **inorder successor** (smallest node in the right subtree) or **inorder predecessor** (largest node in the left subtree).  
- Replace the node’s value with that of the successor or predecessor.  
- Recursively delete the successor or predecessor.  
- Example:

  - Deleting `3`:  
  - Find the **inorder successor** (`1` or `10`).  
  - Replace `3` with `1` or `10`.  
  - Delete the chosen successor or predecessor.  
- Result:

