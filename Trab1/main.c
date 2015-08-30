#include<stdio.h>
#include"arv.h"

int main(void){
    arv* arvore_a = criar_arvore(arvore_a);
    int V[] = {42, 15, 88, 6, 27, 63, 94}, i;
    for(i = 0; i < 7; i++) insereArv(&arvore_a, V[i]);
    printf("%s\n", avl(&arvore_a) ? "Eh avl" : "Nao eh avl");
    printf("%s\n", balan(&arvore_a) ? "Esta balanceada" : "Nao esta balanceada");
    for(i = 0; i < 7; i++)
        printf("Fator %d = %d\n", V[i], fator(&arvore_a, V[i]));
    printf("\n\n ARVORE \n\n");
    print(&arvore_a);
    destruirArv(&arvore_a);
    return 0;
}
