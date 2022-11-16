// PSEUDO GPS
// EXPLANATION: Print all possible paths between
// points A and E
// Paths must be unique (e.g. path A-B is the same as path B-A)
// All possible paths are:
// A-E, A-B-E, A-C-E, A-D-E, A-B-C-E, A-B-D-E, A-C-D-E, A-B-C-D-E

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct node {
    char name;
    struct node *next;
} node;

typedef struct graph {
    int n;
    node *adj[MAX];
} graph;

graph *createGraph() {
    graph *g = (graph *) malloc(sizeof(graph));
    g->n = 0;
    for (int i = 0; i < MAX; i++) {
        g->adj[i] = NULL;
    }
    return g;
}

node *createNode(char name) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->name = name;
    newNode->next = NULL;
    return newNode;
}

void addEdge(graph *g, char v1, char v2) {
    int i;
    for (i = 0; i < g->n; i++) {
        if (g->adj[i]->name == v1) {
            break;
        }
    }
    if (i == g->n) {
        g->adj[i] = createNode(v1);
        g->n++;
    }
    node *newNode = createNode(v2);
    newNode->next = g->adj[i]->next;
    g->adj[i]->next = newNode;
}

void printPath(char *path, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", path[i]);
        if (i < n - 1) {
            printf(" -> ");
        }
    }
    printf(" \n");
}

void printAllPaths(graph *g, char *path, int n, char v1, char v2) {
    if (v1 == v2) {
        printPath(path, n);
        return;
    }
    for (int i = 0; i < g->n; i++) {
        if (g->adj[i]->name == v1) {
            node *aux = g->adj[i]->next;
            while (aux != NULL) {
                path[n] = aux->name;
                printAllPaths(g, path, n + 1, aux->name, v2);
                aux = aux->next;
            }
        }
    }
}

int main() {
    graph *g = createGraph();
    addEdge(g, 'A', 'B');
    addEdge(g, 'A', 'C');
    addEdge(g, 'A', 'D');
    addEdge(g, 'A', 'E');
    addEdge(g, 'B', 'C');
    addEdge(g, 'B', 'D');
    addEdge(g, 'B', 'E');
    addEdge(g, 'C', 'D');
    addEdge(g, 'C', 'E');
    addEdge(g, 'D', 'E');
    char path[MAX];
    path[0] = 'A';
    printAllPaths(g, path, 1, 'A', 'E');
    return 0;
}