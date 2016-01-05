#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock
#include "doubly.h" // NodeP


int main() {

	#ifdef TEST1
		NodeP head, tail;
		list_init(&head, &tail);

		printf("--- test1\n-- creating the list:\n   20 19 .. 1 1 2 .. 10\n");
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
		printf("-- inserting 20 at head, 10 at tail\n");
		printf("press key to continue: "); getchar();
		list_insert(&head, &tail, 20);
		list_append(&head, &tail, 10);
		list_print_head(&head);
		printf("-- reversing head to tail list\n");	
		list_rev(&head);
		list_print_head(&head);
		//list_print_head(&head);
		//printf("%d\n", head->next->data);
		printf("-- deleting list and attempting to print\n\n");
		list_del(&head);
		list_print_head(&head);
		// once deleted, the list becomes unusable
	#endif
	
	#ifdef TEST2
		printf("--- test2\n");
		NodeP head2, tail2;
		list_init(&head2, &tail2);
		for (int i = 0; i < SIZE_TEST2; i++)
			list_insert(&head2, &tail2, i);
	#endif

	#if defined TEST2 && defined TEST3
		// traverse and insert at end
		printf("--- test3\n");
		int toInsert = 0;
		// essentially traveral beginning to end
		list_insert_at(&head2, SIZE_TEST2 - 1, toInsert);	
		printf("-- inserted %d, traversed to %d\n", toInsert, tail2->data);
	#endif

	return 0;
}
