#ifndef	DOUBLY_H
#define DOUBLY_H

#define SIZE_TEST1 30
#define SIZE_TEST2 1000000 

typedef struct _node {
	int data;
	struct _node* next;	
	struct _node* prev;	
} Node;

typedef Node* NodeP;

void list_init(NodeP* head, NodeP* tail);
void list_insert(NodeP* head, NodeP* tail, const int val);
void list_append(NodeP* head, NodeP* tail, const int val);
void list_insert_at(NodeP* head, const int n, const int val);
void list_print_tail(NodeP* tail);
void list_print_head(NodeP* head);
void list_rev (NodeP* head);
void list_del(NodeP* head);
void list_del_at(NodeP* head, NodeP* tail,const int val);

#endif
