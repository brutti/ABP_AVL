#include<stdio.h>
#include"arv.h"

int main(void){
    arv* arvore_a;
    int n, f;
    criar_arvore(arvore_a);
    insereArv(&arvore_a, 20);
    insereArv(&arvore_a, 15);
    insereArv(&arvore_a, 24);
    insereArv(&arvore_a, 11);
    insereArv(&arvore_a, 18);
    insereArv(&arvore_a, 37);
    printf("%s\n", avl(&arvore_a) ? "E avl" : "Nao e avl");
    printf("%s\n", balan(&arvore_a) ? "Esta completamente balanceada" : 
                                      "Nao esta completamente balanceada");
    n = fator(&arvore_a, 24, &f);
    if(f) printf("Fator = %d\n", n);
    else printf("Nao encontrado.\n");
    printf("Arvore:\n");
    print(&arvore_a);
    destruirArv(&arvore_a);
    return 0;
}
