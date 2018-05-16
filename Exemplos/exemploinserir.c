#include <stdio.h>
#include <stdlib.h>

typedef struct No_lista{
    struct No_lista *ant;
    struct No_lista *prox;
    int info;
} No_lista;

typedef No_lista* Lista;

void adicionar(int parametro, Lista *inicial){
    if(*inicial == 0 ){
        (*inicial) = malloc(sizeof(No_lista));
        (*inicial)->ant = *inicial;
        (*inicial)->prox = *inicial;
        (*inicial)->info = parametro;
    }else{
        No_lista *aux, *ultimo;
        aux = *inicial;
        while(aux->prox != *inicial)
            aux = aux->prox;
        aux->prox = malloc(sizeof(No_lista));
        ultimo = aux->prox;
        ultimo->ant = aux;
        ultimo->prox = *inicial;
        ultimo->info = parametro;
        (*inicial)->ant = ultimo;
    }
}

void printLista(Lista *inicial){
    No_lista *aux;
    aux = *inicial;
    printf("Imprimindo lista:\n");
    do{
        printf("%d ", aux->info);
        aux = aux->prox;
    }while(aux != *inicial);
    printf("\n");
}

void ordena(Lista *p_l){ //insertion sort
    No_lista *cur, *ptr, *tmp, *aux, *aux_ant, *aux_prox;
//  if(listaVazia(p_l))
//      return;

    cur = *p_l;
    cur = cur->prox;

    // Tratando para o caso da lista com 2 elementos
    if( cur->prox == *p_l){
        if( (*p_l)->info > cur->info)
            (*p_l) = (*p_l)->prox;
        return;
    }

    while(cur!=*p_l){
        ptr=cur;
        tmp=cur->ant;
        cur=cur->prox;

        while (tmp->prox != *p_l && tmp->info > ptr->info){
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

            if(ptr==*p_l)
                *p_l = tmp;

            tmp=tmp->ant;
            ptr = ptr->ant;
        }
    }
}

int main()
{
    Lista *li, p = NULL;
    li = &p;

    adicionar(4, li);
    adicionar(1, li);
    adicionar(7, li);
    adicionar(5, li);
    adicionar(2, li);

    printLista(li);
    ordena(li);
    printLista(li);

   // scanf("%*c");
    return 0;
}    
