#include <stdio.h>
#include <stdlib.h>
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
Pessoa *criaPessoa(char nome[], char telefone[] , int idade);
void menu();
void insereFinal(ListaDE *l, Pessoa *p);
void insereInicio(ListaDE *l, Pessoa *p);
void inserePosicao(ListaDE *l, Pessoa *p, int i);
void insereOrdenado(ListaDE *l, Pessoa *p);
Pessoa *removeFinal(ListaDE *l);
Pessoa *removeInicio(ListaDE *l);
Pessoa *removePosicao(ListaDE *l, int i);
void mostraListaED(ListaDE *l);
void mostraListaDE(ListaDE *l);
void mostraPessoa(Pessoa *p);
int numeroElementos(ListaDE *l);
void apagaListaInteira(ListaDE *l);
void apagaPessoa(Pessoa *p);
void ordenaListaBubbleSort(ListaDE *l);
void ordenaListaShellSort(ListaDE *l);
void trocaStr(char *str1, char *str2, size_t tam);
void trocaInt(int *x, int *y);
Pessoa *getPessoa(ListaDE *l, int pos);
void setPessoa(ListaDE *l, int pos, char nom[], char tel[], int id);

int main() {
    ListaDE *listaTelefone;
    listaTelefone = criaLista();
    Pessoa *marcia = criaPessoa("Marcia Ribeiro", "234567454", 34);
    insereFinal(listaTelefone, marcia);
    Pessoa *carla = criaPessoa("Carla Ribeiro", "345674543", 38);
    insereFinal(listaTelefone, carla);
    Pessoa *paula = criaPessoa("Paula Ribeiro", "456745434", 28);
    insereFinal(listaTelefone, paula);
    Pessoa *andre = criaPessoa("Andre Santos", "987654321", 42);
    insereFinal(listaTelefone, andre);
    Pessoa *daniel = criaPessoa("Daniel Silva", "987456123", 21);
    insereFinal(listaTelefone, daniel);
    Pessoa *marcio = criaPessoa("Marcio Ribeiro", "912367454", 45);
    insereFinal(listaTelefone, marcio);
    Pessoa *carlos = criaPessoa("Carlos Ribeiro", "345674888", 50);
    insereFinal(listaTelefone, carlos);
    Pessoa *nino = criaPessoa("Nino Acosta", "997117998", 81);
    insereFinal(listaTelefone, nino);
    Pessoa *fani = criaPessoa("Fani Acosta", "997117999", 78);
    insereFinal(listaTelefone, fani);
    Pessoa *jandira = criaPessoa("Jandira Minotto", "997112222", 55);
    insereFinal(listaTelefone, jandira);
    Pessoa *maria = criaPessoa("Maria Acosta", "997113333", 60);
    insereFinal(listaTelefone, maria);
    Pessoa *jose = criaPessoa("Jose Minotto", "991899889", 62);
    insereFinal(listaTelefone, jose);
    Pessoa *edson = criaPessoa("Renan Acosta", "997117933", 36);
    insereFinal(listaTelefone, edson);
    Pessoa *ariel = criaPessoa("Ariel Pinto", "999578599", 36);
    insereFinal(listaTelefone, ariel);
    Pessoa *marcelo = criaPessoa("Marcelo Silva", "999578128", 35);
    insereFinal(listaTelefone, marcelo);
    Pessoa *igor = criaPessoa("Igor Farias", "991889999", 35);
    insereFinal(listaTelefone, igor);
    Pessoa *luciano = criaPessoa("Luciano Gonçalves", "991512128", 41);
    insereFinal(listaTelefone, luciano);
    Pessoa *roberta = criaPessoa("Roberta Funchal", "997119900", 48);
    insereFinal(listaTelefone, roberta);
    Pessoa *andrea = criaPessoa("Andrea Oliveira", "981778128", 50);
    insereFinal(listaTelefone, andrea);
    Pessoa *samantha = criaPessoa("Samantha Greco", "997118888", 31);
    insereFinal(listaTelefone, samantha);

    float td1;
    float td2;
    clock_t t1;
    srand(time(NULL));

    menu();
    int opcao;
    scanf("%d", &opcao);
    while (opcao) {
        switch (opcao) {
            case 1:
                printf("\nMostrar a Lista original da Esquerda para Direita\n\n");
                mostraListaED(listaTelefone);
                break;
            case 2:
                printf("\nMostrar a Lista original da Direita para Esquerda\n\n");
                mostraListaDE(listaTelefone);
                break;
            case 3:
                printf("\nMostrar Lista Ordenada [Bubble Sort]\n\n");
                t1 = clock();
                ordenaListaBubbleSort(listaTelefone);
                t1 = clock() - t1;
                td1 = (float) t1 / CLOCKS_PER_SEC;
                mostraListaED(listaTelefone);
                printf("\n**********************************************\n");
                printf("Tempo Decorrido de Processamento: %f", td1);
                printf("\n**********************************************\n\n\n");
                break;
            case 4:
                printf("\nMostrar Lista Ordenada [Shell Sort]\n\n");
                t1 = clock();
                ordenaListaShellSort(listaTelefone);
                t1 = clock() - t1;
                td2 = (float) t1 / CLOCKS_PER_SEC;
                mostraListaED(listaTelefone);
                printf("\n**********************************************\n");
                printf("Tempo Decorrido de Processamento: %f", td2);
                printf("\n**********************************************\n\n\n");
                break;
            default:
                printf("\n\t\tOpcao inválida!!!\n");
                getchar();
                break;
        }
        menu();
        scanf("%d", &opcao);
    }
    apagaListaInteira(listaTelefone);
    free(listaTelefone);
    printf("\nLista Destruida!\n");
    printf("\t\t***************************************************\n");
    printf("\t\t********************* [FIM] ***********************\n");
    printf("\t\t***************************************************\n\n");
    return 0;
}

void menu() {
    printf("\t\t***************************************************\n");
    printf("\t\t********************* [LDE] ***********************\n");
    printf("\t\t***************************************************\n\n");
    printf("\t\t Renan Gomes Acosta - 11230237\n\n");
    printf("\n\t\tOPCOES:\n");
    printf("\n\t\t1 - Mostrar Lista - da esquerda para a direita");
    printf("\n\t\t2 - Mostrar Lista - da direita para a esquerda");
    printf("\n\t\t3 - Mostrar em ordem Alfabética [Bubble Sort]");
    printf("\n\t\t4 - Mostrar em ordem Alfabética [Shell Sort]");
    printf("\n\t\t0 - Sair\n");
    printf("\n\t\tOPCAO: ");
}

ListaDE *criaLista() {
    ListaDE *aux = (ListaDE *)malloc(sizeof(ListaDE));
    aux->primeiro = NULL;
    aux->ultimo = NULL;
    aux->qtd = 0;
    return aux;
}

Pessoa *criaPessoa(char nome[], char telefone[] , int idade) {
    Pessoa *aux = (Pessoa *)malloc(sizeof(Pessoa));
    strcpy(aux->nome, nome);
    strcpy(aux->telefone, telefone);
    aux->idade = idade;
    aux->anterior = NULL;
    aux->proximo = NULL;
    return aux;
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
    Pessoa *aux = l->primeiro;
    while(aux != NULL ) {
        mostraPessoa(aux);
        aux = aux->proximo;
    }
}

void mostraListaDE(ListaDE *l) {
    Pessoa *aux = l->ultimo;
    while(aux != NULL ) {
        mostraPessoa(aux);
        aux = aux->anterior;
    }
}

void mostraPessoa(Pessoa *p) {
    if(p != NULL) printf("Pessoa: \n\tNome: %s \n\tTelefone: %s \n\tIdade: %d\n",p->nome,p->telefone,p->idade);
}

int numeroElementos(ListaDE *l) {
    return l->qtd;
}


void apagaListaInteira(ListaDE *l) {
    for (int i = 1; i <= numeroElementos(l); i++) {
        apagaPessoa(removeFinal(l));
    }
}


void apagaPessoa(Pessoa *p) {
    if (p != NULL) free(p);
}


void ordenaListaBubbleSort(ListaDE *l) {
    Pessoa *pessoa1 = l->primeiro;
    while (pessoa1 != NULL) {
        Pessoa *pessoa2 = pessoa1->proximo;
        while (pessoa2 != NULL) {
            if (strcmp(pessoa1->nome, pessoa2->nome) > 0) {
                trocaInt(&pessoa1->idade, &pessoa2->idade);
                trocaStr(pessoa1->nome, pessoa2->nome, TAM_NOME);
                trocaStr(pessoa1->telefone, pessoa2->telefone, TAM_TELEFONE);
            }
            pessoa2 = pessoa2->proximo;
        }
        pessoa1 = pessoa1->proximo;
    }
}


void ordenaListaShellSort(ListaDE *l) {
    if (l != NULL && numeroElementos(l) > 1) {
        int tam = numeroElementos(l);
        int chave, k, i = (tam - 1) / 2;
        Pessoa *p1, *p2;
        while (i != 0) {
            do {
                chave = 1;
                for (k = 0; k < tam - 1; k++) {
                    p1 = getPessoa(l, k);
                    p2 = getPessoa(l, k + 1);
                    if (strcmp(p1->nome, p2->nome) > 0) {
                        trocaInt(&p1->idade, &p2->idade);
                        trocaStr(p1->nome, p2->nome, TAM_NOME);
                        trocaStr(p1->telefone, p2->telefone, TAM_TELEFONE);
                        chave = 0;
                    }
                }
            } while (chave == 0);
            i = i / 2;
        }
    }
}

void trocaStr(char *str1, char *str2, size_t tamanho) {
    static char temp[TAM_NOME];
    memcpy(temp, str1, tamanho);
    memcpy(str1, str2, tamanho);
    memcpy(str2, temp, tamanho);
}

void trocaInt(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

Pessoa *getPessoa(ListaDE *l, int pos) {
    if (l == NULL || pos < 0 || pos >= numeroElementos(l)) {
        printf("\nBusca inválida!\n");
        return NULL;
    }
    Pessoa *p = l->primeiro;
    if (pos != 0) for (int i = 1; i <= pos; i++) p = p->proximo;
    return p;
}

void setPessoa(ListaDE *l, int pos, char nom[], char tel[], int id) {
    if (l == NULL || pos < 0 || pos >= numeroElementos(l)) printf("\nOperação inválida!\n");
    else {
        Pessoa *p = l->primeiro;
        if (pos != 0) for (int i = 1; i <= pos; i++) p = p->proximo;
        strcpy(p->nome, nom);
        strcpy(p->telefone, tel);
        p->idade = id;
    }
}
