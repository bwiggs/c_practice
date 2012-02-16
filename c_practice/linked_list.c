#include <stdio.h>
#include <stdlib.h>

// data types
typedef struct NODE {
	int value;
	struct NODE* next;
} NODE;

// prototypes
void insertValue(int);
NODE* allocateNode();

// variables
NODE *head, *tmp, *prev;
int input;
int isInserted;

int main2()
{
	tmp = prev = head = NULL;
	
	while(1) {

		// get user input
		printf("Enter an integer value to store.\n");		
		scanf("%d", &input);

		insertValue(input);
			
		// print out the list
		printf("Current List: [");
		tmp = head;
		do {
			if(tmp)	printf("%d,", tmp->value);
		} while((tmp = tmp->next));
		printf("]\n\n");
		
	}
	

	return 0;
}

NODE* allocateNode() {
	return malloc(sizeof(NODE));
}

void insertValue(int value) {
	tmp = prev = head;
	isInserted = 0;
	
	while(! isInserted) {
		
		// first node
		if(! head) {
			tmp = allocateNode();
			tmp->value = input;
			head = tmp;
			isInserted = 1;
			
		// the value already exists
		} else if(input == tmp->value) { 
			
			// the first item needs to be removed
			if(tmp == head) {
				if(head->next == NULL) {
					head = NULL;	
				} else {
					head = head->next;
				}
				
			// need to remove any other item
			} else {
				prev->next = tmp->next;
			}
			
			free(tmp);
			isInserted = 1;
			
			// the value is smaller than the current node
		} else if(input < tmp->value) { 
			
			// the value is smaller than head
			if(tmp == head) { 
				tmp = allocateNode();
				tmp->value = input;
				tmp->next = head;
				head = tmp;
				isInserted = 1;
				
				// value is smaller than any other node
			} else { 
				tmp = allocateNode();
				tmp->value = input;
				tmp->next = prev->next;
				prev->next = tmp;
				isInserted = 1;
			}
			
			// value is larger than the current node
		} else { 
			
			// im at the last item in the list
			if(tmp->next == NULL) { 
				tmp->next = allocateNode();
				tmp->next->value = input;
				isInserted = 1;		
			}
		}
		
		prev = tmp;
		tmp = tmp->next;
		
	}
}