#include "graphs.h"

int color[MAX];

void df_visit(GraphL g, int s){
    struct edge *aresta;

    color[s] = GRAY;

    for(aresta = g[s];aresta;aresta = aresta -> next) {
        if (color[aresta->dest] == WHITE)
            df_visit(g,aresta->dest);
    }
    color[s] = BLACK;

}

void dfs (GraphL g, int n){
    int i = 0;

    for(i = 0;i < n;i++) color[i] = WHITE;

    for(i = 0;i < n;i++)
        if(color[i] == WHITE) df_visit(g,i);

}

void bf_visit(GraphL g, int s){
    int orla[MAX],f = 0,l = 0;
    struct edge *aresta;

    color[s] = GRAY;
    orla[l++] = s;

    while(f < l) {
    for(aresta = g[orla[f++]];aresta;aresta = aresta -> next)
        if (color[aresta->dest] == WHITE) {
            color[aresta->dest] = GRAY;
            orla[l++] = aresta->dest;
        }
    color[s] = BLACK;
    }
}

void bfs (GraphL g, int n){
    int i = 0;

    for(i = 0;i < n;i++) color[i] = WHITE;

    for(i = 0;i < n;i++)
        if(color[i] == WHITE) bf_visit(g,i);
}

void dists (GraphL g, int s, int dist[]) {
    int orla[MAX],f = 0,l = 0,u,i;
    struct edge *aresta;

    for(i = 0;i < MAX;i++) {
        color[i] = WHITE;
        dist[i] = -1;
    }
    color[s] = GRAY;
    orla[l++] = s;
    dist[s] = 0;

    while(f < l) {
        u = orla[f++];
        for(aresta = g[u];aresta;aresta = aresta -> next)
            if (color[aresta->dest] == WHITE) {
                color[aresta->dest] = GRAY;
                orla[l++] = aresta->dest;
                dist[aresta->dest] = dist[u] + 1;
            }
        color[u] = BLACK;
    }
}

void shortestPath (GraphL g, int s, int  d) {
    int orla[MAX],f = 0,l = 0,u,i,parent[MAX];
    struct edge *aresta;

    for(i = 0;i < MAX;i++) {
        color[i] = WHITE;
        parent[i] = -1;
    }
    color[s] = GRAY;
    orla[l++] = s;

    while(f < l) {
        u = orla[f++];
        for(aresta = g[u];aresta;aresta = aresta -> next)
            if (color[aresta->dest] == WHITE) {
                color[aresta->dest] = GRAY;
                orla[l++] = aresta->dest;
                parent[aresta->dest] = u;
            }
        color[u] = BLACK;
    }

    if (parent[d]==-1) printf("caminho não alcançavel\n");
    else {
        printf("caminho mais curto de %d a %d\n",s,d);
        while(u != -1){
            printf("%d ", u);
            u = parent[u];
        }
    }
}
