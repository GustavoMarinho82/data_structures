#include <stdio.h>
#include "list.h"

int main() {
	List* list = new_list();
	for (int i = 1; i < 11; i++)
		insert(list, i);
	
	print_list(list);

	printf("7 removed: %d\n",  remove_element(list, 7));
	printf("6 removed: %d\n",  remove_element(list, 6));
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
