#include <stdio.h>
#include <string.h>
#include <stlib.h>
#include "forca.h"

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

NoSecreto * inicializaListaSecreta()
{
    return NULL;
}

NoSecreto * inserePalavraSecreta(NoSecreto * l,char word[31],char subject[100])
{
  NoSecreto * novo;
  novo = (NoSecreto *) malloc(sizeof(NoSecreto));
  novo->status = 0;
  strcpy(novo->assunto,subject);
  strcpy(novo->palavra,word);
  novo->prox = l;
  l = novo;
  return l;
}
void imprimeListaSecreta(NoSecreto *l)
{
    NoSecreto * p;
    for (p = l; p!=NULL; p=p->prox)
    {
        printf("%0d | %30s | %30s | %d\n", p->status,p->palavra,p->assunto,p->num);
    }
}
NoSecreto * carregaListaArquivo(NoSecreto * l, char nomeArq[255])
{
    const char ch[2]=";";
    char * token;
    int status;
    char palavra[31];
    char assunto[101];
    char * linha[1024];
    int n=0;
    FILE * fWords;

    fWords = fopen(nomeArq,"r");
    if(fWords==NULL){
        printf("Falha ao acessar base de dados!!!\n\n");
        exit(0);
    }
    while(fgets(linha,1024,fWords))
    {
        token = strtok(linha,ch);
        if(token!=NULL)
        {
             strcpy(palavra,token);
        }
        token=strtok(NULL,ch);
        if(token!=NULL)
        {
            strcpy(assunto,token);
        }
        l = inserePalavraSecreta(l,palavra, assunto);
        l->num=n;
        n++;
    }

    fclose(fWords);
    return l;
}
int quantos(NoSecreto * l)
{
    NoSecreto * p;
    int y=0;
    for (p = l; p!=NULL; p=p->prox)
    {
       y++;
    }
    return y;
}

int temPalavraNaoUsada(NoSecreto *l)
{
    NoSecreto *p;
    for(p=l;p!=NULL;p=p->prox){
        if(p->status==0) return 1;
    }
    return 0;
}

NoSecreto * sorteiaPalavra(NoSecreto *l,NoSecreto *l2)
{
    int tam = quantos(l);
    int aleatorio=0;
    int tentativas = 0;
    NoSecreto * p;

    while(temPalavraNaoUsada(l)){
        aleatorio = geraAleatorio(tam);
        p = retornaPalavraPos(l,aleatorio);
        if(p->status==0){
          {
            p->status = 1;
            return p;
            l2 = inserePalavraSecreta(p,p->palavra,p->assunto);

          }

        }
    }
    return NULL;
}

NoSecreto * retornaPalavraPos(NoSecreto *l, int pos)
{
    int n=1;
    NoSecreto *p;
    for(p=l; p!=NULL; p=p->prox)
    {
        if(n==pos) break;
        n++;
    }
    return p;
}

int geraAleatorio(int maximo)
{
    time_t t;
    int n=0;
    srand((unsigned) time(&t));
    n = (rand() % maximo)+1;
    return n;
}

NoSecreto * retiraUmElemento(NoSecreto * l, char palavra[31])
{
    NoSecreto * ant = NULL;
    NoSecreto * p = l;

    while(p != NULL && p->palavra != palavra)
    {
        ant = p;
        p = p->prox;
    }
    if(ant == NULL)
       {
            l = p->prox;
       }
    else
    {
       ant->prox = p->prox;
    }
    free(p);
    return l;
}
/*NoL * crialetras(NoSecreto * l)
{
    NoSecreto * u = escolhealeatorio(l);

}*/

