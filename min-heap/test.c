#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define SIZE 4000
 
typedef struct snode {
    int _data;
    struct snode* _left;
    struct snode* _right;
    struct snode* _parent;
} node;
 
void tree_swap(node* nP1, node* nP2);
void tree_insert(node* nP,int val);
node* tree_glp (node* nP, node** newP, long int ctr,  int* max);
 
int main() {
    node* n = ( node* ) malloc( sizeof( node));
    node* nn = ( node* ) malloc( sizeof( node));
    node* n1 = ( node* ) malloc( sizeof( node)); n1->_data = 1;
    node* n2 = ( node* ) malloc( sizeof( node)); n2->_data = 2;
    node* n3 = ( node* ) malloc( sizeof( node)); n3->_data = 3;
    node* n4 = ( node* ) malloc( sizeof( node)); n4->_data = 4;
    node* n5 = ( node* ) malloc( sizeof( node)); n5->_data = 5;
    node* n6 = ( node* ) malloc( sizeof( node)); n6->_data = 6;
    node* n7 = ( node* ) malloc( sizeof( node)); n7->_data = 7;
    node* n8 = ( node* ) malloc( sizeof( node)); n8->_data = 8;
    node* n9 = ( node* ) malloc( sizeof( node)); n9->_data = 9;
    node* n10 = ( node* ) malloc( sizeof( node)); n10->_data = 10;
    node* n11 = ( node* ) malloc( sizeof( node)); n11->_data = 11;

/*
	alternatively, use doubble pointers
	however let's specify the node ni's
	a bit more explicitely

node* nP = (node*) malloc( sizeof(node)*11 );
node** nPP=&nP;
(*nPP)->_data=1;
(*nPP+1)->_data=2;
//etc
*/

/*******************************************
               1
	    /      \
	    2       3
	  /   \   /   \
          4   5   6   7
	 / \ / 
         8 9 10	
*******************************************/
	n1->_left = n2; n1->_right = n3; n2->_parent = n3->_parent = n1;
	n2->_left = n4; n2->_right = n5; n4->_parent = n5->_parent = n2;
    int max = LONG_MAX;
    nn =tree_glp(n1, &n, 0, &max); max = LONG_MAX;
    tree_insert(n,6);
    nn =tree_glp(n1, &n, 0, &max); max = LONG_MAX;
    tree_insert(n,7);
    nn =tree_glp(n1, &n, 0, &max); max = LONG_MAX;
    tree_insert(n,8);
    nn =tree_glp(n1, &n, 0, &max); max = LONG_MAX;
    tree_insert(n,9);
    nn =tree_glp(n1, &n, 0, &max); max = LONG_MAX;
    tree_insert(n,10);
    nn =tree_glp(n1, &n, 0, &max); max = LONG_MAX;
    tree_insert(n,11);
    printf("\n");
    nn =tree_glp(n1, &n, 0, &max);
    printf("last parent = %d\n", n->_data);
}
 
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
