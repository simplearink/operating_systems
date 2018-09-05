#include <stdio.h>

struct Node
	{
		int data;
		struct Node *next;
	};

void print_list(struct Node * list) {
	while (list != NULL) {
		printf("%d\n", list->data);
		list = list -> next;
	}
}

void insert_node(struct Node * list, struct Node *new) {
		while (list -> next != NULL) {
			list = list -> next;
		}
		list -> next = new;
	}

void delete_node(struct Node * list, struct Node *del) {
	while (list->next != del) {
		list = list -> next;
	}
	list->next = del->next;
}

int main(){
	struct Node node4 = {.data = 5, .next = (struct Node *) NULL};

	struct Node node3 = {.data = 3, .next = (struct Node *) NULL};
	struct Node node2 = {.data = 2, .next = &node3};
	struct Node node1 = {.data = 1, .next = &node2};

	struct Node head;
	head.data = 120;
	head.next = &node1;

	insert_node(&head, &node4);

	delete_node(&head, &node1);


	print_list(&head);


	 
	return 0;
	}