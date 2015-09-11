#include <stdio.h>
#include <stdlib.h>
/*
	swap data between two nodes
*/ 
void tree_swap(node* nP1, node* nP2){
    int temp = nP2->_data;
    nP2->_data = nP1->_data;
    nP1->_data = temp;
}
 
/*
	takes the root of the tree, a new node
	where the last parent will be written to,
	a counter passed as 0, and max = inf
	
	The recursions can be unwrapped in the 
	following pseudocode, based on Depth 
	First Search

	visited = {}
	leaves = {}
	myNode = root
	add root in visited
	if ( myNode->_right != NULL and myNode not in visited ){
		myNode = myNode->_right
		add myNode in visited
		if (myNode->_left == NULL or myNode->_right == NULL ) {
			add myNode in leaves
		}
	} else {
		myNode = myNode->_parent
		if (myNode->_left != NULL and myNode->_left not in visited )
		myNode = myNode->_left
		add myNode in visited
		if (myNode->_left == NULL or myNode->_right == NULL ) {
			add myNode in leaves
		}
	}
	lastParent = leaves.getLastElement()
*/
node* tree_glp(node* nP, node** newP, long int ctr, int* max) {
    printf("@depth %lu: %d\n" , ctr, nP->_data);
    if ((nP->_left == NULL) || (nP->_right == NULL)){
        if (ctr <= *max) {
            *max = ctr; 
            *newP = nP;
        }
        ctr=0;
        return *newP;
    } else {
        ctr++;
        tree_glp(nP->_right, newP, ctr, max);
        tree_glp(nP->_left, newP, ctr, max);
     
    }
}
 
/* 
	takes the last parent (lastP)
	if its left child is NULL,
	insert a new node there
	otherwise insert it in the right 
	child
*/	
void tree_insert (node* lastP, int val) {
    node* newP = (node*)malloc (sizeof(node));
    newP->_data = val;
    if ( lastP->_left == NULL) {
        newP->_parent = lastP;
        lastP->_left = newP;
    } else {
       	newP->_parent = lastP;
        lastP->_right= newP;
    }
}
