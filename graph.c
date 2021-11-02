#include "graph.h"
#include "dequeue.h"

#include <stdio.h>
#include <stdlib.h>

u_graph *init_graph(int n) {
    int i;
    u_graph *graph=(u_graph *) calloc(1, sizeof(u_graph));
    graph->num_nodes=n;
    graph->adj_mat=calloc(n, sizeof(int*));
    for(i=0; i<n; i++) 
        graph->adj_mat[i]=calloc(n,sizeof(int));
    return graph;
}

void insert_edge(u_graph *graph, int from, int to) {
    graph->adj_mat[from][to]=1;
    graph->adj_mat[to][from]=1;
}

void remove_edge(u_graph *graph, int from, int to) {
    graph->adj_mat[from][to]=0;
    graph->adj_mat[to][from]=0;
}

void destroy_graph(u_graph *graph) {
    int i;
    for(i=0; i<graph->num_nodes; i++)
        free(graph->adj_mat[i]);
    free(graph->adj_mat);
    free(graph);
}

void dfs_recursive(u_graph *graph, int source, int *visited) {
    visited[source]=1;
    printf("%d ", source);
    int i;
    for (i=0; i<graph->num_nodes; i++) {
        if(graph->adj_mat[source][i] && visited[i]==0) 
            dfs_recursive(graph, i, visited);
    }
}

void dfs_iterative(u_graph *graph, int source) {
    double x;
    int i;
    int *visited=calloc(graph->num_nodes, sizeof(int));
    dequeue_t *stack = alloc_deq();
    push_front(stack, source);
    visited[source]=1;
    while(size(stack)!=0) {
        front(stack, &x);
        pop_front(stack);
        printf("%.0lf ", x);
        for (i=graph->num_nodes-1; i>=0; i--) {
            if(graph->adj_mat[(int)x][i] && visited[i]==0) {
                visited[i]=1;
                push_front(stack, i);
            }
        }
    }
    free(visited);
    free(stack);
}

// Parcurge graful pe nivel folosind apeluri recursive.
void bfs_recursive(u_graph *graph, dequeue_t *queue, int *visited) {
    if(size(queue)==0) return;
    double source;
    int i;
    front(queue, &source);
    visited[(int)source]=1;
    pop_front(queue);
    printf("%.0lf ", source);
    for(i=0; i<graph->num_nodes; i++) {
        if(graph->adj_mat[(int)source][i] && visited[i]==0) {
            visited[i]=1;
            push_back(queue, i);
        }
    }    
    bfs_recursive(graph, queue, visited);
}

void bfs_iterative(u_graph *graph, int source) {
    double x;
    int i;
    dequeue_t *queue=alloc_deq();
    int *visited=calloc(graph->num_nodes, sizeof(int));
    visited[source]=1; 
    push_back(queue, source);
    while (size(queue)!=0) {
        front(queue, &x);
        printf("%.0lf ", x);
        pop_front(queue);
        for(i=0; i<graph->num_nodes; i++) {
            if(graph->adj_mat[(int)x][i] && visited[i]==0) {
                visited[i]=1;
                push_back(queue, i);
            }
        }
    }
    free(visited);
    free(queue);
}

int num_connected_components(u_graph *graph) {
    int i, num_comp=0;
    int *visited=calloc(graph->num_nodes, sizeof(int));
    for(i=0; i<graph->num_nodes; i++) {
        if(visited[i]==0) {
            dfs_recursive(graph, i, visited);
            num_comp++;
        }
    }
    free(visited);
    return num_comp;
}

void print_adj_matrix(u_graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        for (int j = 0; j < g->num_nodes; j++) {
            printf("%d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}
