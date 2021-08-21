#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *names;
void insert(void);
void removeName(void);
void print(void);
int menu(void);
char* readString();

int main()
{
	int chosen;
  names = (char *)malloc(sizeof(char));
  names[0] = '\0';

	for (;;) {
		chosen = menu();
		switch (chosen) {
		case 1:
			insert();
			break;
		case 2:
			removeName();
			break;
		case 3:
			print();
			break;
		case 4:
			free(names);
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
		printf("\t 1. Inserir um nome\n");
		printf("\t 2. Excluir um nome\n");
		printf("\t 3. Listar os nomes\n");
		printf("\t 4. Sair\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &c);
	} while (c <= 0 || c > 4);
	getchar();
	return c;
}

char *readString()
{
	int i = 0;
	char c, *string;

  string = (char *)malloc(sizeof(char));
  if(string == NULL){
    printf("Nao foi possivel alocar memoria");
    exit(1);
	}

  while ((c != '\n') && (c != EOF)) {
    c = getchar();
    string = (char *)realloc(string, sizeof(char) * (i + 1));
    string[i] = c;
    i++;
  }

  string = (char *)realloc(string, sizeof(char) * (i + 1));
  string[i] = '\0';

  return string;
}

void removeName(){
  char *name, *name_location, *second_names;
  int cont = 0, cont2 = 0, equal_letters = 0;

  printf("Digite o nome que deseja excluir: ");
  name = readString();

  size_t name_length = strlen(name);
  name_location = strstr(names, name);
  size_t names_length = strlen(names);

  if(name_location != NULL){
    if(name_length == names_length){
      names = realloc(names, sizeof(char));
      *(names) = '\0';
    }

    else{
      while(names[cont] != '\0'){
        if(names[cont] == name[0]){
          equal_letters = 1;
          for(cont2 = 1; cont2 < name_length; cont2++){
            if(name[cont2] == names[cont + cont2]){
              equal_letters++;
            }
          }

          if(equal_letters == name_length){
            for(cont2 = 0; cont2 < name_length; cont2++){
              *(names + cont + cont2) = ';';
            }
          }
        }
        cont++;
      }

      second_names = (char *)malloc(sizeof(char));
      cont2 = 0;
      for(cont = 0; cont <= names_length; cont++){
        if(names[cont] != ';'){
          second_names = realloc(second_names, sizeof(char) * cont2 + 1);
          second_names[cont2] = names[cont];
          cont2++;
        }
      }
      cont2++;
      second_names[cont2] = '\0';
      strcpy(names, second_names);
      names = realloc(names, sizeof(char) * cont2);
      free(second_names);
    }
  }

  printf("\n---------NOVA LISTA---------\n %s", names);
}

void insert(){
  char *name;
  int cont = 0, cont2 = 0;

  printf("Digite o nome que deseja inserir: ");
  name = readString();
  names = (char *)realloc(names, sizeof(names) + sizeof(name));

  while(names[cont] != '\0') cont++;
  while(name[cont2] != '\0'){
    names[cont] = name[cont2];
    cont++;
    cont2++;
  }

  names[cont] = '\0';
}

void print(){
  printf("%s", names);
}