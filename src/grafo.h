#ifndef GRAFO_H
#define GRAFO_H

struct NoAdjacente {
    int vertice;
    struct NoAdjacente* proximo;
};

struct Grafo {
    int numVertices;
    struct NoAdjacente** listaAdjacencia;
};

struct Grafo* criarGrafo(int numVertices);
void destruirGrafo(struct Grafo* grafo);
void adicionarAresta(struct Grafo* grafo, int origem, int destino);
void buscaAltura(struct Grafo* grafo, int verticeInicial);
void buscaProfundidade(struct Grafo* grafo, int verticeInicial);

#endif /* GRAFO_H */