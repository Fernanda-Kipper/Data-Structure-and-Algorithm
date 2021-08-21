#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
  char name[10];
  int age;
  unsigned long int phone;
  struct person *next;
};

typedef struct person person;
void insertPerson(person *pBuffer);
void removePerson(person *pBuffer);
void listAllPeople(person *pBuffer);
int menu(void);
person* createsList();

person *createsList(){
  person *begin;

  if ((begin = (person *)malloc(sizeof(person))) == NULL) {
		printf("Não foi possível alocar memória\n");
		exit(1);
	}

	begin->next = NULL;
  return begin;
};

int main()
{
	int chosen;
  person *pBuffer = createsList();

	for (;;) {
		chosen = menu();
		switch (chosen) {
		case 1:
			insertPerson(pBuffer);
			break;
		case 2:
			removePerson(pBuffer);
			break;
		case 3:
			listAllPeople(pBuffer);
			break;
		case 4:
			free(pBuffer);
			exit(0);
			break;
		}
	}
	return 0;
}

int menu(void)
{
	int c = 0;
	do {
		printf("-- MENU:\n");
		printf("\t 1. Inserir uma pessoa\n");
		printf("\t 2. Excluir uma pessoa\n");
		printf("\t 3. Listar as pessoas\n");
		printf("\t 4. Sair\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &c);
	} while (c <= 0 || c > 4);
	getchar();
	return c;
}

void removePerson(person *pBuffer){
  char name[10];
  person *aux, *aux2;

  printf("Digite o nome da pessoa que deseja excluir: ");
  scanf("%s", name);

	aux = pBuffer;
	aux2 = pBuffer->next;

	while (aux2 != NULL && strcmp(aux2->name, name) != 0) {
		aux = aux2;
		aux2 = aux2->next;
	}

	if (aux2 != NULL && strcmp(aux2->name, name) == 0) {
		aux->next = aux2->next;
		free(aux2);
	}
  return;
}

void insertPerson(person *pBuffer){
  person *new;

  new = (person *)(malloc(sizeof(person)));
  printf("Digite o nome que deseja inserir: ");
  scanf("%s", new->name);
	printf("%s, ", new->name);
  printf("digite sua idade: ");
  scanf("%d", &new->age);
  printf("Digite seu telefone com apenas numeros: ");
  scanf("%lu", &new->phone);

  new->next = pBuffer->next;
	pBuffer->next = new;
  return;
}

void listAllPeople(person *pBuffer){
  person *aux;
	printf("---- LISTAGEM -----\n");
	for (aux = pBuffer->next; aux != NULL; aux = aux->next){
		printf("NOME: %s ", aux->name);
		printf("TELEFONE: %lu ", aux->phone);
		printf("IDADE: %d\n", aux->age);
  }
}