#include <stdio.h>

typedef struct node_list {
	void *data,
	struct node_list *next
} node_list_t;

typedef node_list_t * ADT_list_t;

status_t ADT_list_reverse(ADT_list_t *l) {

	node_list_t * prev = null;
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

status_t ADT_list_concat(ADT_list_t *l1, ADT_list_t l2) {

	node_list_t * curr = l1;

	if(curr == NULL) {
		*l1 = l2;
		return OK;
	}

	while(curr->next != NULL) {
		curr = curr->next;
	}

	curr->next = l2;
	return OK;

}

