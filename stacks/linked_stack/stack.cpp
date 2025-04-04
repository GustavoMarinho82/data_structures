#include <stdio.h>
#include <stdlib.h>
#include "stack.hpp"

void init_stack(Stack &s) { //θ(1)
	s.N = 0;
}

void push(Stack &s, int value) { //θ(1)
	Node* p = (Node*) malloc(sizeof(Node));
	p->E = value;
	p->next = s.top;
	s.top = p;
	s.N++;
}

int pop(Stack &s) { //θ(1)
	//if (s.N == 0) throw ---; WIP
	int value = s.top->E;
	
	Node* p = s.top->next;
	free(s.top);
	s.top = p;
	s.N--;
	
	return value;
}

int top(const Stack &s) { //θ(1)
	//if (s.N == 0) throw ---; WIP
	return s.top->E;
}

int size(const Stack &s) { //θ(1)
	return s.N;
}

void clear(Stack &s) { //θ(N)
	while (s.N > 0)
		pop(s);
}

void print_stack(const Stack &s) { //θ(N)
	Node* p = s.top;
	
	while (p != NULL) {
		printf("|%d|->", p->E);
		p = p->next;
	}
	
	printf("\n");
}
