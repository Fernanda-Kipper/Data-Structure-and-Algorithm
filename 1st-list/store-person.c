#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct person
{
  char name[10];
  int age;
  unsigned long int phone;
};

typedef struct person person;
void insertPerson(void *pBuffer);
void removePerson(void *pBuffer);
void listAllPeople(void *pBuffer);
void searchPerson(void *pBuffer);
int menu(void);

int agendaLength = 0;

int main()
{
	int chosen;
  void *pBuffer;

	pBuffer = (void *)malloc(sizeof(person));
	if (pBuffer == NULL) {
		printf("Não foi possível alocar memória\n");
		exit(1);
	}

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
			searchPerson(pBuffer);
			break;
		case 5:
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
		printf("\t 4. Buscar por uma pessoas\n");
		printf("\t 5. Sair\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &c);
	} while (c != 0 && c != 1 && c != 2 && c != 3 && c != 4 && c != 5);
	getchar();
	return c;
}

void removePerson(void *pBuffer){
	char name[10];
	void *auxBuffer = pBuffer, *aux2Buffer, *aux3Buffer;
	person auxListPerson;
	
	printf("Digite o nome que deseja excluir da agenda: ");
	scanf("%s", name);
	setbuf(stdin, NULL);

	for (int cont = 0; cont < agendaLength; cont++){
		auxListPerson = *(person *)auxBuffer;
		// if this is the person to remove
		if(strcmp(auxListPerson.name, name) == 0){
			printf("Dentro do if igual");
			// if is not the last person on the list
			if(cont != (agendaLength - 1)){
				aux2Buffer = auxBuffer;
				for(int cont2 = cont; cont2 < agendaLength; cont2++){
					aux3Buffer = aux2Buffer + sizeof(person);
					*(person *)aux2Buffer = *(person *)aux3Buffer;

					aux2Buffer = aux2Buffer + sizeof(person);
				}
			}
			// reduces the size to remove the last one
			pBuffer = realloc(pBuffer, sizeof(person) * (agendaLength - 1));
			agendaLength--;
			break;
		}
		auxBuffer = auxBuffer + sizeof(person);
	}
  return;
}

void insertPerson(void *pBuffer){
	char name[10];
	person auxCreatePerson;
	void *auxBuffer;

  // store values inside a person struct
	printf("Digite o nome: ");
	scanf("%s", auxCreatePerson.name);
	setbuf(stdin, NULL);

	printf("%s, ", auxCreatePerson.name);
  printf("digite sua idade: ");
  scanf("%d", &auxCreatePerson.age);
	setbuf(stdin, NULL);

  printf("Digite seu telefone com apenas numeros: ");
  scanf("%lu", &auxCreatePerson.phone);
	setbuf(stdin, NULL);

	if(agendaLength >= 1){
		if ((pBuffer = realloc(pBuffer, sizeof(pBuffer) + sizeof(person))) == NULL){
			printf("Nao foi possivel alocar a memoria.\n");
		}
	}

	// change the value inside the value pointed by pointer to store the new person
	auxBuffer = pBuffer;
	auxBuffer = auxBuffer + (sizeof(person) * agendaLength);
  *(person *)auxBuffer = auxCreatePerson;
	agendaLength++;

  return;
}

void searchPerson(void *pBuffer){
	char name[10];
	void *auxBuffer = pBuffer;
	person auxListPerson;
	
	printf("Digite o nome que deseja buscar na agenda: ");
	scanf("%s", name);
	setbuf(stdin, NULL);

	for (int cont = 0; cont < agendaLength; cont++){
		auxListPerson = *(person *)auxBuffer;
		if(strcmp(auxListPerson.name, name) == 0){
			printf("Pessoa encontrada! Dados: \n");
			printf("NOME: %s ", auxListPerson.name);
			printf("IDADE: %d ", auxListPerson.age);
			printf("TELEFONE: %d \n", auxListPerson.phone);
		}

		auxBuffer = auxBuffer + sizeof(person);
  }
}

void listAllPeople(void *pBuffer){
  void *auxBuffer = pBuffer;
	person auxListPerson;
	printf("---- AGENDA -----\n");
	for (int cont = 0; cont < agendaLength; cont++){
		auxListPerson = *(person *)auxBuffer;
		printf("NOME: %s ", auxListPerson.name);
		printf("IDADE: %d ", auxListPerson.age);
		printf("TELEFONE: %d \n", auxListPerson.phone);

		auxBuffer = auxBuffer + sizeof(person);
  }
}