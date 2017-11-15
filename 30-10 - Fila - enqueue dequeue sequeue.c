#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
     int codigo;
     struct no *next, *back;
} no;

struct no *inicio, *fim, *auxiliar;
int contador=0;


void  enterdata()
{
    int var;
    printf("Entre com o codigo \n");
    scanf("%d", &var);
    fflush(stdin);
    auxiliar->codigo = var;
    printf("codigo: %d\n", auxiliar->codigo);
}

int enqueue ()
{
    if (inicio==NULL)
    {
        inicio = (no*)malloc(sizeof(no));
        auxiliar=inicio;
        fim = inicio;
        inicio->next=NULL;
        inicio->back=NULL;

        contador++;

        enterdata();
    }

    else
    {
        if (contador == 5)
        {
            printf("Queue overflow...\n");
            system("pause");
        }else{
            fim = (no*)malloc(sizeof(no));
            auxiliar->back=fim;
            fim->next=auxiliar;
            auxiliar=fim;
            fim->back=NULL;

            contador++;
            enterdata();
        }
    }
}

int dequeue ()
{
    if (inicio==NULL)
    {
        printf("Queue underflow...");
        system("pause");
    }

    auxiliar = inicio;
    inicio=inicio->back;
    printf("Codigo: %d sera removido! \n", auxiliar->codigo);
    free(auxiliar);
    inicio->next=NULL;

    contador--;
    printf("Removido com sucesso!\n");
    system("pause");
}
int sequeue ()
{
    auxiliar = inicio;
    while (auxiliar != NULL){
        printf("a fila eh: %d \n", auxiliar->codigo);
        auxiliar = auxiliar->back;
    }
    system("pause");
}

void sair(){
 exit(0);
}

int main(){

    inicio=     NULL;
    fim =       NULL;
    auxiliar=   NULL;



    int op;
    do {
        printf("\n [1] - ENQUEUE");
        printf("\n [2] - DEQUEUE");
        printf("\n [3] - SEQUEUE");
        printf("\n [0] - Sair");
        printf("\n [ ] - escolha sua opcao: ");
        scanf("%d", &op);
            printf("\n");
        switch (op){
    case 1:
        enqueue (&inicio);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        sequeue();
        break;
    case 0:
        sair ();
        break;
        }
        }
      while (op < 4);

    return 0;

}
