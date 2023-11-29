#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define WHITE 0
#define GRAY 1
#define BLACK 2

int colors[MAX_VERTICES];
int parent[MAX_VERTICES];
int discovery_time[MAX_VERTICES];
int finish_time[MAX_VERTICES];
int time = 0;

void DFS_visit(int adj_matrix[MAX_VERTICES][MAX_VERTICES], int start_vertex, int num_vertices) {
    colors[start_vertex] = GRAY;
    discovery_time[start_vertex] = time++;
    printf("Visited: %d (GRAY)\n", start_vertex);

    for (int i = 0; i < num_vertices; i++) {
        if (adj_matrix[start_vertex][i] == 1 && colors[i] == WHITE) {
            parent[i] = start_vertex;
            DFS_visit(adj_matrix, i, num_vertices);
        }
    }

    colors[start_vertex] = BLACK;
    finish_time[start_vertex] = time++;
    printf("Visited: %d (BLACK)\n", start_vertex);
}

void DFS(int adj_matrix[MAX_VERTICES][MAX_VERTICES], int num_vertices){
    for (int i = 0; i < num_vertices; i++) {
        colors[i] = WHITE;
        parent[i] = -1;
        discovery_time[i] = -1;
        finish_time[i] = -1;
    }

    for (int i = 0; i < num_vertices; i++){
        if(colors[i] == WHITE)
        DFS_visit(adj_matrix, i, num_vertices);
    }
}

int main() {
    int num_vertices = 6;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {0, 1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };

    DFS(adj_matrix, num_vertices);

    return 0;
}