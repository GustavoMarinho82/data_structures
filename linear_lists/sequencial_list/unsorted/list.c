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
	// Inserts a element into the end of the list [θ(1)]
	if (L->size == L->capacity) {
		fprintf(stderr, "List overflow!\n");
		exit(EXIT_FAILURE);
	}

	L->elements[(L->size)++] = value;
}

bool search(List* L, int value) {
	// Returns true if the value is in the list, false otherwise [O(N)]
	for (int i = 0; i < L->size; i++) {
		if (L->elements[i] == value)
			return true;
	}

	return false;
}

int count(List* L, int value) { 
	// Returns how many times the value appears in the list [θ(N)]
	int count = 0;

	for (int i = 0; i < L->size; i++) {
		if (L->elements[i] == value)
			count++;
	}
	
	return count;
}

bool remove_element(List* L, int value) {
	// Removes the first occurrence of the value in the list. And returns true if a removal occurred, otherwise false [O(N)]
	for (int i = 0; i < L->size; i++) {
		if (L->elements[i] == value) {
			L->elements[i] = L->elements[--(L->size)];
			return true;
		}
	}

	return false;
}

int remove_all(List* L, int value) { 
	// Removes all occurrences of value in the list. And returns how many elements were removed [θ(N)]
	int count = 0;

	for (int i = 0; i < L->size;) {
		if (L->elements[i] == value) {
			L->elements[i] = L->elements[--(L->size)];
			count++;
			
		} else
			i++;
	}

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
	// Prints each element of the list [θ(N)]
	for (int i = 0; i < L->size; i++)
		printf("|%d", L->elements[i]);

	printf((L->size > 0) ? "|\n" : "\n");
}
