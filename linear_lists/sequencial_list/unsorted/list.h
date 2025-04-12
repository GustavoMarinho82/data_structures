#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct List {
	int* elements;
	int size; // current number of elements
	int capacity; // max number of elements
} List;

List* new_list(int); // θ(1)
void destroy_list(List*); // θ(1)
void insert(List*, int); // θ(1)
bool search(List*, int); // O(N)
int count(List*, int); // θ(N)
bool remove_element(List*, int); // O(N)
int remove_all(List*, int); // θ(N)
int length(List*); // θ(1)
bool is_empty(List*); // θ(1)
bool is_full(List*); // θ(1)
void clear(List*); // θ(1)
void print_list(List*); // θ(N)

#endif
