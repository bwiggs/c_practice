#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int value;
	struct NODE* next;
} NODE;

int main()
{
	NODE *head, *tmp, *prev;
	tmp = prev = head = NULL;
	int input;
	int isInserted;
	
	while(1) {

		// get user input
		printf("Enter an integer value to store.\n");		
		scanf("%d", &input);

		tmp = prev = head;
		isInserted = 0;
		while(! isInserted) {
			
			// first node
			if(!head) {
				tmp = (NODE*) malloc(sizeof(NODE));
				tmp->value = input;
				head = tmp;
				isInserted = 1;
			
			// the value already exists
			} else if(input == tmp->value) { 
				if(tmp == head) {
					printf("removing head element");
					tmp = head;
					head = head->next;
					prev->next = head;
					free(tmp);
				} else {
					printf("removing element");
					prev->next = tmp->next;
					free(tmp);
				}

			// the value is smaller than the current node
			} else if(input < tmp->value) { 
				
				// the value is smaller than head
				if(tmp == head) { 
					tmp = (NODE*) malloc(sizeof(NODE));
					tmp->value = input;
					tmp->next = head;
					head = tmp;
					isInserted = 1;
					
				// value is smaller than any other node
				} else { 
					tmp = (NODE*) malloc(sizeof(NODE));
					tmp->value = input;
					tmp->next = prev->next;
					prev->next = tmp;
					isInserted = 1;
				}
				
			// value is larger than the current node
			} else { 
				
				// im at the last item in the list
				if(tmp->next == NULL) { 
					tmp->next = (NODE*) malloc(sizeof(NODE));
					tmp->next->value = input;
					isInserted = 1;		
				}
			}
			
			prev = tmp;
			tmp = tmp->next;
			
		}
	
		// print out the list
		printf("Current List: [");
		tmp = head;
		do {
			printf("%d,", tmp->value);
		} while(tmp = tmp->next);
		printf("]\n\n");
		
	}
	

	return 0;
}