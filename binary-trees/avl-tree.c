#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Understadings Rotate Cases
// Lets consider Z as the un-balanced node, Y child of Z, and X grandchild of Z
//a) y is left child of z and x is left child of y (Left Left Case)  - Solution: Right Rotate
// b) y is left child of z and x is right child of y (Left Right Case)  - Solution: Left Rotate + Right Rotate
// c) y is right child of z and x is right child of y (Right Right Case)  - Solution: Left Rotate
// d) y is right child of z and x is left child of y (Right Left Case) - Solution: Right Rotate + Left Rotate

struct node{
  int data;
  struct node *right;
  struct node *left;
};

typedef struct node node;

node *createNode(){
  node *new_node = (node *)malloc(sizeof(node));

  return new_node;
}

node *reset(){
  node *new_node = createNode();
  new_node->right = NULL;
  new_node->left = NULL;

  return new_node;
}

int height(node *node){
  int right, left;

  if(node == NULL){
    return 0;
  }

  right = height(node->right);
  left = height(node->left);

  if(left > right){
    return left + 1;
  }
  else {
    return right + 1;
  }
}

int balanceFactor(node * root){
  if(root == NULL){
    return 0;
  }

  return height(root->left) - height(root->right);
}

node *rightRotate(node *nodeUnbalanced){
  node *leftNode = nodeUnbalanced->left;
  node *leftRightNode = leftNode->right;

  //1. Perform rotation
  leftNode->right = nodeUnbalanced;
  nodeUnbalanced->left = leftRightNode;

  //2. Return new root
  return leftNode;
}
 
node *leftRotate(node *nodeUnbalanced){
  node *rightNode = nodeUnbalanced->right;
  node *rightLeftNode = rightNode->left;

  //1. Perform rotation
  rightNode->left = nodeUnbalanced;
  nodeUnbalanced->right = rightLeftNode;

  //2. Return new root
  return rightNode;
}

node * balanceAfterInsert(node * currentNode, int data, int balance){
  // 1. If the node is unbalanced, there are 4 cases

  // 1.1 Data inserted is greather then parent right node data, and right node height is more then 1
  if (balance < -1 && data > currentNode->right->data)
    return leftRotate(currentNode);
  // 1.2 Data inserted is less then parent left node data, and left node height is more then 1
  if (balance > 1 && data < currentNode->left->data)
    return rightRotate(currentNode);
  // 1.3 Data inserted is greather then parent left node data, and left node height is more then 1
  if (balance > 1 && data > currentNode->left->data){
      currentNode->left =  leftRotate(currentNode->left);
      return rightRotate(currentNode);
  }
  // 1.2 Data inserted is less then parent right node data, and right node height is more then 1
  if (balance < -1 && data < currentNode->right->data){
      currentNode->right = rightRotate(currentNode->right);
      return leftRotate(currentNode);
  }

  //2. No need balance
  return currentNode;
}

node * balanceAfterDelete(node * currentNode, int balance){
 // 1. If the node became unbalanced, there are 4 cases

  // Simple right rotation
  if (balance > 1 && balanceFactor(currentNode->left) >= 0)
      currentNode = rightRotate(currentNode);

  // Double rotation - left right
  if (balance > 1 && balanceFactor(currentNode->left) < 0){
    currentNode->left =  leftRotate(currentNode->left);
    currentNode = rightRotate(currentNode);
  }

  // Simple left rotation
  if (balance < -1 && balanceFactor(currentNode->right) <= 0)
      currentNode = leftRotate(currentNode);

  // Double rotation - right left
  if (balance < -1 && balanceFactor(currentNode->right) > 0){
    currentNode->right = rightRotate(currentNode->right);
    currentNode = leftRotate(currentNode);
  }

  //2. No need balance
  return currentNode;
}

node * insert(node *currentNode, int data){
  if(currentNode == NULL){
    //1. Creates the new node
    currentNode = reset();
    if(currentNode == NULL){
      printf("\n ERROR: Memory allocation problem");
      exit(-1);
    }

    //2. Set the new node data
    currentNode->data = data;
  }

  if(currentNode->data > data){
    //2. Call the insert function, that some point of the recursion will return a node 
    // And this node will be setted at the left of the current node
    currentNode->left = insert(currentNode->left, data);
  }
  else if(currentNode->data < data){
    //3. Same, but the node will be setted at the right of current node
    currentNode->right = insert(currentNode->right, data);
  }

  int balance = balanceFactor(currentNode);
  currentNode = balanceAfterInsert(currentNode, data, balance);
  return currentNode;
}

node * minValueNode(node * root){ 
  node *currentNode = root;

  //1. Loop to found the smaller leaf in left side
  while (currentNode && currentNode->left != NULL)
      currentNode = currentNode->left;

  return currentNode;
}

node * delete(node *currentNode, int data) {
  if (currentNode == NULL)
    return currentNode;

  // 1.If the data to be deleted
  // is smaller than the currentNode data
  // then it go to left subtree
  if (data < currentNode->data)
      currentNode->left = delete(currentNode->left, data);

  // 1.If the data to be deleted
  // is greather than the currentNode data
  // then it go to right subtree
  else if (data > currentNode->data)
      currentNode->right = delete(currentNode->right, data);
 
    // if data is same as currentNode data,
    // then currentNode IS THE ONE TO BE DELETED
  else if(data == currentNode->data){
    // node with only one child or no child
    if (currentNode->left == NULL) {
        node *temp = currentNode->right;
        free(currentNode);
        return temp;
    }
    else if (currentNode->right == NULL) {
        node* temp = currentNode->left;
        free(currentNode);
        return temp;
    }

    // node with two children:
    // Get successor - (smallest in the right subtree)
    node *temp = minValueNode(currentNode->right);

    // Copy the successor's data to this node
    currentNode->data = temp->data;

    // Deletes the successor node
    currentNode->right = delete(currentNode->right, temp->data);
  }

  int balance = balanceFactor(currentNode);
  currentNode = balanceAfterDelete(currentNode, balance);
  return currentNode;
}

int empty(node *root){
  if(root == NULL){
    printf("\nWARN: Empty Tree");
    return 1;
  }
  return 0;
}

void clear(node *root){
  node *currentNode = root;

  if(currentNode != NULL){
    clear(currentNode->left);
    clear(currentNode->right);
  }
  free(currentNode);

  return;
}

void print(node *root, int level){
  node *currentNode = root;

  if(currentNode != NULL){
    //1. Print the current node and all its children from left to right
    printf("\nLEVEL: %d - %d", level, currentNode->data);
    //2. All children receives it parents level plus one, that represents his depth level on the tree
    print(currentNode->left, level + 1);
    print(currentNode->right, level + 1);
  }

  return;
}

int menu()
{
	int chosen = 0;
	do {
		printf("\n-- MENU:\n");
		printf("\t 1. INSERT\n");
		printf("\t 2. REMOVE\n");
		printf("\t 3. PRINT ELEMENTS\n");
		printf("\t 4. CLEAR LIST\n");
		printf("\t 5. EXIT\n");
		printf("-- Type your choice: ");
		scanf("%d", &chosen);
	} while (chosen < 1 || chosen > 5);
	getchar();
	return chosen;
}

int main(){
  node *root;
  int data;

  //1. Start the tree with no node
  root = NULL;

  while (1) {
  int chosen = menu();
  switch (chosen) {
    case 1:
      printf("\nINSERT: ");
      scanf("%d", &data);
      root = insert(root, data);
      break;
    case 2:
      if(empty(root) == 0){
        printf("\nREMOVE: ");
        scanf("%d", &data);
        root = delete(root, data);
      }
      break;
    case 3:
      if(empty(root) == 0){
        print(root, 1);
      }
      break;
    case 4:
      clear(root);
      root = NULL;
      break;
    case 5:
      clear(root);
      exit(0);
      break;
    }
  }
  return 0;
}