#include <stdlib.h>
#include "vectorDn.h"
#include <stdio.h>
#include <stdbool.h>
#define MIN_CAP 5
#define K 2
#define k 3/5

void vector_init(dbl_vectorDn *v) {
  v->buf = malloc(sizeof(double) * MIN_CAP);
  v->size = 0;
  v->cap = MIN_CAP;
  v->head = 0;
}

bool vector_is_empty(dbl_vectorDn *v){
  if (v->size == 0 ){
        return true;
    }
    return false;
}

int vector_size(dbl_vectorDn *v){
    return v->size;
}

void vector_resize(dbl_vectorDn *v, int new_cap) {
  double *tmp = malloc(sizeof(double) * new_cap);
  for (int i = 0; i < v->size; i++) {
    int ind = (v->head + i) % v->cap;
    tmp[i] = v->buf[ind];
  }
  free(v->buf);
  v->buf = tmp;
  v->cap = new_cap;
  v->head = 0;
}

void vector_push_back(dbl_vectorDn *v, double val) {
  if (v->size == v->cap) {
    vector_resize(v, v->cap * K);
  }
  int ind = (v->head + v->size) % v->cap;
  v->buf[ind] = val;
  v->size++;
}

void vector_pop_back(dbl_vectorDn *v) {
  if (v->size > 0) {
    v->size--;
    if (v->size <= v->cap / 3) {
      vector_resize(v, v->cap * k);
    }
  }
}

double vector_get(dbl_vectorDn *v, int ind) {
  if (ind >= 0 && ind < v->size) {
    int real_ind = (v->head + ind) % v->cap;
    return v->buf[real_ind];
  }
}

void vector_set(dbl_vectorDn *v, int ind, double val) {
  if (ind >= 0 && ind < v->size) {
    int real_ind = (v->head + ind) % v->cap;
    v->buf[real_ind] = val;
  }
}

void vector_destroy(dbl_vectorDn *v) {
  v->size = 0;
  v->cap = 0;
  v->head = 0;
  free(v->buf);
  v->buf = NULL;
}

void print_vector(dbl_vectorDn *v){
    printf("----\n");
    for(int i = 0; i < v->cap; i++){
        printf("%d | %lf\n", i, v->buf[i]);
    }
    printf("Size>%d | Head>%d | Last>%d | Cap>%d\n",v->size,v->head,(v->head+v->size-1)%v->cap,v->cap);
    printf("----\n");
}