#ifndef STACK_H
#define STACK_H

struct Node {
	int E;
	Node* next;
};

struct Stack {
    Node* top;
    int N; // number of elements
};

void init_stack(Stack&); //θ(1)
void push(Stack&, int); //θ(1)
int pop(Stack&); //θ(1)
int top(const Stack&); //θ(1)
int size(const Stack&); //θ(1)
void clear(Stack&); //θ(N)
void print_stack(const Stack&); //θ(N)

#endif
