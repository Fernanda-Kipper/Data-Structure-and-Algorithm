# Data Structure Binary Trees

## Type: Hierarchy
We can remove a node at any position, but **we cannot at a node in any position**

## Basic Operations
- INSERT - Given a tree and a data, inserts the data at right place, respecting **small on left and greater on right** order
- DELETE - Given a tree and a data, deletes the node with this data and returns the new root
- CLEAR - Given a tree, deletes all the nodes
- EMPTY - Given the root node, check if its null or not
- PRINT PRE-ORDER - Given a tree, print all nodes data (printing the current node data and all his children from left to right, in a recursive way)
- SEARCH - Given a tree and a data, search for the node with this given data

## Dictionary
- LEAF - Last node of a branch
- BRANCH - Subtree inside a tree
- ROOT - First element of a tree
- NODE - One element of a tree
- DEPTH - Distance between a given node and the root
- CHILD - Node that is on the left or right branch of the parent node, one level below 

## Binary Search Tree
" The nodes are arranged in a binary search tree according to the following properties:

- The left subtree of a particular node will always contain nodes with keys less than that node’s key.

- The right subtree of a particular node will always contain nodes with keys greater than that node’s key.

- The left and the right subtree of a particular node will also, in turn, be binary search trees."

<p align="center"><img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/Diagram1.png" width="400px"/></p>

## Complexity

### Search

#### Being N the height of a tree

Case | Complexity | Explanation | When happens
--- | --- | --- | --- |
Worst |  **O(n)** | Function will need to pass all level of tree to find the node | When the node searched is the leaf of a branch
Best | **O(log2n) + 1** | Function will stop in some level of the tree (n/2 if is the in middle, n/2/2 if is the middle of middle...)| When the node searched is not the leaf