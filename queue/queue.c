#include <stdlib.h>
#include <stdio.h>
#include "queue.h" 


enum {
	NO_ERROR,
	ERROR_CANNOT_ALLOC,
	ERROR_LIST_EMPTY
} ErrorCodes;


void printPoint(Point pt) {
	printf("(%u, %u) ", pt.x, pt.y);
}

/**
 * @brief Sets head and tail to null
 *
 * @param queue A queue to initialise
 */
void init(Queue* queue){
	queue->head = NULL;
	queue->tail = NULL;
}


unsigned int isEmpty(Queue* queue){
	return queue->head == queue->tail;
}


/**
 * @brief Add a point at the end (tail) of the queue. 
 *
 * @param queue A Queue
 * @param pt A Point structure
 *
 * @return A positive integer if error, else 0
 */
unsigned int append(Queue* queue, Point pt){
	PointNode* next = malloc(sizeof(PointNode));
	if (next == NULL)
		return ERROR_CANNOT_ALLOC;
	next->pt = pt;
	next->next = NULL;

	if (queue->head == NULL)
		queue->head = queue->tail = next; 
	else{
		queue->tail->next = next;
		queue->tail = next;
	}

}


/**
 * @brief Prints the contents of the queue from head to tail
 *
 * @param queue A Queue
 *
 * @return A positive integer if error, else 0
 */
unsigned int printQueue(Queue* queue) {
	if (isEmpty(queue)) 
		return ERROR_LIST_EMPTY;
	PointNode* iter = queue->head;
	if (iter == NULL)
		return ERROR_CANNOT_ALLOC;
	// do the work
	do { 
		printPoint(iter->pt);
		iter  = iter->next;
	} while (iter != NULL);

	free(iter);
}


/**
 * @brief Remove the last element (at tail)
 *
 * @param queue A Queue
 *
 * @return A positive integer if error, else 0
 */
unsigned int pop(Queue* queue) {
	// if head next not null
	PointNode* tmp = queue->head;
	if (tmp == NULL)
		return ERROR_CANNOT_ALLOC;
	queue->head = queue->head->next;
	free(tmp);
}


/**
 * @brief del (free) all nodes of the Queue
 *
 * @param queue A Queue
 *
 * @return A positive integer if error, else 0
 */
unsigned int del(Queue* queue) {
	// check for errors
	if (isEmpty(queue))
		return ERROR_LIST_EMPTY;
	PointNode* iter = malloc(sizeof(PointNode));
	if (iter == NULL)
		return ERROR_CANNOT_ALLOC;
	// do the work
	do {
		iter = queue->head;
		queue->head = queue->head->next;
		free(iter);
	} while (queue -> head != NULL);
}
