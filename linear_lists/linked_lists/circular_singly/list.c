#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List* new_list() {
	// Creates a linked list and returns a pointer to it [θ(1)]
	List* L = malloc(sizeof(List));
	L->head = L->tail = NULL;
	L->size = 0;

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
	p->next = (L->head == NULL) ? p : L->head;
	L->head = p;
	
	if (L->tail == NULL)
		L->tail = p;
		
	else 
		L->tail->next = p;
		
	L->size++;
}

bool search(List* L, int value) {
	// Returns true if the value is in the list, false otherwise [O(N)]
	if (L->head != NULL) {
		Node* p = L->head;
		
		do {
			if (p->element == value)
				return true;
			
			p = p->next;
		} while (p != L->head);
	}
	
	return false;
}

int count(List* L, int value) { 
	// Returns how many times the value appears in the list [θ(N)]
	int count = 0;

	if (L->head != NULL) {
		Node* p = L->head;
		
		do {
			if (p->element == value)
				count++;
			
			p = p->next;
		} while (p != L->head);
	}
	
	return count;
}

bool remove_element(List* L, int value) {
	// Removes the first occurrence of the value in the list. And returns true if a removal occurred, otherwise false [O(N)]
	if (L->head != NULL) {
		Node* p = L->head;
		Node* pPrev = NULL;
		
		do {
			if (p->element == value) {
				if (p == L->head) {
					if (L->size == 1)
						L->head = L->tail = NULL;
						
					else
						L->head = L->tail->next = p->next;
					
				} else if (p == L->tail) {
					pPrev->next = L->head;
					L->tail = pPrev;
					
				} else
					pPrev->next = p->next;
				
				free(p);
				L->size--;
				
				return true;
			}
			
			pPrev = p;
			p = p->next;
		} while (p != L->head);
	}
	
	return false;
}

int remove_all(List* L, int value) { 
	// Removes all occurrences of value in the list. And returns how many elements were removed [θ(N)]
	int count = 0;

	if (L->head != NULL) {
		Node* p = L->head;
		Node* pPrev = NULL;
	
		do {
			if (p->element == value) {
				if (p == L->head) {
					if (L->size == 1)
						L->head = L->tail = NULL;
						
					else
						L->head = L->tail->next = p->next;
						
					free(p);
					p = L->head;
						
				} else if (p == L->tail) {
					L->tail = pPrev;
					L->tail->next = L->head;
					free(p);
					
				} else {
					pPrev->next = p->next;
					free(p);
					p = pPrev->next;
				}
				
				count++;
				L->size--;
				
			} else {
				pPrev = p;
				p = p->next;
			}
		} while (pPrev != L->tail);
	}
	
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
	while (L->head != L->tail) {
		Node* p = L->head;
		L->head = L->head->next;
		free(p);
	}
	
	free(L->tail);
	
	L->head = L->tail = NULL;
	L->size = 0;
}

void print_list(List* L) {
	// Prints each element of the list [θ(N)]
	if (L->head != NULL) {
		Node* p = L->head;
		
		printf("...->");
		
		do {
			printf("|%d|->", p->element);
			p = p->next;
		} while (p != L->head);
	}
	
	printf("...\n");
}
