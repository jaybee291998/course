#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char *data;
	struct Node *next;
} Node;

typedef struct LinkedList {
	Node *head;
	Node *tail;
	unsigned int length;	
} LinkedList;

Node* add(LinkedList *list, const char *data);
Node* getElementAt(LinkedList *list, unsigned int pos);
unsigned int getLenght(LinkedList *list);
void removeAtEnd(LinkedList *list);
Node* insertAt(LinkedList *list, const char *data, unsigned int pos);
Node* removeAt(LinkedList *list, unsigned int pos);
unsigned int indexOf(LinkedList *list, const char *data);

Node* createNode(const char *data);
void freeNode(Node *node);
void printNode(Node *node);
void printList(LinkedList *list);
void printListDetail(LinkedList *list);

int main() {
	LinkedList list = {NULL, NULL, 0};
	add(&list, "head");
	add(&list, "jayvee");
	add(&list, "irene");
	add(&list, "lerma");
	removeAtEnd(&list);
	removeAtEnd(&list);
	removeAtEnd(&list);
	//removeAtEnd(&list);
	//removeAtEnd(&list);
	printList(&list);
	printListDetail(&list);
	Node *node = getElementAt(&list, 100);
	printNode(node);
	return 0;
}

Node* createNode(const char *data) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	if(!newNode) {
		printf("error allocating space for node with data: %s", data);
		return NULL;
	}
	newNode -> data = (char*) malloc(strlen(data) + 1);
	if(!newNode -> data) {	
		printf("error allocating space for data with data: %s", data);
		free(newNode);
		return NULL;
	}
	strcpy(newNode -> data, data);
	newNode -> next = NULL;
	return newNode;
}

void freeNode(Node *node) {
	if(node == NULL) return;
	if(node -> data != NULL) {
		free(node -> data);
	}
	free(node);	
}

Node* add(LinkedList *list, const char *data) {
	Node *newNode = createNode(data);	
	(list -> length)++;
	if(list -> head == NULL && list -> tail == NULL) {
		list -> head = newNode;
		list -> tail = newNode;
		return newNode;		
	}
	list -> tail -> next = newNode;
	list -> tail = newNode;
}

void printNode(Node *node) {
	if(node == NULL) return;
	printf("data: %s\n", node -> data);
	printf("-------------------------------\n");
}

void printList(LinkedList *list) {
	Node *currentNode = list -> head;
	while(currentNode != NULL) {
		printNode(currentNode);
		currentNode = currentNode -> next;
	}
}

void printListDetail(LinkedList *list) {
	if(list -> head == NULL || list -> tail == NULL) return;
	printf("head: %s\n", list->head->data);
	printf("tail: %s\n", list->tail->data);
	printf("length: %u\n", list->length);
}

Node* getElementAt(LinkedList *list, unsigned int pos) {
	Node *currentNode = list -> head;
	unsigned int currentIndex = 0;
	while(currentIndex != pos && currentNode != NULL) {
		currentNode = currentNode -> next;
		currentIndex++;
	}
	
	return currentNode;
}

unsigned int getLenght(LinkedList *list) {

}

void removeAtEnd(LinkedList *list) {
	if(list -> head == NULL || list -> tail == NULL) return;
	Node *currentNode = list -> head;
	while(currentNode -> next != NULL && currentNode -> next -> next != NULL) {
		currentNode = currentNode -> next;
	}
	(list -> length)--;
	//Node removedNode;
	//removedNode -> data = strcpy()	
	// if the currentNode -> next is null then it must the head
	if(currentNode -> next == NULL) {
		freeNode(currentNode);
		list -> tail = NULL;
		list -> head = NULL;
		return;
	}
	freeNode(currentNode -> next);
	list -> tail = currentNode;
	currentNode -> next = NULL;
	//return removedNode;
}

Node* insertAt(LinkedList *list, const char *data, unsigned int pos) {

}

Node* removeAt(LinkedList *list, unsigned int pos) {

}

unsigned int indexOf(LinkedList *list, const char *data) {

}

