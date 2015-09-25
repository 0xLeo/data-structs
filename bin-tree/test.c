#include <stdlib.h>
#include <stdio.h>
#include <limits.h> // LONG_MAX
#include <time.h> // rand()
#include <unistd.h> // sleep() // replace with <windows.h> for windows
#include "tree.h"

int main() {
	node* nTestP = (node*)malloc(sizeof(node));
	tree_init(&nTestP,INPUT_PERIOD/2);

	#ifdef TEST1
		printf("--- testing for %d nodes\n", INPUT_SIZE_1);
		sleep(2);
		printf("--ins %d\n", nTestP->data);
	#endif
	
	#if defined TEST1 || defined TEST2 || defined TEST3
	for (int i = 0, j = 0; j <= INPUT_SIZE_1; i = i++%INPUT_PERIOD, j++){
		#if defined TEST1
			printf("--ins %d\n", i);
		#endif
		tree_insert(&nTestP,i);
	}
	#endif

	#ifdef TEST2
		printf("--- printing tree:\n");
		sleep(2);
		node* n1P = (node*)malloc(sizeof(node));
		int max = LONG_MAX;
		tree_print(nTestP, &n1P, 0, &max);
	#endif

	#ifdef TEST3
		sleep(2);
		printf("-- min data = %d\n", tree_get_min(&nTestP));
		tree_del_all(&nTestP);
		printf("-- tree deleted\n");
	#endif

	#ifdef TEST4
		printf("--- testing for %d nodes\n", INPUT_SIZE_2);
		srand(time(NULL));
		int r;
		for (int i = 0; i <= INPUT_SIZE_2; i++)
			tree_insert(&nTestP, r = rand());
		
		printf("-- searching %d\n",r);	
		int i = tree_search(&nTestP, r);
		( i == 1 ) ? printf("-- found\n") : printf("-- not found\n");
	#endif

}
