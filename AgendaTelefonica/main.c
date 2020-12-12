#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <malloc.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#define TAM_NOME 100
#define TAM_TELEFONE 20

typedef struct Pessoa {
    struct Pessoa *anterior;
    struct Pessoa *proximo;
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
    int idade;
} Pessoa;

typedef struct ListaDE {
    Pessoa *primeiro;
    Pessoa *ultimo;
    int qtd;
} ListaDE;

ListaDE *criaLista();
Pessoa *criaPessoa();
void menu();
void leString(char *str, int tamanho);
void insereInicio(ListaDE *l, Pessoa *p);
void insereFinal(ListaDE *l, Pessoa *p);
void inserePosicao(ListaDE *l, Pessoa *p, int i);
void insereOrdenado(ListaDE *l, Pessoa *p);
Pessoa *removeInicio(ListaDE *l);
Pessoa *removeFinal(ListaDE *l);
Pessoa *removePosicao(ListaDE *l, int i);
void mostraListaED(ListaDE *l);
void mostraListaDE(ListaDE *l);
void mostraPessoa(Pessoa *p);
int numeroElementos(ListaDE *l);
void apagaListaInteira(ListaDE *l);
void apagaPessoa(Pessoa *p);

int main() {
    ListaDE *agenda = criaLista();
    Pessoa *aux;
    int index;

    menu();
    int opcao;
    scanf("%d", &opcao);
    while (opcao) {
        switch (opcao) {

             case 1:
                printf("\nInserir Pessoa no Início da Lista\n\n");
                insereInicio(agenda, criaPessoa());
                break;

            case 2:
                printf("\nInserir Pessoa no Final da Lista\n\n");
                insereFinal(agenda, criaPessoa());
                break;

            case 3:
                printf("\nInsere Pessoa em uma Posição\n\n");
                do {
                    printf("Por favor, informe a Posição que deseja inserir (entre 0 e %d): ", numeroElementos(agenda));
                    scanf("%d", &index);
                } while (index < 0 || index > numeroElementos(agenda));
                inserePosicao(agenda, criaPessoa(), index);
                break;

            case 4:
                printf("\nMostrar Agenda - da esquerda para a direita\n\n");
                mostraListaED(agenda);
                break;

            case 5:
                printf("\nMostrar Agenda - da direita para a esquerda\n\n");
                mostraListaDE(agenda);
                break;


            case 6:
                printf("\nRemover Pessoa do Início da Lista\n\n");
                if (numeroElementos(agenda) > 0) {
                    aux = removeInicio(agenda);
                    if (aux != NULL) {
                        apagaPessoa(aux);
                        printf("\nPessoa removida com sucesso!\n");
                    }
                } else printf("\nRemoção Inválida!\n");
                break;

                case 7:
                printf("\nRemover Pessoa do Final da Lista\n\n");
                if (numeroElementos(agenda) > 0) {
                    aux = removeFinal(agenda);
                    if (aux != NULL) {
                        apagaPessoa(aux);
                        printf("\nPessoa removida com sucesso!\n");
                    }
                } else printf("\nRemoção Inválida!\n");
                break;

            case 8:
                printf("\nRemover Pessoa escolhendo a Posição\n\n");
                if (numeroElementos(agenda) > 0) {
                    do {
                        printf("Por favor, informe a Posição que deseja inserir (entre 0 e %d): ", numeroElementos(agenda) - 1);
                        scanf("%d", &index);
                    } while (index < 0 || index >= numeroElementos(agenda));
                    aux = removePosicao(agenda, index);
                    if (aux != NULL) {
                        apagaPessoa(aux);
                        printf("\nPessoa removida com sucesso!\n");
                    }
                } else printf("\nRemoção Inválida!\n");
                break;
            default:
                printf("\nOpcao inválida!!!\n\n");
                getchar();
                break;
        }
        menu();
        scanf("%d", &opcao);
    }
    apagaListaInteira(agenda);
    free(agenda);
    printf("\nLista Destruida!\n");

    printf("\n\t\tObrigado por usar nossa agenda telefonica!\n");

    printf("\t\t***************************************************\n");
    printf("\t\t********************* [FIM] ***********************\n");
    printf("\t\t***************************************************\n\n");
    return 0;
}

void menu() {
    printf("\t\t***************************************************\n");
    printf("\t\t*********** [AGENDA TELEFÔNICA - 1.0] *************\n");
    printf("\t\t***************************************************\n\n");
    printf("\t\t Renan Gomes Acosta - 11230237\n\n");


    printf("\n\t\tOPCOES:\n");
    printf("\n\t\t1 - Inserir Pessoa no Início da Lista");
    printf("\n\t\t2 - Inserir Pessoa no Final da Lista");
    printf("\n\t\t3 - Inserir Pessoa escolhendo a Posição");
    printf("\n\t\t4 - Mostrar Agenda - da esquerda para a direita");
    printf("\n\t\t5 - Mostrar Agenda - da direita para a esquerda");
    printf("\n\t\t6 - Remover Pessoa do Final da Lista");
    printf("\n\t\t7 - Remover Pessoa do Início da Lista");
    printf("\n\t\t8 - Remover Pessoa escolhendo a Posição");
    printf("\n\t\t0 - Sair\n");
    printf("\n\t\tOPCAO: ");
}

void leString(char *str, int tamanho) {
    __fpurge(stdin);
    fgets(str, tamanho, stdin);
    if (str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }
}

ListaDE *criaLista() {
    ListaDE *aux = (ListaDE *)malloc(sizeof(ListaDE));
    aux->primeiro = NULL;
    aux->ultimo = NULL;
    aux->qtd = 0;
    return aux;
}

Pessoa *criaPessoa() {
    Pessoa *novo = (Pessoa *)malloc(sizeof(Pessoa));
    printf("\n----------- NOVO CONTATO -----------");
    printf("\nNome....: ");
    leString(novo->nome, TAM_NOME);
    printf("Telefone: ");
    leString(novo->telefone, TAM_TELEFONE);
    printf("Idade...: ");
    scanf("%d", &novo->idade);
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

void insereFinal(ListaDE *l, Pessoa *p) {
    p->proximo = NULL;
    if(l->primeiro == NULL) {
        p->anterior = NULL;
        l->primeiro = p;
    } else {
        p->anterior = l->ultimo;
        l->ultimo->proximo = p;
    }
    l->ultimo = p;
    l->qtd++;
}

void insereInicio(ListaDE *l, Pessoa *p) {
    p->anterior = NULL;
    if(l->primeiro == NULL) {
        p->proximo = NULL;
        l->ultimo = p;
    } else {
        p->proximo = l->primeiro;
        l->primeiro->anterior = p;
    }
    l->primeiro = p;
    l->qtd++;
}

void inserePosicao(ListaDE *l, Pessoa *p, int i) {
    if (l == NULL || p == NULL || i < 0 || i > numeroElementos(l)) printf("\nInserção inválida!\n");
    else {
        if (i == 0) insereInicio(l, p);
        else if (i == numeroElementos(l)) insereFinal(l, p);
        else {
            Pessoa *aux = l->primeiro;
            int index = 0;
            while(i != index ) {
                aux = aux->proximo;
                index++;
            }
            aux->anterior->proximo = p;
            p->anterior = aux->anterior;
            p->proximo = aux;
            aux->anterior = p;
            l->qtd++;
        }
    }
}

Pessoa *removeFinal(ListaDE *l) {
    if (numeroElementos(l) == 0) {
        printf("\nLista Vazia!\n");
        return NULL;
    }
    Pessoa *aux = l->ultimo;
    if (numeroElementos(l) == 1) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    } else {
        l->ultimo = aux->anterior;
        l->ultimo->proximo = NULL;
    }
    l->qtd--;
    return aux;
}

Pessoa *removeInicio(ListaDE *l) {
    if (numeroElementos(l) == 0) {
        printf("\nLista Vazia!\n");
        return NULL;
    }
    Pessoa *aux = l->primeiro;
    if (numeroElementos(l) == 1) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    } else {
        l->primeiro = aux->proximo;
        l->primeiro->anterior = NULL;
    }
    l->qtd--;
    return aux;
}

Pessoa *removePosicao(ListaDE *l, int i) {
    if (l == NULL || i < 0 || i >= numeroElementos(l)) {
        printf("\nRemoção inválida!\n");
        return NULL;
    }
    if (i == 0) return removeInicio(l);
    else if (i == numeroElementos(l) - 1) return removeFinal(l);
    else {
        Pessoa *aux = l->primeiro;
        int index = 0;
        while(i != index ) {
            aux = aux->proximo;
            index++;
        }
        aux->anterior->proximo = aux->proximo;
        aux->proximo->anterior = aux->anterior;
        l->qtd--;
        return aux;
    }
}

void mostraListaED(ListaDE *l) {
    if (numeroElementos(l) != 0) {
        Pessoa *aux = l->primeiro;
        while(aux != NULL ) {
            mostraPessoa(aux);
            aux = aux->proximo;
        }
    } else printf("\nLista Vazia!\n");
}

void mostraListaDE(ListaDE *l) {
    if (numeroElementos(l) != 0) {
        Pessoa *aux = l->ultimo;
        while(aux != NULL ) {
            mostraPessoa(aux);
            aux = aux->anterior;
        }
    } else printf("\nLista Vazia!\n");
}

void mostraPessoa(Pessoa *p) {
    if(p != NULL) printf("Pessoa: \n\tNome....: %s \n\tTelefone: %s \n\tIdade...: %d\n", p->nome, p->telefone, p->idade);
}

int numeroElementos(ListaDE *l) {
    return l->qtd;
}

void apagaListaInteira(ListaDE *l) {
    if (numeroElementos(l) != 0) for (int i = 1; i <= numeroElementos(l); i++) apagaPessoa(removeFinal(l));
}

void apagaPessoa(Pessoa *p) {
    if (p != NULL) free(p);
}
