#include <stdio.h>
#include <stdlib.h>
#include "forca.h"
#include "forca.c"
void exibe()
{
    printf("Desenvolvido por Luigi Beghini, Victor Rodrigo: 18146, 18154\n\n");
}

int main()
{
    exibe();
    NoSecreto * listaSecreta = inicializaListaSecreta();
    NoSecreto * sorteada;
    NoSecreto * usadas = inicializaListaSecreta();
    listaSecreta = carregaListaArquivo(listaSecreta,"palavras.dat");
    imprimeListaSecreta(listaSecreta);

      do{
        system("cls");
        exibe();
        imprimeListaSecreta(listaSecreta);

        sorteada= sorteiaPalavra(listaSecreta,usadas);
        if(sorteada!=NULL){
            printf("%s\n", sorteada->palavra);
            listaSecreta = retiraUmElemento(listaSecreta,sorteada->palavra);
        }else{
            printf("Não tem palavra disponível!\n\n");
        }
    }while(getchar()!='f');



    NoL * letras = inicializaListaSecreta();

    return 0;
}
