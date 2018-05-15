/*
    Érico Bandeira - 16/0070287
    Luciana Ribeiro Lins de Albuquerque - 15/0016131
    Max Henrique Barbosa - 16/0047013
*/

#include <stdlib.h>
#include <stdio.h>

void inicia(Contato *le);
//void ordenar (); em ordem alfabética.

typedef struct contato
  {
      char Name [100];
      char Cel [9];
      char Adress [100];
      int CEP;
      char Data [3]; //colocar no formato dd/mm/yyyy

      struct contato *prox;
      struct contato *ante;
  } Contato;

/*--------------------------------------------------------------------------*/

int main(int argc, char const *argv[])
    {

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
/*Foi escolhido: libera, inicia, insere, retira, aloca*/
//----------------------------------------------------------------------------
void opcao(Contato *le, int op)
{
	Contato *tmp;
	switch(op)
    {
  		case 0:
  			libera(Contato);
  			break;

  		case 1:
  			//libera(Contato);
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
void inicia(Contato *le)
{
  Contato *le = (Contato *) malloc(sizeof(Contato));

    if(le == NULL)
      {
        exit(1);
      }

    le->Name = Name;
    le->Cel = Cel;
    le->Adress = Adress;
    le->CEP = CEP;
    le->Data = Data;

	le->prox = NULL;
  le->ante = NULL;
}
//----------------------------------------------------------------------------
void imprime (Contato *le)
  {
     if (le != NULL) {
        printf ("%d\n", le->Contato);
        imprime (le->prox);
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
  //---------------------------------------------------------------------------
  Contato *retiraFim(Contato *LISTA)
{
	if(LISTA->prox == NULL){
		printf("Lista ja vazia\n\n");
		return NULL;
	}else{
		Contato *ultimo = LISTA->prox,
			 *penultimo = LISTA;

		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}

		penultimo->prox = NULL;
		tam--;
		return ultimo;
	}
}
