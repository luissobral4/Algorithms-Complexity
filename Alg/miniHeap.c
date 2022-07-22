#include <stdlib.h>

#include "minheap.h"


void initHeap (Heap *h, int size) {
    h -> size = size;
    h -> used = 0;
    h -> values = calloc(size,sizeof(Elem));
}



void bubbleUp (Elem h[], int i) {
     while (i != 0 && h[i] < h[(i-1)/2]) {
         swap(h,i, (i-1)/2);
         i = (i - 1)/2;
     }
}



int  insertHeap (Heap *h, Elem x) {
    if (h -> size == h -> used) {
        h -> values = realloc(h -> values,2*h->size*sizeof(Elem));
        h -> size *= 2;
    }
    h -> values[h -> used] = x;
    (h -> used)++;
    bubbleUp (h->values,(h->used)-1);
    return 1;
    //return insertHeap_sol (h, x);
}



void bubbleDown (Elem h[], int N) {
    int i = 0;
    while ((2*i+1 < N && h[i] > h[2*i+1]) || (2*i+2 < N && h[i] > h[2*i+2])) {
        if(N - 1 == 2*i-1 || h[2*i + 1] <= h[2*i + 2]) {
            swap(h,i,2*i+1);
            i = 2*i+1;
        }
        else {
            swap(h,i,2*i+2);
            i = 2*i+2;
        }
    }
}



int  extractMin (Heap *h, Elem *x) {
    if (h -> used > 0) {
        x[0] = h -> values[0];
        h -> values[0] = h -> values[h -> used - 1];
        (h -> used --);
        bubbleDown (h -> values,h -> used);
        return 1;
    }
    return 0;
}



int minHeapOK (Heap h) {
    int i = 0;
    for (i;2*i + 1 < h.used;i++)
        if (h.values[i] > h.values[2*i+1] || h.values[i] > h.values[2*i+2]) return 0;


}
