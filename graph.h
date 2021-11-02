#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "dequeue.h"

typedef struct undirected_graph
{
    int num_nodes;
    int **adj_mat;
} u_graph;

// Initializeaza un graf cu n noduri. (0.5 puncte)
u_graph *init_graph(int n);

// Insereaza o noua muchie in graf, de la nodul `from` la nodul `to` (0.5 puncte)
void insert_edge(u_graph *graph, int from, int to);

// Sterge o muchie din graf (0.5 puncte)
void remove_edge(u_graph *graph, int from, int to);

// Sterge si elibereaza memoria alocata grafului. (0.5 puncte)
void destroy_graph(u_graph *graph);

// Afiseaza matricea de adiacenta 
void print_adj_matrix(u_graph *g);

// Parcurge graful in adancime folosind apeluri recursive. (1.5 puncte)
void dfs_recursive(u_graph *graph, int source, int *visited);

// Parcurge graful in adancime folosind o stiva. (2 puncte)
void dfs_iterative(u_graph *graph, int source);

// Parcurge graful pe nivel folosind apeluri recursive. (1.5 puncte)
void bfs_recursive(u_graph *graph, dequeue_t *queue, int *visited);

// Parcurge graful pe nivel folosind o coada. (2 puncte)
void bfs_iterative(u_graph *graph, int source);

// Returneaza numarul de componenete conectate in graph. (1 punct)
int num_connected_components(u_graph *graph);


#endif