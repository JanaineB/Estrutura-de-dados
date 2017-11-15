# include <stdlib.h>
# include <stdio.h>

typedef struct No {
    int codigo;
    char nome[10];
    struct No *next;
}No;

struct No *A, *B;
int main()
{
    int i= 0;

    A = NULL;
    B = NULL;


    for( i==0; i <= 10; i++){

        if(A == NULL){

            B = (No*) malloc (sizeof(No));

            printf("Insira codigo: \n");
            scanf("%d", & B -> codigo);
            printf("Insira nome: \n");
            scanf("%s", & B -> nome);

            B->next = NULL;
            A=B;
        }else{

        B = (No*) malloc (sizeof(No));

        printf("Insira codigo: \n");
        scanf("%d", & B -> codigo);
        printf("Insira nome: \n");
        scanf("%s", & B -> nome);

        A->next = B;
        A=B;
        B->next = NULL;

        }
    }
}
