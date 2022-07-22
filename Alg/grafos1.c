#define NE 0

#define MAX 100

typedef int WEIGHT;

struct edge {
  int dest;
  WEIGHT weight;
  struct edge *next;
};

typedef struct edge *GraphL[MAX];

typedef WEIGHT GraphM[MAX][MAX];

void graphLtoM(GraphM gm, GraphL gl, int n) {
    int i,i2;
    struct edge *x;
    for (i = 0; i < n;i++)
        for(x=gl[i],i2 = 0; i2 < n;i2++) {
            if(x && x-> dest = i2) {
                gl[i][i2] = x -> weight;
                x = x -> prox;
            }
            else gl[i][i2] = NE;
        }

    //graphLtoM_sol(gm, gl, n);
}



void graphMtoL(GraphL gl, GraphM gm, int n) {
    //graphMtoL_sol(gl, gm, n);
    int l,c;
    struct edge *h,*new;
    for(l = 0;l < n;l++) {
        h = NULL;
        for(c = 0;c < n;c++)
            if(gm[l][c]) {
                new = malloc(sizeof(struct edge));
                new -> dest = c;
                new -> weight = gm[l][c];
                new -> next = head;
                h = new;
            }
        gl[l] = h;
    }
}



int inDegree (GraphL g, int j, int n) {
    int c = 0,i;
    struct edge *x;
    for(i = 0; i < n;i++)
        for(x = g[i];x && x -> dest < j;x = x-> prox);
        if(x && x->dest == j) c++;

    return c;
    //return inDegree_sol(g, j, n);
}

int inDegreeM (GraphM g, int j, int n) {
    int c = 0,i;
    for(i = 0; i < n;i++)
        if(g[i][j]) c++;

    return c;
    //return inDegree_sol(g, j, n);
}


int outDegree (GraphL g, int j) {
    int c = 0;
    struct edge *x;
    for(x = g[j];x != NULL;x = x -> prox) c++;

    return c;
    //return outDegree_sol(g, j);
}

int outDegreeM (GraphM g, int j, int n) {
    int c = 0,i;
    for(i = 0;i < n;i++)
        if (g[j][i]) c++;

    return c;
    //return outDegree_sol(g, j);
}

int capacidadeL (GraphL g, int v, int n) {
    int cap = 0,i;
    struct edge *x;
    for (i = 0;i < n;i++) {
        for(x = g[i];x && x -> dest < v;x = x -> prox);
        if(x && x ->dest == v) cap += x -> weight;
    }
    for(x = g[v];x;x = x -> prox) cap -= x -> weight;

    return cap;
    //return  capacidadeL_sol (g, v, n);
}

int maxCap (GraphL g, int n) {
    int cap[n],i,max;
    struct edge *x;
    for(i = 0; i < n; i++)
        for(x = g[i];x;x = x -> prox){
            cap[i] -= x -> weight;
            cap[x -> dest] += x -> weight;
        }
    max = 0;
    for(i = 1;i < n;i++)
        if(cap[i] > cap[max]) max = i;

    return max;
    //return maxCap_sol (g, n);
}

int colorOK (GraphL g, int color[]) {
  int i;
  struc edge *aresta;

  for(i = 0;i < v; i++)
    for(x = g[i];x;x = x -> prox)
      if(c[i] == cor[x -> dest]) return 0;

  return 1;
}

int inverse(GraphL a,GraphL b;int v) {
  int i;
  struct edge *aresta,*new;

  for(i=0;i < v;i++) b[i] = NULL;
  for(i--;i >= 0;i++){
    for(x = a[i];x; x = x -> prox) {
      new = malloc (sizeof(struct edge));
      new -> dest = i;
      new -> weight = x -> weight;
      new -> prox = b[x->dest];
      b[x -> dest] = new;
    }
  }
  return 1;    
}
