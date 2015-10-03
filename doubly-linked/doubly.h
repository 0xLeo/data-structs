#ifndef	DOUBLY_H
#define DOUBLY_H

#define SIZE_TEST1 30
#define SIZE_TEST2 6000000 

typedef struct _node {
	int data;
	struct _node* next;	
	struct _node* prev;	
} node;

typedef node* nodeP;

void list_init(nodeP* head, nodeP* tail);
void list_insert(nodeP* head, nodeP* tail, const int val);
void list_append(nodeP* head, nodeP* tail, const int val);
void list_insert_at(nodeP* head, const int n, const int val);
void list_print_tail(nodeP* tail);
void list_print_head(nodeP* head);
void list_del(nodeP* head);
void list_del_at(nodeP* head, nodeP* tail,const int val);

#endif
