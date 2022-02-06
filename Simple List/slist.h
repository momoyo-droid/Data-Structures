#ifndef SLIST_H
#define SLIST_H

#define MAX 10

typedef int ELEMENT;
typedef int bool;
typedef struct list SL_T;

SL_T* create_list(void);
void destroy_list(SL_T* list);
int size_list(SL_T* list);
int full_list(SL_T* list);
int empty_list(SL_T* list);
bool append_list(SL_T* list, ELEMENT item);
bool pop_list(SL_T* list, ELEMENT item);
void print_list(SL_T* list);

#endif