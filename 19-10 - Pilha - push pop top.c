#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
     int codigo;
     struct no *next, *back;
} no;

struct no *topo, *auxiliar;
int contador=0;


void  enterdata()
{
printf("Entre com o codigo \n");
scanf("%i", &auxiliar->codigo);
fflush(stdin);
}

int push ()
{
    if (topo==NULL)
    {
        topo = (no*)malloc(sizeof(no));
        auxiliar=topo;
        topo->next=NULL;
        topo->back=NULL;

        contador++;

        enterdata();
    }

    else
    {
        if (contador == 5)
        {
            printf("Slack overflow...\n");
            system("pause");
        }

        else
        {
            topo = (no*)malloc(sizeof(no));
            auxiliar->next=topo;
            topo->back=auxiliar;
            auxiliar=topo;
            topo->next=NULL;

            contador++;
            enterdata();
        }
    }
}

int pop ()
{
    if (topo==NULL)
    {
        printf("Stack underflow...");
        system("pause");
    }

    auxiliar = topo;
    topo=topo->back;
    printf("Codigo: %i sera removido! \n", auxiliar->codigo);
    free(auxiliar);
    topo->next=NULL;

    contador--;
    printf("Removido com sucesso!\n");
    system("pause");
}
int top ()
{
    printf("Codigo no topo da pilha eh: %i \n", topo->codigo);
    system("pause");
}

void sair(){
 exit(0);
}

int main(){

    topo=   NULL;
    auxiliar=   NULL;



    int op;
do {
    printf("\n [1] - PUSH");
    printf("\n [2] - POP");
    printf("\n [3] - TOP");
    printf("\n [0] - Sair");
    printf("\n [ ] - escolha sua opcao: ");
    scanf("%d", &op);
        printf("\n");
    switch (op){
case 1:
    push (&topo);
    break;
case 2:
    pop();
    break;
case 3:
    top();
    break;
case 0:
    sair ();
    break;
    }
    }
  while (op < 4);

return 0;

}
