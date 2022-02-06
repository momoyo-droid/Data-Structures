#include "slist.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct list{
    ELEMENT items[MAX];
    int size;
};

SL_T* create_list(void){
    SL_T* new_list = malloc(sizeof(SL_T));
    assert(new_list != NULL);
    new_list->size = 0;

    return new_list;
}

void destroy_list(SL_T* list){
    assert(list != NULL);
    free(list);
}

int size_list(SL_T* list){
    if (list == NULL){
        printf("The list is NULL"); 
        return -1;
    }
    return list->size;
}

int full_list(SL_T* list){
    if (list == NULL){
        printf("The list is NULL");
        return -1;
    }else{
        return (list->size == MAX);
    }
}

int empty_list(SL_T* list){
    if (list == NULL){
        printf("The list is NULL");
        return -1;
    }else{
        return (list->size == 0);
    }
}

bool append_list(SL_T* list, ELEMENT item){
    assert(list != NULL);

    if(full_list(list)){
        printf("The list is FULL\n");
        return 0;
    }

    list->items[list->size] = item;
    list->size++;
    return 1;
}

bool pop_list(SL_T* list, ELEMENT item){
    assert(list != NULL);

    if(empty_list(list)){
        printf("The list is EMPTY\n");
        return 0;
    }

    int i = 0; int k = 0;

    while(i < list->size && list->items[i] != item){
        i++;
    }

    if(i == list->size){
        return 0; // element not found
    } 

    for(k = i; k < list->size; k++){
        list->items[k] = list->items[k+1];
    }
    list->size--;
    return 1;
}

void print_list(SL_T* list){
    assert(list != NULL);

    for(int i = 0; i < list->size; i++){
        printf("%d ", list->items[i]);
    }
}
