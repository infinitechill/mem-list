/* 
	J. Volmer // April 2018
	A basic program demonstrating a linked list 
	memory management system
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memlist.h"

#define NUM_INTS 25

Node *HEAD_OF_LIST = NULL;

int main()
{
	printf("A program demonstrating a linked list for memory management\n");
	// set up variables
	int i,mem_size;

	// allocate memory
	mem_size = NUM_INTS*sizeof(int);
	void *my_buffer = malloc( mem_size );
	void *my_buffer2 = malloc( mem_size );
	int (*my_arr)[NUM_INTS] = (int (*)[NUM_INTS]) my_buffer;  // same memory

	// fill up buffer and add to list
	for (i = 0; i < NUM_INTS; i++)
		(*my_arr)[i]=1;
	push_mem(&HEAD_OF_LIST, my_arr, mem_size); // node id 1
	
	// fill up buffer and add to list
	for (i = 0; i < NUM_INTS; i++)
		(*my_arr)[i]=2;
	push_mem(&HEAD_OF_LIST, my_arr, mem_size); // node id 2
	
	// fill up buffer and add to list
	for (i = 0; i < NUM_INTS; i++)
		(*my_arr)[i]=3;
	push_mem(&HEAD_OF_LIST, my_arr, mem_size); // node id 3 this is the one we will retrieve.
	
	// fill up buffer and add to list
	for (i = 0; i < NUM_INTS; i++)
		(*my_arr)[i]=4;
	push_mem(&HEAD_OF_LIST, my_arr, mem_size); // node id 4
	
	// fill up buffer and add to list
	for (i = 0; i < NUM_INTS; i++)
		(*my_arr)[i]=5;
	push_mem(&HEAD_OF_LIST, my_arr, mem_size); // node id 5
	
	// fill up buffer and add to list
	for (i = 0; i < NUM_INTS; i++)
		(*my_arr)[i]=6;
	push_mem(&HEAD_OF_LIST, my_arr, mem_size); // node id 6

	// retrieve chunk of memory from node id 3
	get_mem(HEAD_OF_LIST, &my_buffer2, mem_size, 4);

	// make sure the get worked.
	print_ints(my_buffer2, NUM_INTS);

	// delete a chunk of memory and remove node from list
	del_mem(&HEAD_OF_LIST, mem_size, 4);

	// update a chunk of memory by list id
	update_mem(&HEAD_OF_LIST, my_buffer2, mem_size, 3);

	// add another one
	for (i = 0; i < NUM_INTS; i++)
		(*my_arr)[i]=7;
	push_mem(&HEAD_OF_LIST, my_arr, mem_size); // node id 7

	// show all the allocated chunks of memory
	show_list(HEAD_OF_LIST,NUM_INTS);
	
	// clean up stuff
	free_list(HEAD_OF_LIST);
	free(my_buffer);
	free(my_buffer2);

	return 0;
}
