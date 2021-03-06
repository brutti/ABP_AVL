/*
 * Jefferson Coppini, Nicholas Brutti
 * G1Trab - Estrutura de Dados II - UFFS 2015/2
 */
#include"arv.h"
#include<stdio.h>
#include<stdlib.h>

void destruirArv(arv **p) {
    if(!(*p)) return;
    destruirArv(&(*p)->esq);
    destruirArv(&(*p)->dir);
    free(*p);
}

void print(arv **p) {
    if(!(*p)) return;
    printf("%d\n",(*p)->n);
    print(&(*p)->esq);
    print(&(*p)->dir);
}

void insereArv(arv **p, int a) {
   if(!(*p)) {
       *p = (arv *) malloc(sizeof(arv));
       (*p)->n = a;
       (*p)->esq = (*p)->dir = NULL;
   }
   if(a < (*p)->n) insereArv(&(*p)->esq,a);
   if(a > (*p)->n) insereArv(&(*p)->dir,a);
}

arv* procElem(arv **p ,int a) {
    if ((*p) == NULL) return NULL;
    if ((*p)->n == a) return *p;
    if (a < (*p)->n) return procElem(&(*p)->esq, a);
    return procElem(&(*p)->dir, a);
}

int alt(arv **p) {
    int esquerda,direita;
    if((*p) == NULL) return -1;
    esquerda = alt(&(*p)->esq);
    direita = alt(&(*p)->dir);
    if(direita > esquerda) return direita + 1;
    return esquerda + 1;
}

int procFator(arv **p) {
    if((*p)->esq && (*p)->dir) return alt(&(*p)->esq)-alt(&(*p)->dir);
    if(!(*p)->esq && (*p)->dir) return -1 -(alt(&(*p)->dir));
    if((*p)->esq && !(*p)->dir) return  1 + alt(&(*p)->esq);
    return 0;
}

int fator(arv **p, int a, int *found) {
    arv * aux = NULL;
    aux = procElem(&(*p),a);
    if(!aux) return *found = 0;
    *found = 1;
    return procFator(&aux);
}

int avl(arv **p) {
    int esq, dir, diferenca;
    if(!(*p)) return 1;
    esq = alt(&(*p)->esq);
    dir = alt(&(*p)->dir);
    diferenca = abs(esq - dir);
    if((diferenca == 1 || diferenca == 0) && avl(&(*p)->esq) && 
                                                        avl(&(*p)->dir))
        return 1; //É avl
    return 0; //Não é avl
}

int balan(arv **p) {
    int esq, dir;
    if(!(*p)) return 1;
    esq = alt(&(*p)->esq);
    dir = alt(&(*p)->dir);
    if(!abs(esq - dir) && balan(&(*p)->esq) && balan(&(*p)->dir))
        return 1; //Está balanceada
    return 0; //Não está balanceada
}
