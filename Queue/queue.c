#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue{
    int start, end, total_elem;
    ELEMENT itens[SIZE_Q];
};

queue_t *create_queue(){
    queue_t *q = malloc(sizeof(queue_t));
    assert(q != NULL);
    q->total_elem = 0;
    q->start = 0;
    q->end = 0
    return q;
}

bool queue_is_empty(queue_t *q){
    assert(q != NULL);
    if(q->end == 0){
        return 1;
    }
    return 0;
}

bool queue_is_full(queue_t *q){
    assert(q != NULL);
    if(q->total_elem == SIZE_Q){
        return 1;
    }
    return 0;
}

bool push_queue(queue_t *q, ELEMENT key){
    if(queue_is_full(q) == 1) return 0;
    q->itens[q->end] = key;
    q->end = (q->end + 1) % SIZE_Q;
    q->total_elem++;
    return 1;
}

bool pop_queue(queue_t *q, ELEMENT *key){
    if(queue_is_empty(q) == 1) return 0;
    *key = q->itens[q->start];
    q->start = (q->start + 1) % SIZE_Q;
    q->total_elem--;
    return 0;
}

void destroy_queue(queue_t *q){
    if(q != NULL) free(q);
}