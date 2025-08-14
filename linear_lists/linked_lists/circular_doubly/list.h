#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct Node {
	int element;
	struct Node* next;
	struct Node* prev; // previous
} Node;

typedef struct List {
	struct Node* head;
	struct Node* tail;
	int size; // current number of elements
} List;

List* new_list(); //θ(1)
void destroy_list(List*); //θ(N)
void insert(List*, int); //θ(1)
bool search(List*, int); //O(N/2)
int count(List*, int); //θ(N)
bool remove_element(List*, int); //O(N/2)
int remove_all(List*, int); //θ(N)
int length(List*); //θ(1)
bool is_empty(List*); //θ(1)
void clear(List*); //θ(N)
void print_list(List*); //θ(N)

#endif
