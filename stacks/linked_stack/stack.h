#ifndef STACK_H
#define STACK_H

#include<stdbool.h>

typedef struct Node {
	int element;
	struct Node* next;
} Node;

typedef struct Stack {
	struct Node* top;
	int size; // current number of elements
} Stack;

Stack* new_stack(); //θ(1)
void destroy_stack(Stack*); //θ(N)
void push(Stack*, int); //θ(1)
int pop(Stack*); //θ(1)
int top(Stack*); //θ(1)
int length(Stack*); //θ(1)
bool is_empty(Stack*); //θ(1)
void clear(Stack*); //θ(N)
void print_stack(Stack*); //θ(N)

#endif
