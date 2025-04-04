#ifndef STACK_H
#define STACK_H

#ifndef MAX_SIZE
#define MAX_SIZE 256
#endif

struct Stack {
    int E[MAX_SIZE];
    int N; // number of elements
};

void init_stack(Stack&); //θ(1)
void push(Stack&, int); //θ(1)
int pop(Stack&); //θ(1)
int top(const Stack&); //θ(1)
int size(const Stack&); //θ(1)
void clear(Stack&); //θ(1)
void print_stack(const Stack&); //θ(N)

#endif
