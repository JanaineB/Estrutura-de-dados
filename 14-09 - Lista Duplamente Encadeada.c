#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int codigo;
    char nome[20];
    struct No *next, *back;
}No;

struct No *corrente, *auxiliar, *auxiliar2, *inicio, *fim;


void enterdata(){
    printf("Informe o codigo:  ");
    scanf("%d", &corrente->codigo);
    printf("Informe o nome:  ");
    scanf("%s", &corrente->nome);
}

int insere(No**lista) {
    corrente = (No*)malloc(sizeof(No));
    enterdata();
    auxiliar = inicio;
    int achou = 0;
    if(inicio == NULL) {
        auxiliar = corrente;
        inicio = corrente;
        corrente -> next = NULL;
        achou = 1;
        printf("inseriu o primeiro elemento da lista.\n");
        system("pause");
    } else {
        if(corrente -> codigo < auxiliar -> codigo) {
            corrente -> next = auxiliar;
            inicio = corrente;
            achou = 1;
            printf("Elemento precede o primeiro da lista...\n");
            system("pause");
        } else {
            auxiliar2 = auxiliar -> next;
            while(auxiliar2 != NULL) {
                if(corrente -> codigo > auxiliar -> codigo && corrente -> codigo < auxiliar -> codigo) {
                    auxiliar -> next = corrente;
                    corrente -> next = auxiliar2;
                    achou = 1;
                    printf("Inserido no meio da lista.\n");
                    system("pause");
                    break;
                } else {
                    auxiliar = auxiliar -> next;
                    auxiliar2 = auxiliar -> next;
                }
            }
        }
        if (achou == 0 && corrente -> codigo > auxiliar -> codigo) {
            auxiliar -> next = corrente;
            corrente -> next = NULL;
            printf("Inserido no final da lista.\n");
            system("pause");
        }
    }
}

int lista(){
    /** Coloca o ponteiro auxiliar no inicio da fila **/
    auxiliar = inicio;
    if(inicio == NULL){
            printf("Lista Vazia... \n");
            system("pause");
    }else{
        while(auxiliar != NULL){
            printf("Codigo: %d ", auxiliar->codigo);
            printf("Nome: %s \n", auxiliar->nome);
            auxiliar = auxiliar->next;
            break;
        }
    }
}

int consulta(){ /**Esta rotina está pesquisando sentido Inicio->fim da lista, porem pode ser feito em direção oposto F->I**/
    int xcodigo;
    int achou=0;

    if(inicio == NULL){

        printf("Lista Vazia! \n\n");
        main();
    }else{

        auxiliar = inicio;
    ///  auxiliar = fim;
        achou = 0;

        printf("Informe o codigo que deseja buscar: \n");
        scanf("%d", &xcodigo);

        while(auxiliar != NULL){
                if(xcodigo == auxiliar->codigo){
                printf("Codigo:%d ", auxiliar->codigo);
                printf("Nome:%s \n\n", auxiliar->nome);
                system("pause");
                achou = 1;
                break;
                }else{
                auxiliar = auxiliar->next;
            ///  auxiliar = auxiliar->next;
            }
        }if(achou=0){
            printf("Registro não encontrado...");
            system("pause");
        }
    }
}

int remover(){
    int achou = 0;
    int xcodigo;
    if(inicio == NULL){

        printf("Lista Vazia! \n");
        system("pause");
    }else{
        auxiliar = inicio;
        achou = 0;
        printf("Qual o codigo deseja remover: ");
        scanf("%d", &xcodigo);

        if(xcodigo == auxiliar -> codigo) {
            inicio = inicio->next;
            inicio->back = NULL;
            free(auxiliar);
            achou=1;
            printf("Removido com sucesso no INICIO da lista \n");
            system("pause");
        }else{
            corrente = auxiliar -> next; ///sincroniza ponteiro

            while(corrente->next != NULL/**segura o ponteiro no final da lista**/) {
                if(corrente->codigo == xcodigo){
                    corrente = corrente->next; ///corrente pula pra o prox end.
                    corrente -> back = auxiliar; /// corrente encadia o end q saltou com o de aux.
                    corrente = auxiliar -> next; /// corrente volta no endereço anterior q sera liberado
                    auxiliar -> next  = corrente ->next;/// auxiliar encadia no endereço q o campo next do corrente ta apontando

                    free(corrente); ///liberado o end. em q corrente está

                    printf("Removido com sucesso no MEIO da lista \n");

                    system("pause");
                    achou=1;
                    break;
                }else{
                    auxiliar = auxiliar->next;
                    corrente = corrente->next;
                }
            }
        }
        if(achou == 0 && corrente -> codigo == xcodigo){
            fim = auxiliar;
            auxiliar->next = NULL;
            free(corrente);
            printf("Removido com sucesso no FINAL da fila...\n");
            system("pause");

        }
    }
}

int altera(){
    int xcodigo;
    auxiliar = inicio;
    if(inicio == NULL){

        printf("Lista Vazia! \n\n");
        main();
    }else{
        printf("Informe o codigo que deseja alterar: \n");
        scanf("%d", &xcodigo);
        while(auxiliar != NULL){
                if(xcodigo == auxiliar->codigo){
                printf("Nome:%s , alterar para: \n", auxiliar->nome);
                scanf("%s", &auxiliar->nome);
                break;
                }else{
                auxiliar = auxiliar->next;
            }
        }
    }
}

void sair(){
    exit(0);
}

int main(){

    corrente=   NULL;
    auxiliar=   NULL;
    inicio=     NULL;
    fim =       NULL;
    auxiliar2=  NULL;


    int op;
do {
    printf("\n [1] - Inserir");
    printf("\n [2] - Listar");
    printf("\n [3] - Consultar");
    printf("\n [4] - Remover");
    printf("\n [5] - Alterar");
    printf("\n [0] - Sair");
    printf("\n [ ] - escolha sua opcao: ");
    scanf("%d", &op);
        printf("\n");
    switch (op){
case 1:
    insere(&inicio);
    break;
case 2:
    lista ();
    break;
case 3:
    consulta ();
    break;
case 4:
    remover ();
    break;
case 5:
    altera ();
    break;
case 0:
    sair ();
    break;
    }
    }
  while (op < 6);

return 0;

}
