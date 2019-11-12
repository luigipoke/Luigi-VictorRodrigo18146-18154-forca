#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "forca.h"

void exibe()
{
    printf("Desenvolvido por Luigi Beghini, Victor Rodrigo: 18146, 18154\n\n");
}

int main()
{
    int num;
    char name[20] = "";
    int c = 0;
    int vamo = 0;
    char letraUnica;
    char  auxiliar;
    char  auxiliar1[31];
    int contar = 0;

        do{
        system("cls");
        printf("Escolha uma das opcoes abaixo:\n\n");

    printf("1. Configuracao, 2. Jogar, 0. Sair\n");
    scanf("%d", &num);

    if(num == 1)
        {
        printf("\n Nos diga seu nome:\n");
        scanf("%s", name);
        printf("\nBem-vindo(a) %s!\n", name);
    }
    else if (num == 2)
    {
    int b = 0;
    exibe();
    NoSecreto * lstSecreta = inicializaListaSecreta();
    NoSecreto * sorteada;
    lstSecreta = carregaListaArquivo(lstSecreta,"palavras.dat");
    imprimeListaSecreta(lstSecreta);

      do{
        system("cls");
        sorteada = sorteiaPalavra(lstSecreta);

        if(sorteada!=NULL)
            {
                strcpy(auxiliar1, sorteada->palavra);
            c = conta(sorteada->palavra);

            for(int i = 0; i<c; i++)
            {
                    sorteada->palavra[i] = '*';
            }
            for(int x = 0; x<c*3; x++){

                    vamo = 0;
           if(strcmp(auxiliar1,sorteada->palavra) == 0)
                {
                    printf("\nVoce achou a palavra\n");
                    vamo = 1;
                    break;
                }
                else
                    {
            contar = contar+1;
            exibe();
            printf("%s\n", sorteada->palavra);
            printf("Assunto: %s\n",sorteada->assunto);

            printf("Digite uma letra:\n");

            scanf("%c",&letraUnica);

            system("cls");

            fflush(stdin);

            for(int i = 0; i<c; i++)
                {
                if(auxiliar1[i] == letraUnica)
                {
                    sorteada->palavra[i] = auxiliar1[i];
                }

            }
                }
            }
            if(vamo == 1)
            {
            system("cls");
            printf("Parabens %s!", name);
            printf("\nEncontrou a palavra em %d tentativas\n",contar);
            printf("Escolhendo nova palavra........\n");
            contar = 0;
            }
            else{
            system("cls");
            printf("\nEsgotou tentativas\n");
            printf("Numero de tentativas: %d\n",contar);
            printf("Escolhendo nova palavra........\n");
            }

            lstSecreta = retiraUmElemento(lstSecreta,sorteada->palavra);
            auxiliar = lstSecreta;
        }
        else
            {
            printf("Nao existe palavra disponivel!\n\n");
            b = 1;



          }
       }
       while(getchar()!='f' && b == 0);

      }


    }
    while(num != 0);

    return 0;
}
