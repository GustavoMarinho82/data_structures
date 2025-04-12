#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* new_stack() {
	// Creates a linked stack and returns a pointer to it [θ(1)]
	Stack* S = malloc(sizeof(Stack));
	S->size = 0;
	S->top = NULL;

	return S;
}

void destroy_stack(Stack* S) {
	// Destroys the stack and frees its memory [θ(N)]
	clear(S);
	free(S);
}

void push(Stack* S, int value) { 
	// Inserts a element into the stack [θ(1)]
	Node* p = malloc(sizeof(Node));
	p->element = value;
	p->next = S->top;
	S->top = p;
	S->size++;
}

int pop(Stack* S) {
	// Removes and returns the top element from the stack [θ(1)]
	if (S->size == 0) {
		fprintf(stderr, "Stack underflow!\n");
		exit(EXIT_FAILURE);
	}
	
	int value = S->top->element;
	
	Node* p = S->top->next;
	free(S->top);
	S->top = p;
	S->size--;
	
	return value;
}

int top(Stack* S) {
	// Returns the top element from the stack [θ(1)]
	if (S->size == 0) {
		fprintf(stderr, "Trying to acess the top of an empty stack!\n");
		exit(EXIT_FAILURE);
	}
	return S->top->element;
}

int length(Stack* S) {
	// Returns the current number of elements in the stack [θ(1)]
	return S->size;
}

bool is_empty(Stack* S) {
	// Returns true if the stack is empty, false otherwise [θ(1)]
	return (S->size == 0);
}

void clear(Stack* S) {
	// Clears the stack freeing its nodes [θ(N)]
	while (S->size > 0)
		pop(S);
}

void print_stack(Stack* S) {
	// Prints each element from top to the bottom of the stack [θ(N)]
	Node* p = S->top;
	
	while (p != NULL) {
		printf("|%d|->", p->element);
		p = p->next;
	}
	
	printf("X\n");
}
