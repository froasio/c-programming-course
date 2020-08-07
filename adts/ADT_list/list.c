#include <stdio.h>
#include <stdlib.h>

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	ERROR_NO_MEMORY,
	ERROR_OUT_OF_RANGE
} status_t;

typedef enum {
	FALSE,
	TRUE
} bool_t;

typedef struct node_list {
	void *data;
	struct node_list *next;
} node_list_t;

typedef node_list_t * ADT_list_t;

status_t ADT_list_new(node_list_t **l);
bool_t ADT_list_is_empty(node_list_t *l);
status_t ADT_list_iterate(node_list_t *l, status_t (*it)(void*));
status_t ADT_list_new_node(node_list_t **l, void *data);
status_t ADT_list_append(node_list_t **l, void *data);
status_t ADT_list_destroy(node_list_t **l, void(*destroy)(void **));

status_t ADT_list_reverse(ADT_list_t *l);
status_t ADT_list_concat(ADT_list_t *l1, ADT_list_t *l2);
status_t ADT_list_clone(ADT_list_t l1, ADT_list_t *l2, status_t(*clone)(const void*, void**), void(*destroy)(void **));

ADT_list_t array_to_list(int v[], size_t l);

void destroy_int(void **i);
status_t print_int(void *i); 
status_t clone_int(const void *, void **);

int main() {

	ADT_list_t l1, l2, l3;
	int v1[] = {1,2,3,4};
	int v2[] = {5,6,7,8};
	
	l1 = array_to_list(v1, 4);
	l2 = array_to_list(v2, 4);
	ADT_list_iterate(l1, print_int);
	puts("----");
	ADT_list_reverse(&l1);
	ADT_list_iterate(l1, print_int);
	puts("----");
	ADT_list_concat(&l1, &l2);
	ADT_list_iterate(l1, print_int);
	puts("----");
	ADT_list_clone(l1, &l3, clone_int, destroy_int);
	ADT_list_iterate(l3, print_int);

	ADT_list_destroy(&l1, destroy_int);
	ADT_list_destroy(&l3, destroy_int);

	return 0;
}

status_t ADT_list_new(node_list_t **l){
	*l = NULL;
	return OK;
}

bool_t ADT_list_is_empty(node_list_t *l) {
	return l->next == NULL ? TRUE : FALSE;
}

status_t ADT_list_iterate(node_list_t *l, status_t (*it)(void*)) {
	status_t st;
	while(l != NULL) {
		st = it(l->data);
		if(st != OK)
			return st;
		l = l->next;
	}
	return OK;
} 	

status_t ADT_list_new_node(node_list_t **l, void *data) {
	
	*l = (node_list_t*) malloc(sizeof(node_list_t));
	if(l == NULL)
		return ERROR_NO_MEMORY;
	
	(*l)->data = data;
	(*l)->next = NULL;

	return OK;
}

status_t ADT_list_append(node_list_t **l, void *data) {
	node_list_t *ll, *tmp;
	status_t st;

	st = ADT_list_new_node(&ll, data);
	if(st != OK)
		return st;

	if(*l == NULL) {
		*l = ll;
		return OK;
	}

	for(tmp = *l; tmp->next != NULL; tmp = tmp->next);
	tmp->next = ll;

	return OK;
		
}

status_t ADT_list_destroy(node_list_t **l, void(*destroy)(void **)) {
	node_list_t *tmp;

	while(*l != NULL) {
		destroy(&((*l)->data));
		tmp = (*l)->next;
		free(*l);
		*l = tmp;
	}

	return OK;
}

ADT_list_t array_to_list(int v[], size_t l) {
	size_t i;
	ADT_list_t nl;
	int *n;

	ADT_list_new(&nl);

	for(i = 0; i < l; i++) {
		n = (int*)malloc(sizeof(int));
		if(n == NULL) {
			ADT_list_destroy(&nl, destroy_int);
			return NULL;
		}
		*n = v[i];
		ADT_list_append(&nl, n);
	}
	return nl;
}

status_t ADT_list_reverse(ADT_list_t *l) {

	node_list_t * prev = NULL;
	node_list_t * curr = *l;
	node_list_t * next;

	while(curr != NULL) {

		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;

	}

	*l = prev;
	return OK;
}

status_t ADT_list_concat(ADT_list_t *l1, ADT_list_t *l2) {

	node_list_t * curr = *l1;

	if(curr == NULL) {
		*l1 = *l2;
		return OK;
	}

	while(curr->next != NULL) {
		curr = curr->next;
	}

	curr->next = *l2;
	*l2 = NULL;
	return OK;

}

status_t print_int(void *i) {
	int *ii = (int*) i;
	printf("%d \n", (*ii));
	return OK;
}

void destroy_int(void **i) {
	int **ii = (int**) i;
	free(*ii);
	*ii = NULL;
}

status_t clone_int(const void *iv, void**ivc){

	int *ic;

	if(iv == NULL)
		return ERROR_NULL_POINTER;

	ic = (int*) malloc(sizeof(int));
	if(ic == NULL)
		return ERROR_NO_MEMORY;

	*ic = *((int*)iv);
	*ivc = (void*)ic;

	return OK;
}

status_t ADT_list_clone(ADT_list_t l1, ADT_list_t *l2, status_t(*clone)(const void*, void**), void(*destroy)(void **)) {

	status_t st;
	void *node_clone;
	ADT_list_new(l2);

	while(l1 != NULL) {

		st = clone(l1->data, &node_clone);
		if(st != OK){
			ADT_list_destroy(l2, destroy);
			return st;
		}
			
		st = ADT_list_append(l2, node_clone);
		if(st != OK){
			ADT_list_destroy(l2, destroy);
			return st;
		}
			
		l1 = l1->next;

	}
	return OK;

}