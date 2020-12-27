#pragma once
#include <stdio.h>
#include <malloc.h>
typedef struct ListNode {
	void* data;
	struct ListNode* next;
	struct ListNode* prev;
} ListNode;
typedef struct List {
	ListNode* head;
	ListNode* tail;
	int size;
} List;
//Func to initialize list
List* init_list();
//Func to add tail in list
void list_add_tail(List* list, void* data);
//Func to add tail in head and push head to the second place of list
void list_add_head(List* list, void* data);
//Func to delete part of list by pointer
void list_delete_part(List *list, int var, void delete_func(void*));
//TOTAL DESTRUCTION
void delete_list(List *list, void delete_func(void*));
//Func to get data from Listnode(ListNode->data)
void *list_get_data(List *list, int var);
//Func to switch two pointers of data
void list_data_changer(List *list, int i, int j);