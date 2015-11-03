#ifndef TREE_H
#define TREE_H

#define INPUT_SIZE_1 200
#define INPUT_PERIOD 20
#define INPUT_SIZE_2 1000000
#ifndef OP
	#define OP <	// < for smaller than root at end, else >
#else
	#define OP >
#endif

typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;
    struct _node* parent;
} node;


void tree_init(node** nP, int val);
void tree_insert(node** nP, int val);
int tree_get_min(node** rootP);
int tree_get_max(node** rootP);
int tree_search(node** nP, int val) ;
void tree_del_all(node** nP);
void tree_print(node* nP, node** newP, long int ctr, int* max, const int* printFlag);
int tree_finsert (FILE* f, node** nP);

#endif
