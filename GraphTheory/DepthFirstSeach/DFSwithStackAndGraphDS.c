#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack{
    int top, size;
    unsigned int capacity;
};

/**
 * isEmpty
 * isFull
 * getTop
 * push
 * pop
 */

struct Graph{
    int V;
    int **edges;
}

struct Graph* createGraph(unsigned int capacity, int V) {
    int i, j;
    struct Graph *G = (struct Graph*) malloc(sizeOf(struct Graph));

    // Allocating array of int pointers, each pointing to an array of int
    G->edges = (int**) malloc(V*sizeOf(int*));

    // Intialization, if edge exists between vertex i and i, G->edges[i][j]=1, else '0'
    for(i=0; i<V; i++) {

        for(j=0; j<V; j++)
            G->edges[i][j] = 0;
    }
}
