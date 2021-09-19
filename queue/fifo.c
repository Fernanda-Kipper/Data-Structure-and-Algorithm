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
};

typedef struct node node;

struct heap{
  node *first;
  node *last;
};

typedef struct heap heap;

heap *reset(){
  heap *list = (heap *)malloc(sizeof(heap));

  // 1. start the first and last with NULL, indicating the list is empty
  list->first = NULL;
  list->last = NULL;

  return list;
}

void append(heap *list, int data){
  node *new;

  //1. Allocates space for new node and save data
  new = (node *)malloc(sizeof(node));
  new->data.data = data;
  //2. Set NEXT to NULL, since will be the last element
  new->next = NULL;

  //3. If there is already elements in the list
  if(list->last != NULL){
    //3.1 Set the ex-last->next to the new node
    list->last->next = new;
  }else{
    //3.2 Set FIRST to new node because there is no element in the list
    list->first = new;
  }

  //4. Set new node as last element
  list->last = new;
}

int empty(heap *list){
  if(list->first == NULL){
    printf("Empty heap");
    return 1;
  }
  else{
    return 0;
  }
}

int pop(heap *list){
  node *top;
  int data;

  //1.If the list is not empty
  if(list->first != NULL){
    top = list->first;
    //1.1 Make the first now point to first->next
    list->first = list->first->next;
    //1.2 If it was the only element, change the last to NULL as well
    if(list->first == NULL){
      list->last == NULL;
    }

    data = top->data.data;

    //1.3 Free the ex-head
    free(top);

    //1.4 Return the value that was removed
    return data;
  }

  //2. If empty just return 0
  return 0;
}

void print(heap *list){
  if(empty(list) == 0){
    node *currentNode = list->first;

    //1. While not reach the end, keep printing the data
    while(currentNode != NULL){
      printf("\nDATA: %d ", currentNode->data.data);
      currentNode = currentNode->next;
    }
  }
}

void clear(heap *list){
  if(empty(list) == 0){
    node *currentNode = list->first;
    node *toFree;

    //1. While not reach the end, free all nodes
    while(currentNode != NULL){
      toFree = currentNode;
      currentNode = currentNode->next;
      free(toFree);
    }
    free(list);
  }
}

int menu()
{
	int chosen = 0;
	do {
		printf("\n-- MENU:\n");
		printf("\t 1. APPEND\n");
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
  heap *list;
  int data;

  list = reset();

  if(list == NULL){
    printf("\nMemory allocation problem");
    exit(-1);
  }

  while (1) {
    int chosen = menu();
    switch (chosen) {
      case 1:
        printf("Value to APPEND? ");
        scanf("%d", &data);
        append(list, data);
        break;
      case 2:
        if(empty(list) == 0){
          data = pop(list);
          printf("\nREMOVED: %d\n", data);
        }
        break;
      case 3:
        print(list);
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
