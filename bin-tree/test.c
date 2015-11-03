#include <stdlib.h>
#include <stdio.h>
#include <limits.h> // LONG_MAX
#include <time.h> // rand()
#include <unistd.h> // sleep() // replace with <Gwindows.h> for windows
#include "tree.h"

int main( char** argv, int argc) {
	node* nTestP = (node*)malloc(sizeof(node));
	tree_init(&nTestP,INPUT_PERIOD/2);

	#ifdef TEST1
		// create tree and print data being inserted
		printf("--- testing for %d nodes\n", INPUT_SIZE_1);
		sleep(2);
		printf("--ins %d\n", nTestP->data);
	#endif
	
	#if defined TEST1 || defined TEST2  
	for (int i = 0, j = 0; j <= INPUT_SIZE_1; i = i++%INPUT_PERIOD, j++){
		#if defined TEST1
			printf("--ins %d\n", i);
		#endif
		tree_insert(&nTestP,i);
	}
	#endif

	#ifdef TEST2
		// visit nodes, print, get min, delete
		printf("--- printing tree:\n");
		sleep(2);
		node* n1P = (node*)malloc(sizeof(node));
		int max = LONG_MAX;
		int flag = 1;
		tree_print(nTestP, &n1P, 0, &max, &flag);

		sleep(2);
		printf("-- min data = %d\n", tree_get_min(&nTestP));
		tree_del_all(&nTestP);
		printf("-- tree deleted\n");
	#endif

	#ifdef TEST3
		// create large tree
		printf("--- testing for %d nodes\n", INPUT_SIZE_2);
		srand(time(NULL));
		tree_init(&nTestP, rand());
		int r;
		for (int i = 0; i <= INPUT_SIZE_2; i++)
			tree_insert(&nTestP, r = rand()); 
		
	#endif
	
	#if defined TEST3 && defined TEST4
		// search entire tree from TEST3
		printf("-- searching %d\n",r);	
		int i = tree_search(&nTestP, r);

		( i == 1 ) ? printf("-- %d found\n", r) : printf("-- %d not found\n", r);
	#endif

	#if defined TEST3 && defined TEST5
		// traverse tree from TEST3 w/o printing
		int flag = 0, max = LONG_MAX;
		tree_print(nTestP, &nTestP, 0, &max, &flag);
		printf("--- traversing done\n");
	#endif


	#if defined TEST6
		printf("-- reading from file and printing\n");
		sleep(2);

		node* nTestP2 = (node*)malloc(sizeof(node));
		
		FILE* f = fopen("./in/test6a.txt", "r");

		tree_finsert(f, &nTestP2);
		node* n1P = (node*)malloc(sizeof(node));
		int max6 = LONG_MAX, flag6 = 1;
		tree_print(nTestP2, &n1P, 0, &max6, &flag6);
		free(n1P);
		tree_del_all(&nTestP2);
		fclose(f);
	#endif
	
}
