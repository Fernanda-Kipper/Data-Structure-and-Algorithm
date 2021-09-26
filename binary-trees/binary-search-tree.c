#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  return currentNode;
}

/* Given a tree, return the node
   with MINIMUM value value found in that tree. */
node * minValueNode(struct node* node)
{ 
    struct node* current = node;
 
    //1. Loop to found the smaller leaf in left side
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

node * delete(node *currentNode, int data)
{
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
 
    // if key is same as currentNode data,
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
 
        // Copy the successor's daata to this node
        currentNode->data = temp->data;
 
        // Deletes the successor node
        currentNode->right = delete(currentNode->right, temp->data);
    }
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
      //2. If its the first to be added, root receives the pointer of first node
      if(root == NULL){
        root = insert(root, data);
      }
      insert(root, data);
      break;
    case 2:
      if(empty(root) == 0){
        printf("\nREMOVE: ");
        scanf("%d", &data);
        delete(root, data);
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