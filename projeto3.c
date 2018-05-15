/*
    Érico Bandeira - 16/0070287
    Luciana Ribeiro Lins de Albuquerque - 15/0016131
    Max Henrique Barbosa - 16/0047013
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct contato
  {
      char Name [100];
      char Cel [9];
      char Adress [100];
      int CEP;
      char Data []; //colocar no formato dd/mm/yyyy

      struct contato *prox;
      struct contato *ante;
  } Contato;

/*--------------------------------------------------------------------------*/

int main(int argc, char const *argv[])
    {

      return 0;
    }
/*--------------------------------------------------------------------------*/

void imprime (celula *le)
  {
     if (le != NULL) {
        printf ("%d\n", le->Contato);
        imprime (le->prox);
     }
  }
