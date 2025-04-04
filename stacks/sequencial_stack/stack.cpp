#include <stdio.h>
#include "stack.hpp"

void init_stack(Stack& s) { //θ(1)
	s.N = 0;
}

void push(Stack &s, int value) { //θ(1)
	//if (s.N + 1 < MAX_SIZE) throw ---; WIP
	s.E[s.N++] = value;
}

int pop(Stack &s) { //θ(1)
	//if (s.N == 0) throw ---; WIP
	return s.E[--s.N];
}

int top(const Stack &s) { //θ(1)
	//if (s.N == 0) throw ---; WIP
	return s.E[s.N - 1];
}

int size(const Stack &s) { //θ(1)
	return s.N;
}

void clear(Stack &s) { //θ(1)
	s.N = 0;
}

void print_stack(const Stack &s) { //θ(N)
	for (int i = s.N - 1; i >= 0; i--)
		printf("|%d| ", s.E[i]);
		
	printf("\n");
}
