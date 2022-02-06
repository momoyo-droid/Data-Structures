#ifndef DLL_H
#define DLL_H

typedef int ELEMENT;
typedef int bool;
typedef struct DLL DLL_T;

DLL_T* create_dll(void);
void destroy_dll(DLL_T* dll);
bool push_dll(DLL_T* dll, ELEMENT item);
bool pop_dll(DLL_T* dll, ELEMENT item);
void print_dll(DLL_T* dll);
void print_reverse_dll(DLL_T* dll);

#endif