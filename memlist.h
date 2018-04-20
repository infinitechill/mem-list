/* 
	J. Volmer // April 2018
	A linked list memory management system
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_INTS 25

// structure for a list node
struct Node
{
	void  *data;
	int size;    
	int key;
	struct Node *next;
};
typedef struct Node Node;

// function that returns a unique key 
// by finding max key and adding one
int get_new_key(struct Node* head);

// function that counts items in a list 
int count_list(struct Node* head);

// function that will properly
// free all the memory in a list
void free_list(struct Node* head);

// function that will print the ints in an allocated region of memory
void print_ints(void *my_mem, int number_ints);

// function that will print the ints in all allocated
// regions of memory in a list for demonstration purposes
void show_list(struct Node* head, int number_ints);

// function that will update a buffer with the contents of 
// memory found at a given node ids key. 
// the size parameter is included to be safe.
void get_mem(struct Node* head_ref, void ** buffer, int size, int mem_key);

// function that will delete the contents of 
// memory found at a given node ids key and update the links. 
// the size parameter is included to be safe.
void del_mem(struct Node **head_ref, int size, int mem_key);

// function that will update the contents of 
// memory found at a given node ids key. 
// the size parameter is included to be safe.
void update_mem(struct Node **head_ref, void* data, int size, int mem_key);

// function that will create a new node and add it to a list
void push_mem(struct Node** head_ref, void *new_data, int data_size);

