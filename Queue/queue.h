#ifndef QUEUE_H
#define QUEUE_H

#define SIZE_Q 100

typedef int ELEMENT;
typedef int bool;
typedef struct queue queue_t;

queue_t *create_queue();
bool queue_is_empty(queue_t *q);
bool queue_is_full(queue_t *q);
bool push_queue(queue_t *q, ELEMENT key);
bool pop_queue(queue_t *q, ELEMENT *key);
void destroy_queue(queue_t *q);

#endif