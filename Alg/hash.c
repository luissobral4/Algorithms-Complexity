
//
//  hashing.c
//  Hashing


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "hashing.h"


int hash(char key[], int size) {

    int chave, i;
    for ( i = 0; key[i] != '\0'; i ++) chave += key[i];
    return (chave % size);
    //return hash_sol(key, size);
}


void initHT(HT *h, int size) {

    h -> size = size;
    h -> used = 0;
    int i;
    h -> tbl= calloc(size,sizeof(struct pair));
    for (i = 0; i < size; i++) strcpy(h->tbl[i].key, EMPTY);
    //initHT_sol(h, size);
}


int freeHT(HT *h, int k) {

    return freeHT_sol(h, k);
}



int writeHT (HT *h, char key[], int value) {

    /*int load,pos;
    //if ((h -> used + 1) / h -> size > 0,8) duplica(2*h->size,h);
    pos = hash(key,h->size);
    while(strcmp(h->tbl[pos].key,EMPTY) || strcmp(h->tbl[pos].key, DELETED))
        {pos = (pos + 1) % h->size;
        printf("* ");}

    h->used++;
    int i;
    for (i = 0; key[i];i++) (h->tbl)[pos].key[i] = key[i];
    (h->tbl)[pos].value = value;

    return pos;*/
    return writeHT_sol (h, key, value);
}



int readHT (HT *h, char key[], int* value) {

    int pos = hash(key,h->size);
    int i = pos;

    while(strcmp(key,h->tbl[pos].key)) {
        if (!strcmp(h->tbl[pos].key,EMPTY)) return -1;
        pos = (pos + 1) % h -> size;
        if (pos == i) return -1;
    }
    *value = h->tbl[pos].value;
    return pos;
    //return readHT_sol (h, key, value);
}



int deleteHT (HT *h, char key[]) {

   int pos = hash(key,h->size);
    int i = pos;

    while(strcmp(key,h->tbl[pos].key)) {
        if (!strcmp(h->tbl[pos].key,EMPTY)) return -1;
        pos = (pos + 1) % h -> size;
        if (pos == i) return -1;
    }
    strcpy(h->tbl[pos].key,DELETED);
    h->used--;
    return pos;
    //return deleteHT_sol (h, key);
}
