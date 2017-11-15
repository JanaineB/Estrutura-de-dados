# include <stdlib.h>
# include <stdio.h>

typedef struct No {
    int codigo;
    char nome[10];
    struct No *next;
}No;

struct No *corrente, *auxiliar, *inicio;

void enterdata(){
    printf("Informe o codigo:  ");
    scanf("%d", &corrente->codigo);
    printf("\n informe o nome:  ");
    scanf("%s", &corrente->nome);
}

int insere(No**lista){
    if(inicio == NULL){
        corrente = (No*)malloc(sizeof(No));
        corrente->next= NULL;
        auxiliar=corrente;
        inicio=corrente;
        enterdata();
    }else{
        corrente = (No*)malloc(sizeof(No));
        auxiliar->next=corrente;
        corrente->next=NULL;
        auxiliar = corrente;
        enterdata();
    }
}

int main(){
    corrente=NULL;
    auxiliar=NULL;
    inicio = NULL;
    insere(&inicio);
}
