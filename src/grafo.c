#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

struct NoAdjacente* criarNoAdjacente(int vertice) {
    struct NoAdjacente* novoNo = (struct NoAdjacente*)malloc(sizeof(struct NoAdjacente));
    novoNo->vertice = vertice;
    novoNo->proximo = NULL;
    return novoNo;
}

struct Grafo* criarGrafo(int numVertices) {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->numVertices = numVertices;
    grafo->listaAdjacencia = (struct NoAdjacente**)malloc(numVertices * sizeof(struct NoAdjacente*));
    int i;
    for (i = 0; i < numVertices; i++) {
        grafo->listaAdjacencia[i] = NULL;
    }
    return grafo;
}

void destruirGrafo(struct Grafo* grafo) {
    if (grafo) {
        int i;
        for (i = 0; i < grafo->numVertices; i++) {
            struct NoAdjacente* atual = grafo->listaAdjacencia[i];
            while (atual) {
                struct NoAdjacente* proximo = atual->proximo;
                free(atual);
                atual = proximo;
            }
        }
        free(grafo->listaAdjacencia);
        free(grafo);
    }
}

void adicionarAresta(struct Grafo* grafo, int origem, int destino) {
    if (grafo && origem >= 0 && origem < grafo->numVertices && destino >= 0 && destino < grafo->numVertices) {
        struct NoAdjacente* novoNo = criarNoAdjacente(destino);
        novoNo->proximo = grafo->listaAdjacencia[origem];
        grafo->listaAdjacencia[origem] = novoNo;
    }
}

void buscaAlturaUtil(struct Grafo* grafo, int vertice, int* visitado) {
    visitado[vertice] = 1;
    printf("%d ", vertice);

    struct NoAdjacente* atual = grafo->listaAdjacencia[vertice];
    while (atual) {
        if (!visitado[atual->vertice]) {
            buscaAlturaUtil(grafo, atual->vertice, visitado);
        }
        atual = atual->proximo;
    }
}

void buscaAltura(struct Grafo* grafo, int verticeInicial) {
    if (grafo && verticeInicial >= 0 && verticeInicial < grafo->numVertices) {
        int* visitado = (int*)calloc(grafo->numVertices, sizeof(int));
        buscaAlturaUtil(grafo, verticeInicial, visitado);
        free(visitado);
    }
}

void buscaProfundidade(struct Grafo* grafo, int verticeInicial) {
    if (grafo && verticeInicial >= 0 && verticeInicial < grafo->numVertices) {
        int* visitado = (int*)calloc(grafo->numVertices, sizeof(int));
        int* fila = (int*)malloc(grafo->numVertices * sizeof(int));
        int inicio = 0;
        int fim = 0;

        visitado[verticeInicial] = 1;
        fila[fim++] = verticeInicial;

        while (inicio < fim) {
            int vertice = fila[inicio++];
            printf("%d ", vertice);

            struct NoAdjacente* atual = grafo->listaAdjacencia[vertice];
            while (atual) {
                if (!visitado[atual->vertice]) {
                    visitado[atual->vertice] = 1;
                    fila[fim++] = atual->vertice;
                }
                atual = atual->proximo;
            }
        }

        free(visitado);
        free(fila);
    }
}