#include <stdio.h>
#include <malloc.h>
typedef struct ListNode ListNode;
 struct ListNode {
	void* data;
	ListNode* next;
	ListNode* prev;
};
typedef struct List {
	ListNode* head;
	ListNode* tail;
	int size;
}List;

List* init_list() {
	List* list = (List*)malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}
void list_add_tail(List* list, void* data) {
	ListNode* tmp;
	tmp = (ListNode*)malloc(sizeof(ListNode));
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail == NULL) {
		list->tail = tmp;
		list->head = tmp;
		list->size = 1;
	}
	else {
		list->tail->next = tmp;
		list->tail = tmp;
		list->size++;
	}
}

void list_add_head(List* list, void* data) {
	ListNode* tmp;
	tmp = (ListNode*)malloc(sizeof(ListNode));
	tmp->data = data;
	tmp->prev = NULL;
	tmp->next = list->head;
	if (list->head != 0) {
		list->head->prev = tmp;
	}
	if (list->size == 0) {
		list->head = list->tail = tmp;
	}
	else {
		list->head = tmp;
	}
	list->size++;
}

ListNode* list_get_part(List* list, int num) {
	ListNode* tmp = NULL;
	if (list->size < num || num < 0) {
		return NULL;
	}
	else if (list->size / 2 >= num) {
		tmp = list->head;
		for (int i = 0; num != i; i++) {
			tmp = tmp->next;
		}
		return tmp;
	}
	else if (list->size / 2 <= num) {
		tmp = list->tail;
		for (int i = list->size; num + 1 != i; i--) {
			tmp = tmp->prev;
		}
		return tmp;
	}
}

void delete_node(ListNode* tmp, void delete_func(void*)) {
	delete_func(tmp->data);
	free(tmp);
}

void int_delete(List* list, ListNode* node, void delete_func(void*)) {
	if (node == list->head) {
		list->head = node->next;
		if (list->head != NULL)
			list->head->prev = NULL;
	}

	if (node == list->tail) {
		list->tail = node->prev;
		if (list->tail != NULL)
			list->tail->next = NULL;
	}
	delete_node(node, delete_func);
	list->size -= 1;
}

void list_delete_part(List* list, int var, void delete_func(void*)) {
	ListNode* node = list_get_part(list, var);
	int_delete(list, node, delete_func);
}

void delete_list(List* list, void delete_func(void*)) {
	ListNode* tmp;
	while (list->tail != list->head) {
		tmp = list->tail;
		list->tail = list->tail->prev;
		delete_node(tmp, delete_func);
	}
	free(list->tail);
	free(list);
}

void* list_get_data(List* list, int var) {
	ListNode* myList1 = list_get_part(list, var);
	return myList1->data;
}

void list_data_changer(List* list, int i, int j) {
	void* tmp;
	ListNode* myList1 = list_get_part(list, i);
	ListNode* myList2 = list_get_part(list, j);
	tmp = myList1->data;
	myList1->data = myList2->data;
	myList2->data = tmp;
}
