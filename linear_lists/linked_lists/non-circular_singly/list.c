#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List* new_list() {
	// Creates a linked list and returns a pointer to it [θ(1)]
	List* L = malloc(sizeof(List));
	L->size = 0;
	L->head = NULL;

	return L;
}

void destroy_list(List* L) {
	// Destroys the list and frees its memory [θ(N)]
	clear(L);
	free(L);
}

void insert(List* L, int value) { 
	// Inserts a element into the list [θ(1)]
	Node* p = malloc(sizeof(Node));
	p->element = value;
	p->next = L->head;
	L->head = p;
	L->size++;
}

bool search(List* L, int value) {
	// Returns true if the value is in the list, false otherwise [O(N)]
	Node* p = L->head;
	
	while (p != NULL) {
		if (p->element == value)
			return true;
		
		p = p->next;
	}

	return false;
}

int count(List* L, int value) { 
	// Returns how many times the value appears in the list [θ(N)]
	int count = 0;
	Node* p = L->head;
	
	while (p != NULL) {
		if (p->element == value)
			count++;
		
		p = p->next;
	}
	
	return count;
}

bool remove_element(List* L, int value) {
	// Removes the first occurrence of the value in the list. And returns true if a removal occurred, otherwise false [O(N)]
	Node* p = L->head;
	Node* pPrev = NULL;
	
	while (p != NULL) {
		if (p->element == value) {
			if (pPrev == NULL)
				L->head = p->next;
				
			else
				pPrev->next = p->next;
			
			free(p);
			L->size--;
			
			return true;
		}
		
		pPrev = p;
		p = p->next;
	}
	
	return false;
}

int remove_all(List* L, int value) { 
	// Removes all occurrences of value in the list. And returns how many elements were removed [θ(N)]
	int count = 0;
	Node* p = L->head;
	Node* pPrev = NULL;

	while (p != NULL) {
		if (p->element == value) {
			if (pPrev == NULL) {
				L->head = p->next;
				free(p);
				p = L->head;
				
			} else {
				pPrev->next = p->next;
				free(p);
				p = pPrev->next;
			}
			
			count++;
			
		} else {
			pPrev = p;
			p = p->next;
		}
	}
	
	L->size -= count;
	
	return count;
}

int length(List* L) {
	// Returns the current number of elements in the list [θ(1)]
	return L->size;
}

bool is_empty(List* L) {
	// Returns true if the list is empty, false otherwise [θ(1)]
	return (L->size == 0);
}

void clear(List* L) {
	// Clears the list freeing its nodes [θ(N)]
	while (L->head != NULL) {
		Node* p = L->head;
		L->head = L->head->next;
		free(p);
	}
	
	L->size = 0;
}

void print_list(List* L) {
	// Prints each element of the list [θ(N)]
	Node* p = L->head;
	
	while (p != NULL) {
		printf("|%d|->", p->element);
		p = p->next;
	}
	
	printf("X\n");
}
