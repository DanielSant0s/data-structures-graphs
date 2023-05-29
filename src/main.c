#include "grafo.h"
#include <stdio.h>

int main() {
    struct Grafo* grafo = criarGrafo(6);

    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 2, 4);
    adicionarAresta(grafo, 3, 4);
    adicionarAresta(grafo, 3, 5);

    printf("Busca em altura (DFS): ");
    buscaAltura(grafo, 0);
    printf("\n");

    printf("Busca em profundidade (BFS): ");
    buscaProfundidade(grafo, 0);
    printf("\n");

    destruirGrafo(grafo);

    return 0;
}