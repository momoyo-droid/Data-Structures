#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list LL_T;
typedef int bool;
typedef int ELEMENT;

LL_T* create_linked_list(void);
void destroy_linked_list(LL_T* list);
void append_linked_list(LL_T* list, ELEMENT item);
bool pop_linked_list(LL_T* list, ELEMENT item);
int size_linked_list(LL_T* list);
bool search_linked_list(LL_T* list, ELEMENT item);
void print_linked_list(LL_T* list);
void reverse_linked_list(LL_T* list);

#endif
