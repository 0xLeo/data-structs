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
      if (( nP && *printFlag )){ printf("@depth %lu: %d\n" , ctr, nP->data);};
          ctr++; 
         if ( nP->right ) { tree_print(nP->right, newP, ctr, max, printFlag); }
         if ( nP->left ) { tree_print(nP->left, newP, ctr, max, printFlag); }

}

