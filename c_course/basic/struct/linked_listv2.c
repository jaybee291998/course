#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char *data;
	struct Node *nextNode;
} Node;

typedef struct LinkedList {
	Node *head;
	size_t len;
	Node *tail;
} LinkedList;

Node* createNode(const char *data);
void printNode(Node *node);
void traverseList(LinkedList *list);
Node* insertInBeginning(LinkedList *linkedList, const char *data);
void printListDetail(LinkedList *list);
Node* insertAtEnd(LinkedList *list, const char *data);

int main() {
	Node *head;
	//insertInBeginning(head, "jayvee");
	Node *newNode = createNode("originalHead");
	Node *tail = createNode("tail0");
	//newNode -> nextNode = tail;
	//newNode -> nextNode = createNode("tail0");
	LinkedList list = {newNode, 2, tail};
	insertAtEnd(&list, "tail1");
	insertAtEnd(&list, "tail2");
	insertInBeginning(&list, "head");
	//Node *node2 = createNode("irene");
	//newNode->nextNode = node2;
	//traverseList(newNode);
	//printNode(newNode);
//	Node *node2 = insertInBeginning(head, "irene");
//	insertInBeginning(head, "irene");
//	insertInBeginning(head, "irene");
//	insertInBeginning(head, "irene");
//	insertInBeginning(head, "irene");
//	insertInBeginning(head, "irene");
//	insertInBeginning(head, "irene");
	for(int i = 0; i < 10; i++) {		
		//insertInBeginning(&list, "irene");
	}
	//insertInBeginning(&list, "head");
	traverseList(&list);
	printListDetail(&list);
	//printNode(node2);
	//traverseList(node2);
	return 0;
}


Node* createNode(const char *data) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	if(!newNode) {
		printf("error in allocating space for new node with data %s\n", data);
		return NULL;
	}

	newNode -> data = (char *) malloc(strlen(data) + 1);

	if(!newNode -> data) {
		printf("error in alloating space for data with data %s\n", data);
		free(newNode);
	       return NULL;	
	}

	strcpy(newNode -> data, data);
	newNode -> nextNode = NULL;

	return newNode;
}

Node* insertInBeginning(LinkedList *linkedList, const char *data) {
	Node *newNode = createNode(data);
	if(!newNode) {
		return (linkedList -> head);
	}
	(linkedList -> len)++; 
	newNode->nextNode = (linkedList -> head);
	(linkedList -> head) = newNode;
	return newNode;  
}

void printNode(Node *node ) {
	printf("data: %s\n", node->data);
	printf("nextNodeAddr: %p\n", (void *) node->nextNode);
}


void traverseList(LinkedList *list) {
	Node *currentNode = (list -> head);
	while(currentNode != NULL) {
		printNode(currentNode);
		printf("--------------------------\n");
		currentNode = currentNode->nextNode;
	}
}


void printListDetail(LinkedList *list) {
	printf("head: %s\n", ((list -> head))->data);
	printf("tail: %s\n", ((list -> tail))->data);
	printf("head: %zu\n", list -> len);
}

Node* insertAtEnd(LinkedList *list, const char *data) {
	Node *newNode = createNode(data);
	if(!newNode) {
		return list -> tail;
	}
	(list -> len)++;
	list -> tail -> nextNode = newNode;
	list -> tail = newNode;
	//newNode -> nextNode = list -> tail;
	//list -> tail = newNode;
	return newNode;
}
