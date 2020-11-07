#include <stdio.h>
#include <stdlib.h>

struct listas{
 int num;
 struct listas *prox;
};

typedef struct listas listas;

int tam;

void inicia(listas *LISTA);
int menu(void);
void opcao(listas *LISTA, int op);
listas *criaNo();
void insereFim(listas *LISTA);
void insereInicio(listas *LISTA);
void exibe(listas *LISTA);
void libera(listas *LISTA);
void insere (listas *LISTA);
listas *retiraInicio(listas *LISTA);
listas *retiraFim(listas *LISTA);
listas *retira(listas *LISTA);


int main(void)
{
 listas *LISTA = (listas *) malloc(sizeof(listas));
 if(!LISTA){
  printf("SEM MEMÓRIA DISPONÍVEL!\n");
  exit(1);
 }else{
 inicia(LISTA);
 int opt;

 do{
  opt=menu();
  opcao(LISTA,opt);
 }while(opt);

 free(LISTA);
 return 0;
 }
}

void inicia(listas *LISTA)
{
 LISTA->prox = NULL;
 tam=0;
}

int menu(void)
{
 int opt;

         printf ("\t=============================================================\n");
         printf ("\t=========================  LISTAS  ==========================\n");
         printf ("\t=============================================================\n");
         printf ("\t [Renan Gomes Acosta - 11230237] \n\n");

 printf("\t Por favor, escolha uma opção:\n\n");
 printf("\t 0. Sair\n");
 printf("\t 1. Zerar lista\n");
 printf("\t 2. Exibir lista\n");
 printf("\t 3. Adicionar no inicio da lista\n");
 printf("\t 4. Adicionar no fim da lista\n");
 printf("\t 5. Escolher onde inserir na lista\n");
 printf("\t 6. Retirar do inicio da lista\n");
 printf("\t 7. Retirar do fim da lista\n");
 printf("\t 8. Escolher de onde retirar da lista\n");
 printf("\t Opcao: \n\n");
 scanf("%d", &opt);

 return opt;

}

void opcao(listas *LISTA, int op)
{
 listas *tmp;
 switch(op){
  case 0:
   libera(LISTA);
   printf ("\t=============================================================\n");
   printf ("\t====================  FIM DO PROGRAMA  ======================\n");
   printf ("\t=============================================================\n");
   break;

  case 1:
   libera(LISTA);
   inicia(LISTA);
   printf("\n\n LISTA ZERADA! \n\n");
   break;

  case 2:
   exibe(LISTA);
   break;

  case 3:
   insereInicio(LISTA);
   break;

  case 4:
   insereFim(LISTA);
   break;

  case 5:
   insere(LISTA);
   break;

  case 6:
   tmp= retiraInicio(LISTA);
   printf("\n RETIRADO: %3d \n\n", tmp->num);
   break;

  case 7:
   tmp= retiraFim(LISTA);
   printf("\n RETIRADO: %3d \n\n", tmp->num);
   break;

  case 8:
   tmp= retira(LISTA);
   printf("\n RETIRADO: %3d \n\n", tmp->num);
   break;

  default:
   printf("\n COMANDO INVÁLIDO \n\n");
 }
}

int vazia(listas *LISTA)
{
 if(LISTA->prox == NULL)
  return 1;
 else
  return 0;
}

listas *aloca()
{
 listas *novo=(listas *) malloc(sizeof(listas));
 if(!novo){
  printf("\n SEM MEMÓRIA DISPONÍVEL! \n");
  exit(1);
 }else{
  printf("\n NOVO ELEMENTO: ");
  scanf("%d", &novo->num);
  return novo;
 }
}


void insereFim(listas *LISTA)
{
 listas *novo=aloca();
 novo->prox = NULL;

 if(vazia(LISTA))
  LISTA->prox=novo;
 else{
  listas *tmp = LISTA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
 tam++;
}

void insereInicio(listas *LISTA)
{
 listas *novo=aloca();
 listas *oldHead = LISTA->prox;

 LISTA->prox = novo;
 novo->prox = oldHead;

 tam++;
}

void exibe(listas *LISTA)
{
 system("clear");
 if(vazia(LISTA)){
  printf("\n LISTA VAZIA! \n\n");
  return ;
 }

 listas *tmp;
 tmp = LISTA->prox;
 printf("LISTA:");
 while( tmp != NULL){
  printf("%5d", tmp->num);
  tmp = tmp->prox;
 }
 printf("\n        ");
 int count;
 for(count=0 ; count < tam ; count++)
  printf("  ^  ");
 printf("\nORDEM:");
 for(count=0 ; count < tam ; count++)
  printf("%5d", count+1);


 printf("\n\n");
}

void libera(listas *LISTA)
{
 if(!vazia(LISTA)){
  listas *proxlistas,
     *atual;

  atual = LISTA->prox;
  while(atual != NULL){
   proxlistas = atual->prox;
   free(atual);
   atual = proxlistas;
  }
 }
}

void insere(listas *LISTA)
{
 int pos, count;
 printf("\n EM QUE POSIÇÃO, [de 1 ate %d] VOCE DESEJA INSERIR NA LISTA: ", tam);
 scanf("%d", &pos);

 if(pos>0 && pos <= tam){
  if(pos==1)
   insereInicio(LISTA);
  else{
   listas *atual = LISTA->prox,
     *anterior=LISTA;
   listas *novo=aloca();

   for(count=1 ; count < pos ; count++){
     anterior=atual;
     atual=atual->prox;
   }
   anterior->prox=novo;
   novo->prox = atual;
   tam++;
  }

 }else
  printf("\n ELEMENTO INVÁLIDO \n\n");
}

listas *retiraInicio(listas *LISTA)
{
 if(LISTA->prox == NULL){
  printf("\n A LISTA JÁ ESTÁ VAZIA \n\n");
  return NULL;
 }else{
  listas *tmp = LISTA->prox;
  LISTA->prox = tmp->prox;
  tam--;
  return tmp;
 }

}

listas *retiraFim(listas *LISTA)
{
 if(LISTA->prox == NULL){
  printf("\n A LISTA JÁ ESTA VAZIA \n\n");
  return NULL;
 }else{
  listas *ultimo = LISTA->prox,
    *penultimo = LISTA;

  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }

  penultimo->prox = NULL;
  tam--;
  return ultimo;
 }
}

listas *retira(listas *LISTA)
{
 int opt,count;
 printf("\n QUE POSIÇÃO, [de 1 ate %d] VOCE DESEJA RETIRAR DA LISTA: ", tam);
 scanf("%d", &opt);

 if(opt>0 && opt <= tam){
  if(opt==1)
   return retiraInicio(LISTA);
  else{
   listas *atual = LISTA->prox,
     *anterior=LISTA;

   for(count=1 ; count < opt ; count++){
    anterior=atual;
    atual=atual->prox;
   }

  anterior->prox=atual->prox;
  tam--;
  return atual;
  }

 }else{
  printf("\n ELEMENTO INVÁLIDO \n\n");
  return NULL;
 }
}
