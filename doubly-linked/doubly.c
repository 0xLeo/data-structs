#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset
#include "doubly.h"
#define SIZE_INPUT 30 


void list_init(NodeP* head, NodeP* tail) {
	*head = (NodeP) malloc(sizeof(Node));
	*tail= (NodeP) malloc(sizeof(Node));
	*head = NULL;
	*tail = NULL;
}

void list_insert(NodeP* head, NodeP* tail,  int val) {
	NodeP new_node = (NodeP) malloc(sizeof(Node));
	new_node->data = val;

	new_node->next = *head;
	new_node->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = new_node;
	else
		*head = *tail = new_node;	
	*head = new_node;
}

void list_append(NodeP* head, NodeP* tail, const int val) {
	NodeP new_node = (NodeP) malloc(sizeof(Node));
	new_node->data = val;

	new_node->prev = *tail;
	new_node->next = NULL;

	if ((*tail) != NULL)
		(*tail)->next = new_node;
	else
		*head = *tail = new_node;
	*tail = new_node;
}

void list_insert_at (NodeP* head, const int n, const int val ){
	NodeP new_node = (NodeP) malloc(sizeof(Node));
	new_node->data = val;

	NodeP where = (NodeP) malloc(sizeof(Node));

	where = *head;
	int i =0;
	while (i < n-1 && where != NULL){
		where=where->next;	
		i++;
	}
	// to correct the index, i.e. start from 1
	where = where->prev;

	new_node->next=where->next;
	new_node->prev=where;
	(where->next)->prev=new_node;
	where->next = new_node;
		
}

/* traverse from tail to head */
void list_print_tail( NodeP* tail){
	NodeP where = (NodeP) malloc(sizeof(Node));

	where = *tail;

	while (where != NULL){
		printf("%d ", where->data);
		where=where->prev;
	}
	printf("\n");
}

/* traverse from head to tail */
void list_print_head(NodeP* head){
	NodeP where = (NodeP) malloc(sizeof(Node));

	where = *head;

	while (where != NULL){
		printf("%d ", where->data);
		where=where->next;
	}
	printf("\n");
}

/*
 	list_rev
	use: list_rev (&head)
       	treats list as singly linked,
	reverses it by reversing the direction of links
	and moving head to tail
	
	algorithm:	
	find head
	head -> next = NULL
	while ( next node exists ) {
		move to next node
		new node's next = previous
 	}
 	the last new node we've reached is the new head
 */
void list_rev (NodeP* head) {
	NodeP newHead = NULL; 
	NodeP next = NULL;

	newHead = NULL;
	NodeP oldHead = *head;

	while ( oldHead ) {
		next = oldHead->next;
		oldHead->next = newHead;
		newHead = oldHead;
		oldHead = next;
	}
	
	free(next);
	free(oldHead);
	next = NULL;
	*head = newHead;
}

void list_del(NodeP* head) {
	NodeP where = (NodeP) malloc(sizeof(Node));
	NodeP temp = (NodeP) malloc(sizeof(Node));

	where = *head;

	while (where != NULL){
		temp = where;
		where = where->next;
		free(temp);
		memset(temp, 0, sizeof(Node)); 
	}
	*head = NULL;
	
}

void list_del_at (NodeP* head, NodeP* tail, const int n) {

	NodeP where = (NodeP) malloc(sizeof(Node));

	where = *head;
	if (n > 1 ) {
		if (  where->next  ) {
			NodeP temp  = (NodeP) malloc(sizeof(Node));

			int i =0;
			while (i < n-1 && where != NULL){
				where=where->next;
				i++;
			}
			// to correct the index
			where=where->prev;
			
			
			where->next->next->prev = where;
			free(where->next);
			memset(where->next,0,sizeof(Node));	
			temp=where->next->next;
			where->next = temp;
			
			//temp=NULL;
			free(temp);
			memset(temp,0,sizeof(Node));
		}
	} else if ( n == 1) {
		//update head
		if (head ) {
			NodeP temp  = (NodeP) malloc(sizeof(Node));
			temp = *head;
			*head = (*head)->next;
			(*head)->prev = NULL;
			free(temp);
			//
			memset(temp,0,sizeof(Node));
		}
	} else  {
		//update tail
		if (tail ) {
			NodeP temp  = (NodeP) malloc(sizeof(Node));
			temp = *tail;
			//printf("--tail->prev=%d\n",((*tail)->prev)->data);
			*tail = (*tail)->prev;
			(*tail)->next = NULL;
			free(temp);
			memset(temp,0,sizeof(Node));
		}
	}
}

