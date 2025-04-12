#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

List* new_list(int capacity) {
	// Creates a list with the specified capacity and returns a pointer to it [θ(1)]
	if (capacity <= 0)
		return NULL;

	List* L = malloc(sizeof(List));
	L->size = 0;
	L->capacity = capacity;
	L->elements = malloc(sizeof(int) * capacity);
			
	return L;
}

void destroy_list(List* L) {
	// Destroys the list and frees its memory [θ(1)]
	free(L->elements);
	free(L);
}

void insert(List* L, int value) {
	// Inserts an element into the list, maintaining the ascending order [θ(N)]
	if (L->size == L->capacity) {
		fprintf(stderr, "List overflow!\n");
		exit(EXIT_FAILURE);
	}
	
	int i = 0;
	
	while ((i < L->size) && (L->elements[i] < value))
		i++;
	
	for (int j = L->size; j > i; j--) {
		L->elements[j] = L->elements[j - 1];
	}
	
	L->elements[i] = value;
	L->size++;
}

bool search(List* L, int value) {
	// Returns true if the value exists in the list. Otherwise returns false [O(log N)]
	int low_lim = 0, up_lim = L->size - 1, middle;

	while (low_lim <= up_lim) {
		middle = (up_lim + low_lim)/2;

		if (L->elements[middle] == value)
			return true;

		else if (L->elements[middle] < value)
			low_lim = middle + 1;

		else
			up_lim = middle - 1;
	}

	return false;
}

int search_first(List* L, int value) {
	// Returns the index of the first occurrence of the value. If the value is not found, returns -1 [O(log N)]
	int low_lim = 0, up_lim = L->size - 1, middle, found_position = -1;

	while (low_lim <= up_lim) {
		middle = (up_lim + low_lim)/2;

		if (L->elements[middle] == value) {
			found_position = middle;
			up_lim = middle - 1;

		} else if (L->elements[middle] < value)
			low_lim = middle + 1;

		else
			up_lim = middle - 1;
	}

	return found_position;	
}

int search_last(List* L, int value) {
	// Returns the index of the last occurrence of the value. If the value is not found, returns -1 [O(log N)]
	int low_lim = 0, up_lim = L->size - 1, middle, found_position = -1;

	while (low_lim <= up_lim) {
		middle = (up_lim + low_lim)/2;

		if (L->elements[middle] == value) {
			found_position = middle;
			low_lim = middle + 1;

		} else if (L->elements[middle] < value)
			low_lim = middle + 1;

		else
			up_lim = middle - 1;
	}

	return found_position;	
}

int count(List* L, int value) { 
	// Returns how many times the value appears in the list [O(log N)]
	int first = search_first(L, value); 
	
	if (first == -1)
		return 0;
		
	int last = search_last(L, value);
	
	return last - first + 1;
}

bool remove_element(List* L, int value) {
	// Removes one occurrence of the value from the list. Returns true if a removal occurred, false otherwise [O(N)]
	int found_position = search_last(L, value);
	
	if (found_position ==  -1)
		return false;
	
	else {
		L->size--;
		
		for (int i = found_position; i < L->size; i++)
			L->elements[i] = L->elements[i+1];
		
		return true;
	}
}

int remove_all(List* L, int value) { 
	// Removes all occurrences of the value from the list. Returns the number of removed elements [O(N)]
	int first = search_first(L, value);
	
	if (first == -1)
		return 0;
	
	int last = search_last(L, value), count = last - first + 1;

	L->size -= count;
	
	for (int i = first; i < L->size; i++)
		L->elements[i] = L->elements[i + count];
		
	return count;
}

int length(List* L) {
	// Returns the current number of elements in the list [θ(1)]
	return L->size;
}

int max_length(List* L) {
	// Returns the capacity (maximum number of elements) of the list [θ(1)]
	return L->capacity;
}

bool is_empty(List* L) {
	// Returns true if the list is empty, false otherwise [θ(1)]
	return (L->size == 0);
}

bool is_full(List* L) {
	// Returns true if the list is full, false otherwise [θ(1)]
	return (L->size == L->capacity);
}

void clear(List* L) {
	// Clears the list by setting its size to 0 [θ(1)]
	L->size = 0;
}

void print_list(List* L) {
	// Prints all element of the list in order [θ(N)]
	for (int i = 0; i < L->size; i++)
		printf("|%d", L->elements[i]);

	printf((L->size > 0) ? "|\n" : "\n");
}
