#ifndef STACK_H
#define STACK_H
#define STACK_SIZE 100

typedef struct stack STACK_T;
typedef int boolean;

STACK_T* create_stack(int size_stack);
void destroy_stack(STACK_T* stack);
boolean stack_is_full(STACK_T* stack);
boolean stack_is_empty(STACK_T* stack);
boolean push_stack(STACK_T* stack, void* item);
boolean pop_stack(STACK_T* stack, void* item);
boolean top_stack(STACK_T* stack, void* item);

#endif