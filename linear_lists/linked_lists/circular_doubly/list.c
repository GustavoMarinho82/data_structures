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
	
	if (L->head == NULL)
		L->head = L->tail = p->next = p->prev = p;
	
	else {
		p->next = L->head;
		p->prev = L->tail;
		L->head->prev = L->tail->next = p;
		L->head = p;
	}
		
	L->size++;
}

bool search(List* L, int value) {
	// Returns true if the value is in the list, false otherwise [O(N/2)]
	if (L->head != NULL) {
		Node* pLeft = L->head;
		Node* pRight = L->tail;
	
		while (true) {
			if ((pLeft->element == value) || (pRight->element == value))
				return true;
				
			if ((pLeft == pRight) || (pLeft->next == pRight)) 
				break;
				
			pLeft = pLeft->next;
			pRight = pRight->prev;
		}
	}
		
	return false;
}

int count(List* L, int value) { 
	// Returns how many times the value appears in the list [θ(N)]
	int count = 0;
	Node* p = L->head;
	
	do {
		if (p->element == value)
			count++;
		
		p = p->next;
	} while (p != L->head);
	
	return count;
}

void remove_node(List* L, Node* p) {
	// Removes a node from the list. Assumes the node is within this list. [θ(1)]
	if (p != NULL) {
		if (p->next == p) {
			L->head = L->tail = NULL;
			
		} else {
			if (L->head == p)
				L->head = p->next;
			
			if (L->tail == p)
				L->tail = p->prev;
			
			p->prev->next = p->next;
			p->next->prev = p->prev;
		}
		
		free(p);
		L->size--;
	}
}

bool remove_element(List* L, int value) {
	// Removes an occurrence of the value in the list. And returns true if a removal occurred, otherwise false [O(N/2)]
	if (L->head != NULL) {
		Node* pLeft = L->head;
		Node* pRight = L->tail;
		
		while (true) {
			if (pLeft->element == value) {
				remove_node(L, pLeft);
				return true;
			}
			
			if (pRight->element == value) {
				remove_node(L, pRight);
				return true;
			}
			
			if ((pLeft == pRight) || (pLeft->next == pRight)) 
				break;
				
			pLeft = pLeft->next;
			pRight = pRight->prev;
		}
	}
	
	return false;
}

int remove_all(List* L, int value) { 
	// Removes all occurrences of value in the list. And returns how many elements were removed [θ(N)]
	int count = 0;
	Node* p = L->head;
	Node* pTemp;
	
	for (int i = 0, j = L->size; i < j; i++) {
		if (p->element == value) {
			pTemp = (p->next != p) ? p->next : NULL;
			remove_node(L, p);
			count++;
			p = pTemp;
				
		} else
			p = p->next;
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
			printf("|%d|<>", p->element);
			p = p->next;
		} while (p != L->head);
	}
	
	printf("...\n");
}
