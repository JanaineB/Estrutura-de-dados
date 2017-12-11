#include <stdio.h>
#include <stdlib.h>

typedef struct arvore_bin{
       int info;
       struct arvore_bin *esquerda;
       struct arvore_bin *direita;
}arvore_bin;

struct arvore_bin *raiz;

arvore_bin *visita_arvore(arvore_bin *ra, arvore_bin *r, int pValor){
    if(r == NULL){
        r = (arvore_bin *) malloc (sizeof(arvore_bin));
        if (r == NULL){
            printf("\n\nErro. Sem memoria para alocar\n\n");
            system("pause");
            exit(0);
        }
        r->esquerda = NULL;
        r->direita = NULL;
        r->info = pValor;

        if(ra == NULL){
            printf("\nEsse numero Adicionado e a raiz\n");
            system("pause");
            return r;
        }
        if(pValor < ra->info){
            ra->esquerda = r;
            printf("\nEsse numero foi adicionado a esqueda de %d\n", ra->info);
        }else{
            ra->direita = r;
            printf("\nEssa numero foi adicionado a direita %d\n", ra->info);
        }
        system("pause");
        return r;
    }
    if(pValor < r->info){
        visita_arvore(r, r->esquerda, pValor);
    }else{
        visita_arvore(r, r->direita, pValor);
    }
}

void incluir (void){
     int vValor;
     printf("\nDigite o valor para inserir: ");
     scanf("%d", &vValor);
     if (raiz == NULL){
        raiz = visita_arvore(raiz, raiz, vValor);
     }else{
        visita_arvore(raiz, raiz, vValor);
     }
}

void preordem(arvore_bin *pNo){
    if (pNo != NULL){
       printf("%d - ", pNo->info);
       preordem(pNo->esquerda);
       preordem(pNo->direita);
    }
}

void posordem(arvore_bin *pNo){
    if (pNo != NULL){
       posordem(pNo->esquerda);
       posordem(pNo->direita);
       printf("%d - ", pNo->info);
    }
}

void emordem(arvore_bin *pNo){
    if (pNo != NULL){
       emordem(pNo->esquerda);
       printf("%d - ", pNo->info);
       emordem(pNo->direita);
    }
}

int listar(arvore_bin *pNo){
   int a=1,b=1;
   if(pNo != NULL){
      printf("(");
      printf("%d",pNo->info);
      a=listar(pNo->esquerda);///a==0 caso sub_arvore_esquerda==NULL
      b=listar(pNo->direita);///a==0 caso sub_arvore_direita==NULL
      if(b==0 && a==0){
          printf("()");///imprime  () se e somente se encontrar um nó folha
      }else if(b==0 && a!=0){
          ///isso acontece se encontrar um nó com a perna direita null
          //printf("()");
      }else if(b!=0 && a==0){
         ///isso acontece se encontrar um nó com a perna esquerda null
         //printf("()");
      }
      printf(")");///fecha a representação de uma raiz
   }else{
       return 0;//retorna 0 caso arvore == NULL
   }
}

int main (void){
    int op;
    raiz=NULL;
    while(1){
        system ("cls");
        printf ("\nMenu");
        printf ("\n\n 1. Insere");
        printf ("\n 2. Exibe Arvore");
        printf ("\n 3. Exibe Arvore em PreOrdem");
        printf ("\n 4. Exibe Arvore em PosOrdem");
        printf ("\n 5. Exibe Arvore em EmOrdem");
        printf ("\n 6. Sair");
        printf ("\n\n Entre a sua opcao: ");
        scanf ("%d",&op);
        fflush(stdin);
        switch (op) {
            case 1 : incluir();
                     break;
            case 2 : listar(raiz);
                     puts("\n\n");
                     system("pause");
                     break;
            case 3 : preordem(raiz);
                     system("pause");
                     break;
            case 4 : posordem(raiz);
                     system("pause");
                     break;
            case 5 : emordem(raiz);
                     system("pause");
                     break;
            case 6 : exit(0);
            default: printf ("\nOpcao errada");
                     system ("pause");
                     break;
        }
   }
}
