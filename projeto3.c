/*
    Érico Bandeira - 16/0070287
    Luciana Ribeiro Lins de Albuquerque - 15/0016131
    Max Henrique Barbosa - 16/0047013
*/

#include <stdlib.h>
#include <stdio.h>

//LISTAR AS FUNÇÕES

void inicia(Contato *le);
//void ordenar (); em ordem alfabética.

typedef struct contato
  {
      char Name [100];
      char Cel [9];
      char Adress [100];
      int CEP;
      char Date [3]; //colocar no formato dd/mm/yyyy

      struct contato *prox;
      struct contato *ante;
  } Contato;

/*--------------------------------------------------------------------------*/

int main(int argc, char const *argv[])
{
  FILE *arq;                        /*IMPLEMENTAR FUNÇÃO PRA LER ARQUIVO*/
  char Linha[100];
  char *result;
  int i;

  arq = fopen("contatos.txt", "r");
  if (arq == NULL)
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  i = 1;
  while (!feof(arq))
  {
      result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      if (result)  // Se foi possível ler
	    printf("Linha %d : %s",i,Linha);
      i++;
  }
  fclose(arq);
return 0;
}

/*--------------------------------------------------------------------------*/
int menu(void)
{
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Inserir novo registro\n");
	printf("2. Remover um registro\n");
	printf("3. Procurar registro\n");
	printf("4. Vizualizar todo o registro\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}
/*Foi escolhido: limpa, inicia, insere, retira, aloca*/
//----------------------------------------------------------------------------
void opcao(Contato *le, int op) //CONCERTAR OS NOMES DE FUNÇOES
{
	Contato *tmp;
	switch(op)
    {
  		case 0:
  			limpa(Contato);
  			break;

  		case 1:
  			//limpa(Contato);
  			insere(Contato);
  			break;

  		case 2:
        tmp= retira(Contato);//chamar de remove
        printf("Retirado: %3d\n\n", tmp->num);
  		  break;

  		case 3:
  			busca_contato(Contato);
  			break;

  		case 4:
  			imprime(Contato);
  			break;

  		default:
  			printf("Comando invalido\n\n");
  	}
}
//----------------------------------------------------------------------------
void adicionar(/*int parametros*/,Contato *atual) //ACRESCENTAR OS PARAMETROS
{
    if(*atual == NULL)
      {
        (*atual) = malloc(sizeof(Contato));

        (*atual)->Name = Name;
        (*atual)->Cel = Cel;
        (*atual)->Adress = Adress;
        (*atual)->CEP = CEP;
        (*atual)->Date = Date;

        (*atual)->prox = *atual;
        (*atual)->ante = *atual;
      }
    else
      {
        Contato *aux, *ultimo;
        aux = *atual;
        while(aux->prox != *atual)
            aux = aux->prox;
        aux->prox = malloc(sizeof(Contato));
        ultimo = aux->prox;
        ultimo->ante = aux;
        ultimo->prox = *atual;
        ultimo->info = parametro;
        (*atual)->ante = ultimo;
      }
}
//----------------------------------------------------------------------------
void ordena(Lista *le){ //insertion sort
    Contato *cur, *ptr, *tmp, *aux, *aux_ant, *aux_prox;
//  if(listaVazia(le))
//      return;

    cur = *le;
    cur = cur->prox;

    // Tratando para o caso da lista com 2 elementos
    if( cur->prox == *le){
        if( (*le)->info > cur->info)
            (*le) = (*le)->prox;
        return;
    }

    while(cur!=*le){
        ptr=cur;
        tmp=cur->ant;
        cur=cur->prox;

        while (tmp->prox != *le && tmp->info > ptr->info){
            aux_ant = tmp->ant;
            aux_prox = ptr->prox;

            aux_ant->prox = ptr;
            ptr->prox = tmp;
            tmp->prox = aux_prox;
            aux_prox->ant = tmp;
            tmp->ant = ptr;
            ptr->ant = aux_ant;

            tmp = ptr;
            ptr = tmp->prox;

            if(ptr==*le)
                *le = tmp;

            tmp=tmp->ant;
            ptr = ptr->ant;
        }
    }
}
//----------------------------------------------------------------------------
void imprime (Contato *le) //tem que refatorar
  {
    Contato *aux;
    aux = *atual;
    printf("Imprimindo lista:\n");
    do{
        printf("%d ", aux->info);
        aux = aux->prox;
    }while(aux != *atual);
    printf("\n");
     }
  }
//-----------------------------------------------------------------------------
Contato *busca_contato (int x, Contato *le) //Recebe x
  {
     if (le == NULL)
      return NULL;

     if (le->Name == x)
      return le;
  return busca_contato (x, le->prox);
  }
//-----------------------------------------------------------------------------
Contato *retira(Contato *le)//FAZER ESSA FUNÇÃO
{
	if(le->prox == NULL)
    {
  		printf("Lista ja vazia\n\n");
  		return NULL;
  	}
  else
    {
  		Contato *ultimo = le->prox,
  			 *penultimo = le;

  		while(ultimo->prox != NULL){
  			penultimo = ultimo;
  			ultimo = ultimo->prox;
  	}

		penultimo->prox = NULL;
		tam--;
		return ultimo;
	}
}
//-----------------------------------------------------------------------------
void limpa(node *le)//FAZER ESSA FUNÇÃO
{
	if(!vazia(le)){
		node *proxNode,
			  *atual;

		atual = le->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}
