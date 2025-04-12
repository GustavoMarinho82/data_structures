#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

int main() {
	List* list = new_list(20);
	
	srand(time(NULL));
	
	for (int i = 1; i < 21; i++)
		insert(list, rand() % 11);
	
	print_list(list);
	
	printf("Is full: %d\n",  is_full(list));
	printf("7 removed: %d\n",  remove_element(list, 7));
	printf("6 removed: %d\n",  remove_element(list, 6));
	printf("Is full: %d\n",  is_full(list));
	print_list(list);
	
	insert(list, 1);
	print_list(list);
	printf("How many 1's: %d\n",  count(list, 1));
	printf("How many 1's removed: %d\n",  remove_all(list, 1));
	print_list(list);
	
	printf("Size: %d\n",  length(list));
	
	printf("Is empty: %d\n",  is_empty(list));
	clear(list);
	printf("Is empty: %d\n",  is_empty(list));
	print_list(list);
	printf("Size: %d\n",  length(list));
	
	destroy_list(list);
	
	return 0;
}
