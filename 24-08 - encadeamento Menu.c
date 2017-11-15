# include <stdlib.h>
# include <stdio.h>

typedef struct No {
    int codigo;
    char nome[10];
    struct No *next;
}No;

struct No *corrente, *auxiliar, *auxiliar2, *inicio;

void enterdata(){
    printf("Informe o codigo:  ");
    scanf("%d", &corrente->codigo);
    printf("Informe o nome:  ");
    scanf("%s", &corrente->nome);
}

int insere(No**lista){
   /** corrente = inicio;
    auxiliar = inicio;**/
    if(inicio == NULL){
        corrente = (No*)malloc(sizeof(No));
        corrente->next= NULL;
        auxiliar=corrente;
        inicio=corrente;
        enterdata();
    }else{
    corrente = inicio;
    auxiliar = inicio;
      while(corrente != NULL){
             corrente = corrente -> next;
        }
        corrente = (No*)malloc(sizeof(No));
        auxiliar->next=corrente;
        corrente->next=NULL;
        auxiliar = corrente;
        enterdata();
        }
    }

int lista(){
    /** Coloca o ponteiro auxiliar no inicio da fila **/
    auxiliar = inicio;

    while(auxiliar != NULL){
        printf("Codigo: %d ", auxiliar->codigo);
        printf("Nome: %s \n", auxiliar->nome);
        auxiliar = auxiliar->next;
        break;
    }
}

int consulta(){
    int xcodigo;
    int achou=0;

    if(inicio == NULL){

        printf("Lista Vazia! \n\n");
        main();
    }else{
        auxiliar = inicio;
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
        printf("Informe o Codigo do registro que deseja remover: ");
        scanf("%d", &xcodigo);

        if(auxiliar->codigo == xcodigo){
            inicio = inicio->next;
            free(auxiliar);
            printf("Removido com sucesso no inicio da lista \n");
            system("pause");
            achou=1;
        }else{
            corrente = auxiliar->next;
            while(corrente != NULL){

                if(corrente->codigo == xcodigo){
                    auxiliar->next = corrente->next;
                    free(corrente);
                    achou=1;
                    printf("Removido com sucesso no meio/fim da lista \n");
                    system("pause");
                }else{
                    auxiliar = auxiliar->next;
                    corrente = corrente->next;
                }
            }
        }
        if(achou ==0){
            printf("registro não encontrado...\n");
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
    corrente=NULL;
    auxiliar=NULL;
    inicio = NULL;

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
