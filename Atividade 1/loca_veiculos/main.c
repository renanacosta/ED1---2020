# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <locale.h>

/*CARROS CADASTRADOS PARA LOCAÇÃO */

int Fusca = 1;
int Chevette = 1;
int Kombi = 1;
int Belina = 1;
int Brasilia = 1;
int sair = 1;
char plFusc[30]= "FUS2017", plChev[30]= "CHE2017", plKomb[30]="KOM2017",plBeli[30]="BEL2017", plBras[30]="BRA2017";
const int HORA_LOCACAO = 12, LOCACAO = 1, DEVOLUCAO = 0;

time_t timer;
struct tm dLocFusca, dDevFusca, dLocChevette,dDevChevette, dLocKombi, dDevKombi, dLocBelina, dDevBelina, dLocBrasilia, dDevBrasilia;



resolverDatas(struct tm *date1, struct tm *date2, int diasAMais)
    {

    timer=time(NULL);
    (*date1) = *gmtime( &timer ) ;
    printf("\t Data Locação: \t\t%02d/%02d/%d\n",(*date1).tm_mday,(*date1).tm_mon+1,(*date1).tm_year+1900);
    (*date2).tm_year = (*date1).tm_year;
    (*date2).tm_mon = (*date1).tm_mon;
    (*date2).tm_mday = (*date1).tm_mday + diasAMais;
    timer = mktime( (*&date2) ) ;
    (*date2) = *gmtime( &timer ) ;
    printf("\t Data Devolução: \t%02d/%02d/%d\n\n",(*date2).tm_mday,(*date2).tm_mon+1,(*date2).tm_year+1900);

    }

void autolocadora()
    {

/*TÍTULO DO PROGRAMA */


         printf ("\t=============================================================\n");
         printf ("\t===================  RENAN AUTOLOCADORA  ====================\n");
         printf ("\t=============================================================\n");
         printf("\t [Renan Gomes Acosta - 11230237]\n\n");
    }

void printCatalogo()
{
         autolocadora();

         /*AQUI MOSTRA TODOS OS CARROS LIVRES PARA SEREM LOCADOS */


         printf ("\t CARROS DISPONÍVEIS PARA LOCAÇÃO:  \n\n");
         if (Fusca == 1){printf ("\t Fusca  \n");}
         if (Chevette == 1){printf ("\t Chevette  \n");}
         if (Kombi == 1){printf ("\t Kombi  \n");}
         if (Belina == 1){printf ("\t Belina  \n");}
         if (Brasilia == 1){printf ("\t Brasilia  \n");}
         printf ("\n\n");

        /*AQUI MOSTRA TODOS OS CARROS QUE FORAM LOCADOS */


         printf ("\t CARROS NÃO DISPONÍVEIS | DATA DE LOC | PREVISÃO DE ENTREGA:  \n\n");
         if (Fusca == 0){printf ("\t Fusca  \t\t  %02d/%02d/%d\t%02d/%02d/%d às %d:00h\n",dLocFusca.tm_mday,dLocFusca.tm_mon+1,dLocFusca.tm_year+1900, dDevFusca.tm_mday,dDevFusca.tm_mon+1,dDevFusca.tm_year+1900, HORA_LOCACAO);}
         if (Chevette == 0){printf ("\t Chevette    \t\t  %02d/%02d/%d\t%02d/%02d/%d às %d:00h\n",dLocChevette.tm_mday,dLocChevette.tm_mon+1,dLocChevette.tm_year+1900, dDevChevette.tm_mday,dDevChevette.tm_mon+1,dDevChevette.tm_year+1900, HORA_LOCACAO);}
         if (Kombi == 0){printf ("\t Kombi   \t\t  %02d/%02d/%d\t%02d/%02d/%d às %d:00h\n",dLocKombi.tm_mday,dLocKombi.tm_mon+1,dLocKombi.tm_year+1900, dDevKombi.tm_mday,dDevKombi.tm_mon+1,dDevKombi.tm_year+1900, HORA_LOCACAO);}
         if (Belina == 0){printf ("\t Belina  \t\t  %02d/%02d/%d\t%02d/%02d/%d às %d:00h\n",dLocBelina.tm_mday,dLocBelina.tm_mon+1,dLocBelina.tm_year+1900, dDevBelina.tm_mday,dDevBelina.tm_mon+1,dDevBelina.tm_year+1900, HORA_LOCACAO);}
         if (Brasilia == 0){printf ("\t Brasilia    \t\t  %02d/%02d/%d\t%02d/%02d/%d às %d:00h\n",dLocBrasilia.tm_mday,dLocBrasilia.tm_mon+1,dLocBrasilia.tm_year+1900, dDevFusca.tm_mday,dDevBrasilia.tm_mon+1,dDevBrasilia.tm_year+1900, HORA_LOCACAO);}
         printf ("\n\n");

}
int printMenuPrincipal()
{
         autolocadora();

         /*MENU PRINCIPAL DO PROGRAMA */

         printf("\t POR FAVOR, ESCOLHA UMA OPÇÃO:\n\n");
         printf ("\t (1) Consultar Veículos Disponíveis\n");
         printf ("\t (2) Alugar Veículo\n");
         printf ("\t (3) Devolver Veículo\n");
         printf ("\t (0) Sair\n\n");

         int x;
         scanf("%i", &x);

         if(x<0 ||x>3)
            {

                printf ("\n\n\t Opção Inválida. Por gentileza, digite uma opção válida:\n\n");
                system("pause");
                printMenuPrincipal();
            }
         return x;
}
int printMenuLocacao()
{
         autolocadora();

         printf ("\t Selecione o veículo:  \n\n");
         printf ("\t (1) Fusca  \n");
         printf ("\t (2) Chevette    \n");
         printf ("\t (3) Kombi    \n");
         printf ("\t (4) Belina  \n");
         printf ("\t (5) Brasilia    \n");
         printf ("\t (0) Sair    \n");

         int x;
         scanf("%i", &x);
         if(x<0 ||x>5)
            {
                printf ("\n\n\t Opção Inválida. Por gentileza, digite uma opção válida:\n\n");
                system("pause");
                printMenuLocacao();
            }
         return x;
}

void printTicket(char* placa, float valor, struct tm *dataLocacao, struct tm *dataDevolucao){

/*AQUI MOSTRA O INFORMATIVO CONTENDO OS DADOS DO VEÍCULO, COM O VALOR E AS DATAS DE LOCAÇÃO E DEVOLUÇÃO */


    printf("\t======================TICKET DO CLIENTE======================\n");
    printf("\t PLACA DO VEÍCULO:\t\t %s\n",placa);
    printf("\t VALOR DA LOCAÇÃO:\t\t R$ %.2f\n",valor);
    printf("\t DATA LOCAÇAO:\t\t\t %02d/%02d/%d às %d:00h\n",(*dataLocacao).tm_mday,(*dataLocacao).tm_mon+1,(*dataLocacao).tm_year+1900, HORA_LOCACAO);
    printf("\t DATA DEVOLUÇÃO:\t\t %02d/%02d/%d às %d:00h\n",(*dataDevolucao).tm_mday,(*dataDevolucao).tm_mon+1,(*dataDevolucao).tm_year+1900, HORA_LOCACAO);
    printf("\t=================REIMPRESSÃO NAO DISPONÍVEL==================\n\n");

}

/*AQUI FAZ O CALCULO NA HORA DA DEVOLUÇÃO SE TEVE ATRASO, SOMA O VALOR AO VALOR DA LOCAÇÃO */


void verificarAtrasoDevolucao(int valorDiaria )
{
    int aux;
    float multa;
    printf("\n\t Horas de atraso na entrega:(se não houve atraso digite 0)\n\n");
    scanf("%d", &aux);
    if(aux > 0)
        {
            multa = aux * (valorDiaria/24);
            printf("\t MULTA POR ATRASO: R$ %.2f\n\n", multa);
        }else if(aux == 0)
            {
                printf("\t NÃO HÁ MULTAS A PAGAR.\n\n");
            }
}

int verificaDiariaGratis(int x){
	int opcao;
	if(x >= 5){
		printf("\t Uma diária de cortesia? 1 - sim, OUTRO NÚMERO - não.\n\n");
		scanf("%d", &opcao);

		if(opcao == 1){

			x = x + 1;
		}
	}

	return x;
}
void locacaoFusca()
{
float valorLocacao, x;
int qtdDias;

                   autolocadora();
                   printf("\t Modelo Escolhido:\t Fusca        \n");
                   printf("\t Placa:\t\t\t %s\n",plFusc);
                   printf("\t Valor da diaria:\t R$ 240,00                  \n");
                   printf("\t Digite a quantidade de dias de locação:\n");
                   scanf ("%d",&qtdDias);

                   valorLocacao = 240 * qtdDias;

                   printf ("\t Valor da locação : R$%.2f \n\n",valorLocacao );

                   verificarDesconto(&valorLocacao);

                   qtdDias = verificaDiariaGratis(qtdDias);

                   resolverDatas(&dLocFusca, &dDevFusca, qtdDias);

                   printf ("\t Para confirma digite 1 Cancelar 2: \n");

                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        Fusca=0;
                        system("cls");
                        autolocadora();
                        printf ("\t LOCAÇÃO CONFIRMADA. \n\n"
                                "\t Modelo Escolhido: FUSCA.\n\n");


                        printTicket(plFusc, valorLocacao, &dLocFusca, &dDevFusca);

                   }
                   else if (x == 2)
                   {
                        system("cls");
                        autolocadora();
                        printf ("\t LOCAÇÃO CANCELADA!\n\n");
                   }

}

void devolucaoFusca()
{
float valorLocacao, x;

                   autolocadora();

                   printf ("\t MODELO EM DEVOLUÇÃO: Fusca.        \n");

                   verificarAtrasoDevolucao(240);

                   printf ("\t Para confirma digite 1 Cancelar 2: \n");

                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        Fusca=1;
                        system("cls");
                        autolocadora();
                        printf ("\t DEVOLUÇÃO CONFIRMADA. \n\n");
                        printf ("\t MODELO EM DEVOLUÇÃO: Fusca. \n\n");
                   }
                   else if (x == 2)
                   {
                        printf ("\t DEVOLUÇÃO CANCELADA!\n\n");
                   }

 }

void locacaoChevette()
{
float valorLocacao, x;
int qtdDias;

                   autolocadora();

                   printf ("\t Modelo Escolhido:\t Chevette   \n");
                   printf("\t Placa:\t\t\t %s\n",plChev);
                   printf ("\t Valor da diaria:\t R$ 240,00          \n");
                   printf ("\t Digite a quantidade de dias de locação:\n");
                   scanf ("%d", &qtdDias);

                   valorLocacao = 240 * qtdDias;

                   printf ("\t Valor da locação : R$%.2f \n",valorLocacao );

                   verificarDesconto(&valorLocacao);

		   qtdDias = verificaDiariaGratis(qtdDias);

                   resolverDatas(&dLocChevette, &dDevChevette, qtdDias);

                   printf ("\t Para confirma digite 1 Cancelar 2: \n");
                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        Chevette=0;
                        system("cls");
                        autolocadora();
                        printf ("\t LOCAÇÃO CONFIRMADA. \n\n"
                                "\t Modelo Escolhido: CHEVETTE.\n\n");

                        printTicket(plChev, valorLocacao, &dLocChevette, &dDevChevette);

                   }
                   else if (x == 2)
                   {
                        printf ("\t LOCAÇÃO CANCELADA!\n\n");
                   }

}

void devolucaoChevette()
{
float valorLocacao, x;

                   autolocadora();

                   printf ("\t MODELO EM DEVOLUÇÃO: Chevette.          \n");

                   verificarAtrasoDevolucao(240);

                   printf ("\t Para confirma digite 1 Cancelar 2: \n");

                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        Chevette=1;
                        system("cls");
                        autolocadora();
                        printf ("\t DEVOLUÇÃO CONFIRMADA. \n\n");
                        printf ("\t MODELO EM DEVOLUÇÃO: Chevette. \n\n");

                   }
                   else if (x == 2)
                   {
                        printf ("\t DEVOLUÇÃO CANCELADA!\n\n");

                   }

 }


void locacaoKombi()
{
float valorLocacao, x;
int qtdDias;

                   autolocadora();

                   printf ("\t Modelo Escolhido:\t Kombi\n");
                   printf("\t Placa:\t\t\t %s\n",plKomb);
                   printf ("\t Valor da diaria:\t R$ 240,00    \n");
                   printf ("\t Digite a quantidade de dias de locação:\n");
                   scanf ("%d", &qtdDias);

                   valorLocacao = 240 * qtdDias;

                   printf ("\t Valor da locação : R$%.2f \n",valorLocacao );

                   verificarDesconto(&valorLocacao);

                   qtdDias = verificaDiariaGratis(qtdDias);

                   resolverDatas(&dLocKombi, &dDevKombi, qtdDias);

                   printf ("\t Para confirmar digite 1 Cancelar 2: \n");
                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        Kombi=0;
                        system("cls");
                        autolocadora();
                        printf ("\t LOCAÇÃO CONFIRMADA. \n"
                                "\t Modelo Escolhido: KOMBI.\n\n");

                        printTicket(plKomb, valorLocacao, &dLocKombi, &dDevKombi);

                   }
                   else if (x == 2)
                   {
                        printf ("\t LOCAÇÃO CANCELADA!\n");

                   }

 }

void devolucaoKombi()
{
float valorLocacao, x;

                   autolocadora();

                   printf ("\t MODELO EM DEVOLUÇÃO: Kombi.\n");

                   verificarAtrasoDevolucao(240);

                   printf ("\t Para confirmar digite 1 Cancelar 2: \n");
                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        Kombi=1;
                        system("cls");
                        autolocadora();
                        printf ("\t DEVOLUÇÃO CONFIRMADA. \n\n");
                        printf ("\t MODELO EM DEVOLUÇÃO: Kombi. \n\n");

                   }
                   else if (x == 2)
                   {
                        printf ("\t DEVOLUÇÃO CANCELADA!\n");

                   }

 }



void locacaoBelina()
{
float valorLocacao, x;
int qtdDias;

                   autolocadora();

                   printf ("\t Modelo Escolhido:\t Belina        \n");
                   printf("\t Placa:\t\t\t %s\n",plBeli);
                   printf ("\t Valor da diaria:\t R$ 240,00               \n");
                   printf ("\t Digite a quantidade de dias de locação:     \n");
                   scanf ("%d", &qtdDias);

                   valorLocacao = 240 * qtdDias;

                   printf ("\t Valor da locação : R$%.2f \n",valorLocacao );

                   verificarDesconto(&valorLocacao);

                   qtdDias = verificaDiariaGratis(qtdDias);

	           resolverDatas(&dLocBelina, &dDevBelina, qtdDias);

                   printf ("\t Para confirma digite 1 Cancelar 2: \n");
                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        Belina=0;
                        system("cls");
                        autolocadora();
                        printf ("\t LOCAÇÃO CONFIRMADA. \n\n"
                                "\t Modelo Escolhido: BELINA.\n\n");

                        printTicket(plBeli, valorLocacao, &dLocBelina, &dDevBelina);

                   }
                   else if (x == 2)
                   {
                        printf ("\t LOCAÇÃO CANCELADA!\n\n");
                   }

 }

void devolucaoBelina()
{
float valorLocacao, x;

                   autolocadora();

                   printf ("\t MODELO EM DEVOLUÇÃO: Belina.        \n");

                   verificarAtrasoDevolucao(240);

                   printf ("\t Para confirma digite 1 Cancelar 2: \n");
                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        Belina=1;
                        system("cls");
                        autolocadora();
                        printf ("\t DEVOLUÇÃO CONFIRMADA. \n\n");
                        printf ("\t MODELO EM DEVOLUÇÃO: Belina. \n\n");


                   }
                   else if (x == 2)
                   {
                        printf ("\t DEVOLUÇÃO CANCELADA!\n\n");
                   }

 }


void locacaoBrasilia()
{
float valorLocacao, x;
int qtdDias;

                   autolocadora();

                   printf ("\t Modelo Escolhido:\t Brasilia       \n");
                   printf("\t Placa:\t\t\t %s\n",plBras);
                   printf ("\t Valor da diaria:\t R$ 240,00              \n");
                   printf ("\t Digite a quantidade de dias de locação:\n");
                   scanf ("%d", &qtdDias);

                   valorLocacao = 240 * qtdDias;

                   printf ("\t Valor da locação : R$%.2f \n",valorLocacao );

                   verificarDesconto(&valorLocacao);

                   qtdDias = verificaDiariaGratis(qtdDias);

                   resolverDatas(&dLocBrasilia, &dDevBrasilia, qtdDias);

                   printf ("\t Para confirma digite 1 Cancelar 2: \n");
                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        Brasilia=0;
                        system("cls");
                        autolocadora();
                        printf ("\t LOCAÇÃO CONFIRMADA.\n\n"
                                "\t Modelo Escolhido: BRASILIA.\n\n");

                        printTicket(plBras, valorLocacao, &dLocBrasilia, &dDevBrasilia);


                   }
                   else if (x == 2)
                   {
                        printf ("\t LOCAÇÃO CANCELADA!\n\n");
                   }

}

void devolucaoBrasilia()
{
float valorLocacao, x;

                   autolocadora();

                   printf ("\t MODELO EM DEVOLUÇÃO: Brasilia         \n");

                   verificarAtrasoDevolucao(240);

                   printf ("\t Para confirma digite 1 Cancelar 2: \n");
                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        Brasilia=1;
                        system("cls");
                        autolocadora();
                        printf ("\t DEVOLUÇÃO CONFIRMADA. \n\n");
                        printf ("\t MODELO EM DEVOLUÇÃO: Brasilia. \n\n");

                   }
                   else if (x == 2)
                   {
                        printf ("\t DEVOLUÇÃO CANCELADA!\n\n");
                   }

}

void alugarVeiculo(int menuItem)
{

    int aux = verificarStatusVeiculo(menuItem, LOCACAO);

    switch(aux)
    {
        case 1:
            locacaoFusca();
            break;
        case 2:
            locacaoChevette();
            break;
        case 3:

            locacaoKombi();
            break;
        case 4:
            locacaoBelina();
            break;
        case 5:
            locacaoBrasilia();
            break;
    }
}

void devolverVeiculo(int menuItem)
{
    int aux = verificarStatusVeiculo(menuItem, DEVOLUCAO);

    switch(aux)
    {
        case 1:
            devolucaoFusca();
            break;
        case 2:
            devolucaoChevette();
            break;
        case 3:
            devolucaoKombi();
            break;
        case 4:
            devolucaoBelina();
            break;
        case 5:
            devolucaoBrasilia();
            break;
    }

}

void escolhaMenuPrincipal(int escolha)
{
   switch(escolha)
   {
       case 1:
           printCatalogo();
           break;
       case 2:
           alugarVeiculo(printMenuLocacao());

           break;
       case 3:
           devolverVeiculo(printMenuLocacao());

           break;
       case 0:

           break;
   }
}

int verificaEntradaUmOuDois(int valor)
{
    if (valor<1)
        {
            printf("\t Por gentileza, digite 1 ou 2.\n");
            scanf("%i", &valor);
            verificaEntradaUmOuDois(valor);

        }else if(valor>2)
        {
            printf("\t Por gentileza, digite 1 ou 2.\n");
            scanf("%i", &valor);
            verificaEntradaUmOuDois(valor);

        }else

    return valor;
}

int verificarStatusVeiculo(int idMenu, int evento)
{
    int carro;

    int aux = idMenu;

    switch(idMenu)
    {
        case 1:
            carro = Fusca;
            break;
        case 2:
            carro = Chevette;
            break;
        case 3:
            carro = Kombi;
            break;
        case 4:
            carro = Belina;
            break;
        case 5:
            carro = Brasilia;
            break;
    }

    if(evento == 1)
    {
        switch(carro)
        {
            case 0:
                printf("\t VEÍCULO INDISPONÍVEL/ALUGADO.\n\n"
                        "\t LOCAÇÃO NÃO PODE SER FINALIZADA\n\n");

                aux = 0;
                break;
        }
    }
    if(evento == 0)
    {
        switch(carro)
        {
            case 1:
                printf("\t VEÍCULO NÃO ESTÁ ALUGADO.\n\n"
                        "\t DEVOLUÇÃO NÃO PODE SER FINALIZADA\n\n");
                aux = 0;
                break;
        }
    }

    return aux;
}

int verificarSair(int x ){

    if (x == 1)
        {
            return x;
        }else
        {

            printf ("\n\n\n");
            printf ("\t=============================================================\n");
            printf ("\t===================  PROGRAMA FINALIZADO  ===================\n");
            printf ("\t=============================================================\n\n");
            printf("\t\t\t Desenvolvedor:\n");
            printf("\t\t\t Renan Gomes Acosta\n");
	        printf ("\n\n\n");

            return 0;
    }

}

/*VERIFICAÇÃO DE DESCONTO A SER APLICADO AO VALOR DA LOCAÇÃO CASO OCORRA */


void verificarDesconto(float *valor)
{
    int x;
    printf("\t APLICAR DESCONTO.\n");
    printf("\t (1)Idoso ou Deficiente.\n");
    printf("\t (2)Empresa parceira.\n");
    printf("\t (0)Sem desconto.\n");

    scanf("%i", &x);

    while (x<0 || x>2)
        {
            printf("\t Por gentileza, digite 1, 2 ou 0.\n\n");
            scanf("%i", &x);

        }
        if (x == 1)
        {
            printf("\t Valor da locação com 10%% de Desconto: R$%.2f\n\n", *valor*0.9);
            *valor = *valor*0.9;

        }else if (x == 2)
        {
            printf("\t Valor da locação com 5%% de Desconto: R$%.2f\n\n", *valor*0.95);
            *valor = *valor*0.95;
        }else if (x == 0)
        {
            *valor = *valor*1.0;
        }

}




void main ()
{

	setlocale(LC_ALL, "Portuguese");

do{
        int menuItem;


        menuItem = printMenuPrincipal();

        escolhaMenuPrincipal(menuItem);


/*FUNÇÃO ENCERRAR PROGRAMA */

        printf("\t Menu principal-DIGITE 1 - Sair do programa - OUTRO NÚMERO.\n");
        scanf("%i", &sair);

        sair = verificarSair(sair);

    }
    while(sair == 1);
      system (" pause ");
}

