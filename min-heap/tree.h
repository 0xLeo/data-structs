#ifndef TREE_H
#define TREE_H

typedef struct snode {
    int _data;
    struct snode* _left;
    struct snode* _right;
    struct snode* _parent;
} node;
 
void tree_swap(node* nP1, node* nP2);
void tree_insert(node* nP,int val);
node* tree_glp (node* nP, node** newP, long int ctr,  int* max);

#endif
