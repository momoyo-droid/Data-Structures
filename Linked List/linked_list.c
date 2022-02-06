#include "linked_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE_T;

struct node{
    ELEMENT item;    
    NODE_T* next;
};

struct list{
    NODE_T* head, *tail;
    int size_list;
};

LL_T* create_linked_list(void){
    LL_T* list = malloc(sizeof(LL_T));
    
    assert(list != NULL);
    
    list->head = NULL;
    list->tail = NULL;
    list->size_list = 0;

    return list;
}

void destroy_linked_list(LL_T* list){
    assert(list != NULL);

    NODE_T* node = list->head;
    while(node != NULL){
        list->head = node->next;
        free(node);
        node = list->head;
    }
    free(list);
}

void append_linked_list(LL_T* list, ELEMENT item){
    assert(list != NULL);

    // does not allow insertion of repeated elements
    if(search_linked_list(list, item) == 1){
        printf("element REPEATED\n");
        return;
    }

    NODE_T* new_node = malloc(sizeof(NODE_T));
    new_node->item = item;
    new_node->next = NULL;

    assert(new_node != NULL);

    if(list->head == NULL){
        list->head = new_node;
    }else{
        list->tail->next = new_node;
    }
    list->tail = new_node;
    list->size_list++;
}

bool pop_linked_list(LL_T* list, ELEMENT item){
    assert(list != NULL);

    if(list->head == NULL){
        printf("The list is EMPTY\n");
        return 0;
    }

    NODE_T* deleted_node = list->head;
    NODE_T* prev = NULL;

    while(deleted_node != NULL){
        if(deleted_node->item == item){
            // element is at the beginning of the list
            if(deleted_node == list->head){
                list->head = list->head->next;
                free(deleted_node);
            }else if(deleted_node == list->tail){ // element is at the end of the list
                list->tail = prev;
                list->tail->next = NULL;
                free(deleted_node);
            }else{ // element is at the middle of the list
                prev->next = deleted_node->next;
                free(deleted_node);
            }
            list->size_list--;
            return 1;
        }else{
            prev = deleted_node;
            deleted_node = deleted_node->next;
        }
    }
    return 0;
}

int size_linked_list(LL_T* list){
    assert(list != NULL);
    return list->size_list;
}

bool search_linked_list(LL_T* list, ELEMENT item){
    assert(list != NULL);

    NODE_T* node = list->head;
    while(node != NULL){
        if(node->item == item){
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void print_linked_list(LL_T* list){
    assert(list != NULL);

    NODE_T* node = list->head;
    while(node != NULL){
        printf("%d ", node->item);
        node = node->next;
    }
    printf("\n");
}

void reverse_linked_list(LL_T* list){
    if(list->head == NULL){
        printf("The list is EMPTY\n");
        return;
    }

    NODE_T* previous_node = NULL, *current_node = list->head, *next_node;

    while(current_node != NULL){
        next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    list->head = previous_node;
}