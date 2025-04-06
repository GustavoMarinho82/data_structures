#include <stdio.h>
#include "stack.h"

int main() {
	Stack* stack = new_stack(10);
	for (int i = 1; i < 11; i++)
		push(stack, i);
	
	print_stack(stack);
	
	printf("Is full: %d\n",  is_full(stack));
	printf("Pop: %d\n",  pop(stack));
	printf("Is full: %d\n",  is_full(stack));
	print_stack(stack);
	
	push(stack, 50);
	print_stack(stack);
	
	printf("Top: %d\n",  top(stack));
	printf("Size: %d\n",  length(stack));
	
	printf("Is empty: %d\n",  is_empty(stack));
	clear(stack);
	printf("Is empty: %d\n",  is_empty(stack));
	print_stack(stack);
	printf("Size: %d\n",  length(stack));
	
	destroy_stack(stack);
	
	return 0;
}
