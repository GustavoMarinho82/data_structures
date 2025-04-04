#include <stdio.h>
#include "stack.hpp"

int main() {
	Stack stack;
	init_stack(stack);
	
	for (int i = 1; i < 7; i++)
		push(stack, i);
	
	print_stack(stack);
	printf("Pop: %d\n",  pop(stack));
	print_stack(stack);
	push(stack, 50);
	print_stack(stack);
	printf("Top: %d\n",  top(stack));
	printf("Size: %d\n",  size(stack));
	clear(stack);
	print_stack(stack);
	printf("Size: %d\n",  size(stack));
	
	return 0;
}
