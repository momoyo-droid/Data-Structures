#include "dll.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE NODE_T;

struct NODE{
    ELEMENT item;
    NODE_T* prev, *next;
};

struct DLL{
    NODE_T* head, *tail;
};

DLL_T* create_dll(){
    DLL_T* new_dll = malloc(sizeof(DLL_T));
    assert(new_dll != NULL);
    new_dll->head = new_dll->tail = NULL;
    return new_dll;
}

void destroy_dll(DLL_T* dll){
    if(dll != NULL){
        NODE_T* node = dll->head;
        while(node != NULL){
            dll->head = dll->head->next;
            free(node);
            node = dll->head;
        }
        free(dll);
    }
}

bool push_dll(DLL_T* dll, ELEMENT item){
    assert(dll != NULL); 
    NODE_T* new_node = malloc(sizeof(NODE_T));
    assert(new_node != NULL);
    new_node->item = item;
    new_node->prev = NULL;
    new_node->next = NULL;

    NODE_T* next_node = dll->head, *prev_node = NULL;
    while(next_node != NULL && item > next_node->item){
        prev_node = next_node;
        next_node = next_node->next;
    }

    // item already exist
    while(next_node != NULL && item ==  next_node->item){
        free(new_node);
        return 0;
    }

    // push head
    if(prev_node == NULL){
        new_node->next = dll->head;
        if(dll->head != NULL) dll->head->prev = new_node; // check if it already has items
        dll->head = new_node;
    }else{ // insert in the middle or at the end
        new_node->next = prev_node->next;
        prev_node->next = new_node;
        if(new_node->next != NULL) new_node->next->prev = new_node;
        else dll->tail = new_node;
        new_node->prev = prev_node;
    }
}

bool pop_dll(DLL_T* dll, ELEMENT item){
    assert(dll != NULL);
    
    NODE_T* curr_node = dll->head, *prev_node = NULL;

    while(curr_node != NULL && item > curr_node->item){
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    if(curr_node == NULL) return 0;

    if(prev_node == NULL){ // remove first element
        dll->head = dll->head->next;
        if(dll->head != NULL) dll->head->prev = NULL;
        else dll->tail = NULL;
        free(curr_node);
    }else{ // remove from the middle
        if(curr_node->next == NULL){
            dll->tail = curr_node->prev;
            prev_node->next = NULL;
            free(curr_node);
        }else{
            prev_node->next = curr_node->next;
            curr_node->next->prev = prev_node;
            free(curr_node);
        }
    }
    return 1;
}

void print_dll(DLL_T* dll){
    assert(dll != NULL);
    NODE_T* node = dll->head;
    while(node != NULL){
        printf("%d ", node->item);
        node = node->next;
    }
    printf("\n");
}

void print_reverse_dll(DLL_T* dll){
    assert(dll != NULL);
    NODE_T* node = dll->tail;
    while(node != NULL){
        printf("%d ", node->item);
        node = node->prev;
    }
    printf("\n");
}