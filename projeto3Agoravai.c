/*
    Érico Bandeira - 16/0070287
    Luciana Ribeiro Lins de Albuquerque - 15/0016131
    Max Henrique Barbosa - 16/0047013
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct contato {
  char name[100];
  char cel[10];
  char adress[100];
  int cep;
  char date[3];

  struct contato *prox;
  struct contato *ante;
} Contato;

Contato *readFile();
Contato *newInsert(Contato *list);
Contato *insertSort(Contato *position, Contato *list);

int main() {
  Contato *list;
  int sel;
  char c;

  if(list = (Contato*)malloc(sizeof(Contato)), list == NULL){
    printf("Erro ao alocar!\n");
  }
  list = readFile();
  system("clear");

  do {

    printf("\n=========================================================================\n");
    printf("||\t0. Sair                                                        ||\n");
    printf("||\t1. Inserir novo registro                                       ||\n");
    printf("||\t2. Remover registros que possuem o nome indicado               ||\n");
    printf("||\t3. Visualizar registros que possuem o nome indicado            ||\n");
    printf("||\t4. Visualizar todos os registros em ordem alfabética de nomes  ||\n");
    printf("=========================================================================\n\n");

    printf("Resposta: ");
    scanf("%d",&sel);

    switch(sel){
      case 1:
        printf("\n");
        list = newInsert(list);
      break;

      case 2:
        printf("\n");
      break;

      case 3:
        printf("\n");
      break;

      case 4:
        printf("\n");
      break;


    }

    system("clear");

  } while(sel != 0);
  return 0;
}

Contato *readFile(){
  FILE *fp;
  Contato *data, *firstPosition;
  char dollar;

  if(fp = fopen("contatos.txt", "r+"), fp == NULL){
    printf("Falha ao abrir o arquivo!\n");
    exit(1);
  }

  while(!feof(fp)){
    if(data = (Contato*)malloc(sizeof(Contato)), data == NULL){
      printf("Erro ao alocar!\n");
    }

    fscanf(fp, "%[^\n]\n%s\n%[^\n]\n%u\n%s\n%c\n",
           data->name,
           data->cel,
           data->adress,
           &data->cep,
           data->date,
           &dollar);

    firstPosition = insertSort(firstPosition, data);

  }
  fclose(fp);

  return firstPosition;
}

Contato *insertSort(Contato *position, Contato *data){
  Contato *num;

  for(num=position; num!=NULL; num=num->prox){
    if(strcasecmp(num->name, data->name) > 0){
      data->prox = num;
      data->ante = num->ante;
      num->ante = data;

      if(data->ante != NULL){
        data->ante->prox = data;
      } else {
        position = data;
      }
      return position;
    }
    if(num -> prox == NULL){
      data -> prox = NULL;
      data -> ante = num;
      num -> prox = data;
      return position;
    }
  }
}

Contato *newInsert(Contato *list){
  Contato *newData;
  char day, month, year;

  if(newData = (Contato*)malloc(sizeof(Contato)), newData == NULL){
    printf("Erro ao alocar!\n");
  }

  printf("Insira o nome do novo contato:\n");
  scanf("%[^\n]",newData->name);

  printf("Insira o telefone do novo contato:\n");
  scanf("%[^\n]",newData->cel);

  printf("Insira o endereco do novo contato:\n");
  scanf("%[^\n]",newData->adress);

  printf("Insira o CEP do novo contato:\n");
  scanf("%u",&newData->cep);

  printf("Insira a data de nascimento do novo contato:\n");
  scanf("%[^\n]",newData->date);

  list = insertSort(list, newData);
  return list;
}
