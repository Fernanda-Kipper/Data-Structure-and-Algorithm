#include <stdio.h>
#include <stdlib.h>

struct Data {
  int data;
};

typedef struct Data Data;

struct stack {
  Data *dataList;
  Data *top;
  Data *bottom;
  int limit;
};

typedef struct stack stack;

void reset(stack *stack){
  stack->bottom = NULL;
  stack->top = NULL;
  stack->dataList = NULL;
  stack->limit = 0;
}

void clear(stack *stack){
  free(stack->dataList);
  reset(stack);
}

int empty(stack *stack){
  if(stack->top == NULL){
    return 1;
  }
  return 0;
}

int full(stack *stack){
  Data *data;
  stack->limit++;
  if((stack->dataList = realloc(stack->dataList, sizeof(Data) * stack->limit)) == NULL){
    printf("Não foi possível alocar memória");
    stack->limit--;
    return 1;
  }
  return 0;
}

void push(stack *stack, Data *includeData){
  if(full(stack) == 0){
    stack->dataList[stack->limit - 1] = *includeData;
    stack->top = &stack->dataList[stack->limit - 1];
    stack->bottom = stack->dataList;

    return;
  }
  return;
}

void list(stack *stack){
  int cont = 0;
  for(; cont < stack->limit; cont++){
    printf("\nData[%d] = %d", cont + 1, stack->dataList[cont]);
  }
}

void pop(stack *stack, Data *popData){
  if(empty(stack) == 1)
    popData->data = NULL;
    return;

  popData = stack->top;
  stack->limit--;

  if(stack->limit <= 0){
    free(stack->dataList);
    reset(stack);
    return;
  }

  stack->top = &stack->dataList[stack->limit - 1];
  stack->bottom = stack->dataList;
  stack->dataList = realloc(stack->dataList, sizeof(Data) * stack->limit);

  return;
}

stack *initialize(){
  stack *stack;
  reset(stack);
  stack->dataList = malloc(sizeof(Data) * stack->limit);
  return stack;
}

int menu()
{
	int chosen = 0;
	do {
		printf("-- MENU:\n");
		printf("\t 1. Inserir na pilha\n");
		printf("\t 2. Excluir ultimo valor da pilha\n");
		printf("\t 3. Listar elementos da pilha\n");
		printf("\t 4. Limpa a pilha\n");
		printf("\t 5. Sair\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &chosen);
	} while (chosen < 1 || chosen > 5);
	getchar();
	return chosen;
}

int main(){
  stack *stack = initialize();
  int chosen = 0;
  Data *dataToManipulate = malloc(sizeof(Data));

  while (1) {
    chosen = menu();
    switch (chosen) {
      case 1:
        printf("Adicionar qual valor? ");
        scanf("%d", &dataToManipulate->data);
        push(stack, dataToManipulate);
        break;
      case 2:
        pop(stack, dataToManipulate);
        if(dataToManipulate->data != NULL){
          printf("Valor removido: %d \n", dataToManipulate->data);
        }else{
          printf("Lista vazia");
        }
        break;
      case 3:
        list(stack);
        break;
      case 4:
        clear(stack);
        break;
      case 5:
        clear(stack);
        exit(0);
        break;
    }
  }
  return 0;
}