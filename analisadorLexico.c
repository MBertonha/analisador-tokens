#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define VARIAVEL 556
#define OPERANDO 557
#define OPERADOR 558
#define MAX 50


typedef struct token{
  int tipo;
  char conteudo;
}TOKENS;

typedef struct{
    TOKENS A[MAX];
    int nroElem;
}LISTA;


void inicializaLista(LISTA *l){
    l->nroElem = 0;
}

void exibirLista(LISTA *l, TOKENS *tk){
    int i;
    if(l->nroElem == 0){
        printf("Lista Vazia..\n");
        return;
    }
    for(i=0;i<l->nroElem;i++){
        printf("\n\nConteudo: %c\n", l->A[i].conteudo);
        printf("Tipo: %d\n", l->A[i].tipo);
    }
}

void insere(LISTA *l, TOKENS *tk){
    char expr[10];
    int i,retorno,retorno1,retorno2;
    printf("Insira uma expressao ( FORMATO: 2+2; )\n");
    gets(expr);
    fflush(stdin); //usado para limpar o buffer
    for(i=0; i<10; i++){
        if(expr[i] == ';'){
            return;
        }
        l->A[i].conteudo = expr[i];
        retorno = isNumber(expr[i]);
        retorno1 = isOperador(expr[i]);
        retorno2 = isVariaveis(expr[i]);
        if(retorno == 1){ //é numero
            l->A[i].tipo = 558;
        }
        if(retorno1 == 2){  //è operador
            l->A[i].tipo = 557;
        }
        if(retorno2 == 3){
            l->A[i].tipo = 556;
        }
        l->nroElem++;
    }
}

void isNumber(char ch){
    char numeros[9] = "0123456789";
    int i,retorno = 0;
    for(i=0; i<10; i++){
        if(ch == numeros[i]){
           retorno = 1;
        }
    }
    return retorno;
}

void isOperador(char ch){
    char op[4] = "+=-*/";
    int i,retorno = 0;
    for(i=0; i<5; i++){
        if(ch == op[i]){
           retorno = 2;
        }
    }
    return retorno;
}

void isVariaveis(char ch){
    char variaveis[2] = "xyz";
    int i,retorno = 0;
    for(i=0; i<3; i++){
        if(ch == variaveis[i]){
           retorno = 3;
        }
    }
    return retorno;
}

void somar(LISTA *l, TOKENS *tk){



}

int main(){

    LISTA lista;
    TOKENS tk;
    char resposta;

    inicializaLista(&lista);
    insere(&lista, &tk);
    exibirLista(&lista, &tk);

    printf("Deseja efetuar a soma ? [s/n]");
    gets(resposta);

    if(resposta == 's'){
        somar();
    }else{
        return 0;
    }
    return 0;
}
