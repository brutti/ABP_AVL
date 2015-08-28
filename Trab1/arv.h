/*
 * Jefferson Coppini, Nicholas Brutti
 * G1Trab - Estrutura de Dados II - UFFS 2015/2
 */
#ifndef hARV
    #define hARV
#include <stdlib.h>

typedef struct arv {
    struct arv *dir, *esq;
    int n;
} arv;

#define criar_arvore(P) P = NULL

void print(arv **p); //Exibe a árvore
void insereArv(arv **p, int a); //Insere um novo nó na árvore
arv* procElem(arv **p, int a); //Retorna o ponteiro para o valor encontrado
int alt(arv **p); //Altura de um nodo
int procFator(arv **p); //Calcula fator
int fator(arv **p, int a);
int avl(arv **p); //Verifica se a árvore é avl ou não
int balan(arv **p); //Verifica se a árvore está balanceada

#endif