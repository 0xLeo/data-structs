#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock
#include "doubly.h" // nodeP


int main() {

	#ifdef TEST1
		nodeP head, tail;
		list_init(&head, &tail);

		printf("-- creating the list:\n   20 19 .. 1 1 2 .. 10\n");
		for (int i = 0; i < SIZE_TEST1 - 10; i++)
			list_insert(&head, &tail, i+1);
		for (int i = 0; i < SIZE_TEST1 - 20; i++)
			list_append(&head, &tail, i+1);
		list_print_head(&head);
		printf("-- replace 10th node with 1337\n");
		printf("press key to continue: "); getchar();
		list_insert_at(&head, 10, 1337);
		list_print_head(&head);
		printf("-- deleting head and tail\n");
		printf("press key to continue: "); getchar();
		list_del_at(&head, &tail, 1);	// 1  -->head
		list_del_at(&head, &tail, 0);	// <1 -->tail
		list_print_head(&head);
		printf("inserting 20 at head, 10 at tail\n");
		printf("press key to continue: "); getchar();
		list_insert(&head, &tail, 20);
		list_append(&head, &tail, 10);
		list_print_head(&head);
		printf("-- deleting list and attempting to print\n\n");
		list_del(&head);
		list_print_head(&head);
		// once deleted, the list becomes unusable
	#endif
	
	#ifdef TEST2
		clock_t t_start, t_end;
		float t_elapsed;
		nodeP head2, tail2;

		list_init(&head2, &tail2);
		
		printf("-- creating a list of 40 million nodes\n");
		t_start = clock();
		for (int i = 0; i < SIZE_TEST2; i++)
			list_insert(&head2, &tail2, i);
		t_end = clock();
		t_elapsed = ((float) (t_end - t_start)) / CLOCKS_PER_SEC;
		printf("-- insertion took %.4f sec\n", t_elapsed);
		list_del(&head2);
	#endif
	
	return 0;
}
