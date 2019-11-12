#ifndef FORCA_H_INCLUDED
#define FORCA_H_INCLUDED

struct noSecreto {
int status;
char palavra[31];
char assunto[100];
int num;
struct noSecreto * prox;
};

struct noLetras
{
    char letra;
    int estado;
    struct noSecreto * proximo;
};

typedef struct noSecreto NoSecreto;
typedef struct noLetras  NoL;

NoSecreto *  inicializaListaSecreta();

NoSecreto * carregaListaArquivo(NoSecreto * l, char nomeArq[255]);

void imprimeListaSecreta(NoSecreto *l);

NoSecreto * inserePalavraSecreta(NoSecreto * l,char word[31],char subject [100]);

int temPalavraNaoUsada(NoSecreto *l);

NoSecreto * sorteiaPalavra(NoSecreto *l);

NoL * crialetras(NoSecreto * l);

NoSecreto * retornaPalavraPos(NoSecreto *l, int pos);

int geraAleatorio(int maximo);

int tamanhoListaSecreta(NoSecreto *l);

NoSecreto* insere (NoSecreto* l, char i[31]);

NoSecreto* retiraUmElemento(NoSecreto * l, char palavra[31]);

int conta(char *s);
#endif // FORCA_H_INCLUDED
