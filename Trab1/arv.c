#include"arv.h"
#include<stdio.h>
#include<stdlib.h>

void print(arv **p) {
    if(!(*p)) return;
    printf("%d\n",(*p)->n);
    print(&(*p)->esq);
    print(&(*p)->dir);
}

void insereArv(arv **p, int a) {
   if(*p == NULL) {
       *p = (arv *) malloc(sizeof(arv));
       (*p)->n = a;
       (*p)->esq = (*p)->dir = NULL;
   }
   else {
       if(a < (*p)->n) insereArv(&(*p)->esq,a);
       if(a > (*p)->n) insereArv(&(*p)->dir,a);
   }
}

arv* procElem(arv **p ,int a) {
    if ((*p) == NULL) return NULL;
    if ((*p)->n == a) return *p;
    if (a < (*p)->n) return procElem(&(*p)->esq, a);
    return procElem(&(*p)->dir, a);
}

int alt (arv **p) {
    int esquerda,direita;
    if ((*p) == NULL) return -1;
    else {
        esquerda = alt(&(*p)->esq);
        direita = alt(&(*p)->dir);
        if(direita > esquerda) return direita+1;
        else return esquerda+1;
    }
}

int procFator(arv **p) {
    if((*p)->esq && (*p)->dir) return alt(&(*p)->esq)-alt(&(*p)->dir);
    if(!(*p)->esq && (*p)->dir) return -1 -(alt(&(*p)->dir));
    if((*p)->esq && !(*p)->dir) return  1 + alt(&(*p)->esq);
    else return 0;
}

int fator(arv **p, int a) {
    int i;
    arv * aux = NULL;
    aux = procElem(&(*p),a);
    if(!aux) return -2;
    i = procFator(&aux);
    return i;
}

int avl(arv **p) {
    int num;
    if((*p) != NULL){
            num = procFator(&(*p));
            if(num < -1 || num > 1) return -1;
            return avl(&(*p)->esq); 
            return avl(&(*p)->dir);
        }
    return 1;
}

int balan(arv **p) {
    int num;
    if((*p) != NULL){
            num = procFator(&(*p));
            if(num>0 || num <0) return -1;
            return balan(&(*p)->esq); 
            return balan(&(*p)->dir);
        }
    return 1;
}
