#include <assert.h>
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    void** items;
    int index_top;
    int size_elements;
};

STACK_T* create_stack(int size_elements){
    STACK_T* stack = malloc(sizeof(STACK_T));
    assert(stack != NULL);

    stack->items = malloc(sizeof(void*)*STACK_SIZE);
    assert(stack->items != NULL);

    stack->index_top = -1;
    stack->size_elements = size_elements;

    return stack;
}

void destroy_stack(STACK_T* stack){
    while(stack->index_top >= 0){
        free(stack->items[stack->index_top]);
        stack->index_top -= 1;
    }
    if(stack->items != NULL) free(stack->items);
    if(stack != NULL) free(stack);
    stack = NULL;
}

boolean stack_is_full(STACK_T* stack){
    assert(stack != NULL);
    if(stack->index_top == STACK_SIZE - 1) return 1;
    else return 0;
}

boolean stack_is_empty(STACK_T* stack){
    assert(stack != NULL);
    if(stack->index_top == -1) return 1;
    else return 0;
}

boolean push_stack(STACK_T* stack, void* item){
    assert(stack != NULL);
    if(stack_is_full(stack) == 1) return -1;

    stack->index_top += 1;
    stack->items[stack->index_top] = malloc(stack->size_elements);
    assert(stack->items[stack->index_top] != NULL);
    memcpy(stack->items[stack->index_top], item, stack->size_elements);
    return 1;
}

boolean pop_stack(STACK_T* stack, void* item){
    assert(stack != NULL);
    if(stack_is_empty(stack) == 1) return -1;
    memcpy(item, stack->items[stack->index_top], stack->size_elements);
    free(stack->items[stack->index_top]);
    stack->index_top -= 1;
    return 1;
}

boolean top_stack(STACK_T* stack, void* item){
    assert(stack != NULL);
    if(stack_is_empty(stack) == 1) return -1;
    memcpy(item, stack->items[stack->index_top], stack->size_elements);
    return 1;
}
