/*
 * Jefferson Coppini, Nicholas Brutti
 * G1Trab - Estrutura de Dados II - UFFS 2015/2
 */
#ifndef hARV
#define hARV

typedef struct arv {
    struct arv *dir, *esq;
    int n;
} arv;

#define criar_arvore(P) P = NULL

/* Libera o espaço alocado pela árvore. */
void destruirArv(arv **p);

/* Exibe todos os elementos contidos na árvore, na forma pré ordem. */
void print(arv **p);

/* Recebe a árvore, e um valor. Aloca memória e atribui o valor para
   o nó. 
 * Por padrão inicializa o ponteiro da esquerda e da direita com NULL.*/
void insereArv(arv **p, int a);

/* Recebe a árvore, um valor e o endereço de um int.
 * Se o ponteiro retornar 0, significa que o elemento
   não está na árvore.
 * Caso contrário, ele pertence a árvore e exibe o 
   fator referente ao nó. */
int fator(arv **p, int a, int *found);

/* Percorre a árvore e verifica se a árvore é avl. */
int avl(arv **p);

/* Verifica se a árvore está completamente balanceada. */
int balan(arv **p);

#endif
