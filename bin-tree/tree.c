#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

/*
	call it for the root node
*/
void tree_init(node** nP, int val){
	(*nP)->parent = (*nP)->left = (*nP)->right = NULL;
	(*nP)->data = val;
}
/* 
	insertion algorithm is described on wikipedia:
	https://en.wikipedia.org/wiki/Binary_heap
*/
void tree_insert(node** nP, int val){
	node* new_node = (node*) malloc(sizeof(node));
	new_node->data = val;

	if ( val OP (*nP)->data){
		if ( (*nP)->left == NULL ) {
			(*nP)->left = new_node;
			(*nP)->left->data = val;
			new_node->parent = *nP;
		} else {
			tree_insert(&(*nP)->left, val);
		}
	} else {
		if ( (*nP)->right == NULL ) {
			(*nP)->right = new_node;
			(*nP)->right->data = val;
			new_node->parent = *nP;
		} else {
			tree_insert(&(*nP)->right, val);
		}
	}
}

/*
	follow leftmost branches to return min
*/
int tree_get_min(node** rootP){
	node* tempP = (node*) malloc(sizeof(node));
	tempP = *rootP;
	while ( tempP->left ) 
		tempP = tempP->left;
	return tempP->data;
}

/*	similar */
int tree_get_max(node** rootP){
	node* tempP = (node*) malloc(sizeof(node));
	tempP = *rootP;
	while ( tempP->right ) 
		tempP = tempP->right;
	return tempP->data;
}

/*
	binary search on tree
	return val if found, otherwise -1
	assume node data are non negative
	ret 0 for not found, 1 for found
*/
int tree_search(node** nP, int val) {
	if (*nP) {
		if ( (*nP)->data == val ) 
			return (*nP)->data == val;
		 else if ( val OP (*nP)->data )
			tree_search(&(*nP)->left, val);
		else
			tree_search(&(*nP)->right, val);
	} else { 
		return 0;
	}
}


/*
	spread to the left and right child
	then delete their parent
*/
void tree_del_all(node** nP){
	if ( *nP ){
		tree_del_all(&(*nP)->right);
		tree_del_all(&(*nP)->left);
		free(*nP);
		*nP = NULL;
	}
}

/*
	depth first search to visit all nodes once
	adapted from here:
	https://gist.github.com/0xLeo/dbd53a1b47e5cf6c2b34
	flag to !=0 to print data
*/
void tree_print(node* nP, node** newP, long int ctr, int* max, const int* printFlag) {
      if ( nP && *printFlag ) printf("@depth %lu: %d\n" , ctr, nP->data);
          ctr++; 
         if ( nP->right )  tree_print(nP->right, newP, ctr, max, printFlag);
         if ( nP->left )  tree_print(nP->left, newP, ctr, max, printFlag);

}

/*
	input: a space-separated file f
		caller function is responsible for 
		where to start reading from and
		to close the file
	output: a tree nP that contains the integers
		read from file
	notes: file may contain up to 4 ints per line
		if more, they are ignored
*/		
int tree_finsert (FILE* f, node** nP) { 

	// 4 nums/ line =>
	// worst case length po 2 = (2^(ceil(log(12*4+4)/log(2))) = 64
	char buf[64];
	int buf2int[4], numel = 0;
	short int how_many,  first_time = 0; // was last sscanf successful?, tree init flag
	
	while ( fgets( buf, 64, f) != NULL ) {

		how_many = 0;
		how_many += (sscanf(buf, "%d %d %d %d", 
			&buf2int[0],  &buf2int[1],  &buf2int[2],  &buf2int[3]) == 4) * 4;
		how_many += (sscanf(buf, "%d %d %d", 
			&buf2int[0],  &buf2int[1],  &buf2int[2] ) == 3 && how_many == 0) * 3;
		how_many += (sscanf(buf, "%d %d", 
			&buf2int[0],  &buf2int[1]  ) == 2 && how_many == 0 ) * 2;
		how_many += (sscanf(buf, "%d", 
			&buf2int[0]) == 1  &&  how_many == 0);
		
		if ( (++first_time -1 ) == 0 )
			tree_init(nP, buf2int[0]);
		else
		{
			for (int i = 0 + (first_time == 1); i < how_many; i++)
				tree_insert(nP, buf2int[i]);
		}
		
	}
}
