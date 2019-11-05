#ifndef FORCA_H_INCLUDED
#define FORCA_H_INCLUDED

typedef struct noSecreto NoSecreto;
typedef struct noLetras  NoL;

NoSecreto *  inicializaListaSecreta();

NoSecreto * carregaListaArquivo(NoSecreto * l, char nomeArq[255]);

void imprimeListaSecreta(NoSecreto *l);

NoSecreto * inserePalavraSecreta(NoSecreto * l,char word[31],char subject [100]);

int temPalavraNaoUsada(NoSecreto *l);

NoSecreto * sorteiaPalavra(NoSecreto *l,NoSecreto * l2);

int quantos(NoSecreto * l);

NoL * crialetras(NoSecreto * l);

NoSecreto * retornaPalavraPos(NoSecreto *l, int pos);

int geraAleatorio(int maximo);

NoSecreto* retiraUmElemento(NoSecreto * l, char palavra[31]);
#endif // FORCA_H_INCLUDED
