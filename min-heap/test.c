#include <stdlib.h>
#include <stdio.h>
#include <limits.h> // LONG_MAX
#include "tree.h"
#include "tree.c"

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
	 / \ / \
         8 9 10	11
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
 
