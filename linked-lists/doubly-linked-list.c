#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info{
  int data;
};

typedef struct info info;

struct node{
  info data;
  struct node *next;
  struct node *prev;
};

typedef struct node node;

struct linkedList{
  node *head;
  node *tail;
  unsigned int size;
};

typedef struct linkedList linkedList;

linkedList *reset(){
  linkedList *list = (linkedList *)malloc(sizeof(linkedList));

  // 1. start the head with NULL, indicating the list is empty
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
}

void push(linkedList *list, int data)
{
  node *head = list->head;
  // 1.allocate space for new node
  node *new_node = (node *) malloc(sizeof(node));

  // 2. put the data inside new node
  //and set its previous as NULL because it will became the head
  new_node->data.data = data;
  new_node->prev = NULL;

  //3. If its the first element to be added
  if(head == NULL){
    list->head = new_node;
    list->tail = new_node;
    new_node->next = NULL;
  }
  else{
    //4. If its not the first element
    //make prev head as new node and turn new node in head 
    // new node next is ex-head
    head->prev = new_node;
    new_node->next = head;
    list->head = new_node;
  }
  
  // 4. Increases the size of the list
  list->size += 1;
}

void printList(linkedList *list)
{
  node *current = list->head;
  // 1. Loops throught the list, while current node is not NULL
  printf("\n----- LIST -----\n");
  while (current != NULL)
  {
    // 2. Print the data inside the node
     printf(" %d ", current->data.data);
     current = current->next;
  }
}

int empty(linkedList *list){
  // 1.Checks if head is null
  if(list->head == NULL) return 1;

  // 2. If not empty, return false
  return 0;
}

int pop(linkedList *list){
  // 1. If there is none element
  if(empty(list) == 1) return 0;

  int data;
  // 2.Creates a copy of head element
  node *current = list->head;

  if(list->size == 1){
    // 3. Removes the only node of the list
    list->head = NULL;
    list->tail = NULL;
  }else{
    // 3. Removes the first element
    list->head = current->next;
    list->head->prev = NULL;
  }

  // 4. Save the current data to return
  data = current->data.data;
  
  // 5. Free the current node for no memory leak
  free(current);

  // 6. Decreases the list size
  list->size -= 1;

  return data;
}

void clear(linkedList *list){
  node *current = list->head;

  // 1. Free all elements from the list
  while(current->next != NULL){
    node *elementToDelete = current;
    current = elementToDelete->next;

    free(elementToDelete);
  }

  // 2. Free the last one
  free(current);
  
  // 3. Free the list
  free(list);
}

int menu()
{
	int chosen = 0;
	do {
		printf("-- MENU:\n");
		printf("\t 1. PUSH\n");
		printf("\t 2. POP\n");
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
  linkedList *list;
  int data;

  list = reset();

  if(list == NULL){
    printf("memory allocation problem");
    exit(-1);
  }

  while (1) {
  int chosen = menu();
  switch (chosen) {
    case 1:
      printf("Value to PUSH? ");
      scanf("%d", &data);
      push(list, data);
      break;
    case 2:
      if(empty(list) == 0){
        data = pop(list);
        printf("\nREMOVED: %d\n", data);
      }else{
        printf("Empty List");
      }
      break;
    case 3:
      printList(list);
      break;
    case 4:
      clear(list);
      list = reset();
      break;
    case 5:
      clear(list);
      exit(0);
      break;
    }
  }
  return 0;
}