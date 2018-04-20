/* 
	J. Volmer // April 2018
	A linked list memory management system
*/


#include "memlist.h"

// function that returns a unique key 
// by finding max key and adding one
int get_new_key(struct Node* head)
{
	int max = 0;
	struct Node* current = head;
	while (current != NULL)
	{
		if ( current->key > max ) 
		{
			max = current->key;
		}
		current = current->next;
	}
	return max+1;
}

// function that counts items in a list 
int count_list(struct Node* head)
{
	int count = 0;
	struct Node* current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

// function that will properly
// free all the memory in a list
void free_list(struct Node* head)
{
	struct Node* curr = head;
	struct Node* temp = NULL;    
	while(curr != NULL)
	{
	   temp = curr;
	   curr = curr->next;
	   free(temp->data);
	   free(temp);
	}
}

// function that will print the ints in an allocated region of memory
void print_ints(void *my_mem, int number_ints)
{
	int (*my_arr)[number_ints] = (int (*)[number_ints]) my_mem;
	int i;
	printf("\n");
	for (i = 0; i < NUM_INTS; i++)
		printf("%d: %d \t",i,(*my_arr)[i]);
	printf("\n");

}

// function that will print the ints in all allocated
// regions of memory in a list for demonstration purposes
void show_list(struct Node* head, int number_ints)
{
	struct Node* curr = head;
	struct Node* temp = NULL;    
	while(curr != NULL)
	{
	   temp = curr;
	   curr = curr->next;
	   printf("\n%d:%d",temp->key,temp->size);
	   print_ints(temp->data, number_ints);
	}
}


// function that will update a buffer with the contents of 
// memory found at a given node ids key. 
// the size parameter is included to be safe.
void get_mem(struct Node* head_ref, void ** buffer, int size, int mem_key)
{
	struct Node* curr = head_ref;
	struct Node* temp = NULL; 
	int curr_count=0;
	while(curr != NULL)
	{
	   temp = curr;
	   curr = curr->next;
	   if (temp->key == mem_key && temp->size == size) 
	   {
			memcpy(*buffer,temp->data,temp->size);
			break;
	   }
	}
}

// function that will delete the contents of 
// memory found at a given node ids key and update the links. 
// the size parameter is included to be safe.
void del_mem(struct Node **head_ref, int size, int mem_key)
{
    struct Node* temp = *head_ref, *prev;
    while (temp != NULL && temp->key == mem_key && temp->size == size)
    {
        *head_ref = temp->next;
        free(temp->data);
        free(temp);
        temp = *head_ref;
    }
    while (temp != NULL)
    {
        while (temp != NULL && temp->key != mem_key)
        {
			prev = temp;
			temp = temp->next;
        }
        if (temp == NULL || temp->size != size) return;
		
		prev->next = temp->next;
 		free(temp->data);
        free(temp);
		temp = prev->next;
    }
}

// function that will update the contents of 
// memory found at a given node ids key. 
// the size parameter is included to be safe.
void update_mem(struct Node **head_ref, void* data, int size, int mem_key)
{
    struct Node* temp = *head_ref, *prev;
    while (temp != NULL && temp->key == mem_key)
    {
        *head_ref = temp->next;
        if (temp->size == size && temp->key == mem_key)
        {
        	memcpy(temp->data,data,size);
        	return;
        }
    }
    while (temp != NULL)
    {
        while (temp != NULL && temp->key != mem_key)
        {
			prev = temp;
			temp = temp->next;
        }
        if (temp == NULL) return;
        if (temp->size == size && temp->key == mem_key)
        {
        	memcpy(temp->data,data,size);
        	return;
        }
    }
}

// function that will create a new node and add it to a list
void push_mem(struct Node** head_ref, void *new_data, int data_size)
{
	int i;
	// allocate memory and update values
	Node* new_node = (Node*)malloc(sizeof(struct Node));
	new_node->data  = malloc(data_size);
	new_node->size = data_size;
	new_node->key = get_new_key(*head_ref);
	memcpy(new_node->data, new_data, data_size);
	// update links
	new_node->next = (*head_ref);
	(*head_ref)    = new_node;
}
