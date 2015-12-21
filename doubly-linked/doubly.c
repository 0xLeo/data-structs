#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset
#include "doubly.h"
#define SIZE_INPUT 30 


void list_init(nodeP* head, nodeP* tail) {
	*head = (nodeP) malloc(sizeof(node));
	*tail= (nodeP) malloc(sizeof(node));
	*head = NULL;
	*tail = NULL;
}

void list_insert(nodeP* head, nodeP* tail,  int val) {
	nodeP new_node = (nodeP) malloc(sizeof(node));
	new_node->data = val;

	new_node->next = *head;
	new_node->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = new_node;
	else
		*head = *tail = new_node;	
	*head = new_node;
}

void list_append(nodeP* head, nodeP* tail, const int val) {
	nodeP new_node = (nodeP) malloc(sizeof(node));
	new_node->data = val;

	new_node->prev = *tail;
	new_node->next = NULL;

	if ((*tail) != NULL)
		(*tail)->next = new_node;
	else
		*head = *tail = new_node;
	*tail = new_node;
}

void list_insert_at (nodeP* head, const int n, const int val ){
	nodeP new_node = (nodeP) malloc(sizeof(node));
	new_node->data = val;

	nodeP where = (nodeP) malloc(sizeof(node));

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
void list_print_tail( nodeP* tail){
	nodeP where = (nodeP) malloc(sizeof(node));

	where = *tail;

	while (where != NULL){
		printf("%d ", where->data);
		where=where->prev;
	}
	printf("\n");
}

/* traverse from head to tail */
void list_print_head(nodeP* head){
	nodeP where = (nodeP) malloc(sizeof(node));

	where = *head;

	while (where != NULL){
		printf("%d ", where->data);
		where=where->next;
	}
	printf("\n");
}

void list_del(nodeP* head) {
	nodeP where = (nodeP) malloc(sizeof(node));
	nodeP temp = (nodeP) malloc(sizeof(node));

	where = *head;

	while (where != NULL){
		temp = where;
		where = where->next;
		free(temp);
		memset(temp, 0, sizeof(node)); 
	}
	*head = NULL;
	
}

void list_del_at (nodeP* head, nodeP* tail, const int n) {

	nodeP where = (nodeP) malloc(sizeof(node));

	where = *head;
	if (n > 1 ) {
		if (  where->next  ) {
			nodeP temp  = (nodeP) malloc(sizeof(node));

			int i =0;
			while (i < n-1 && where != NULL){
				where=where->next;
				i++;
			}
			// to correct the index
			where=where->prev;
			
			
			where->next->next->prev = where;
			free(where->next);
			memset(where->next,0,sizeof(node));	
			temp=where->next->next;
			where->next = temp;
			
			//temp=NULL;
			free(temp);
			memset(temp,0,sizeof(node));
		}
	} else if ( n == 1) {
		//update head
		if (head ) {
			nodeP temp  = (nodeP) malloc(sizeof(node));
			temp = *head;
			*head = (*head)->next;
			(*head)->prev = NULL;
			free(temp);
			//
			memset(temp,0,sizeof(node));
		}
	} else  {
		//update tail
		if (tail ) {
			nodeP temp  = (nodeP) malloc(sizeof(node));
			temp = *tail;
			//printf("--tail->prev=%d\n",((*tail)->prev)->data);
			*tail = (*tail)->prev;
			(*tail)->next = NULL;
			free(temp);
			memset(temp,0,sizeof(node));
		}
	}
}

