#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char *data;
	struct Node *nextNode;
} Node;

Node* createNode(const char *data);
void printNode(Node *node);
void traverseList(Node *node);
Node* insertInBeginning(Node **head, const char *data);

int main() {
	Node **head;
	Node *newNode = createNode("jayvee");
	head = &newNode;
	//Node *node2 = createNode("irene");
	//newNode->nextNode = node2;
	//traverseList(newNode);
	//printNode(newNode);
	//Node *node2 = insertInBeginning(head, "irene");
	traverseList(*head);
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

Node* insertInBeginning(Node **head, const char *data) {
	Node *newNode = createNode(data);
	if(!newNode) {
		return *head;
	}

	newNode->nextNode = *head;
	*head = &newNode;
	return newNode;  
}

void printNode(Node *node ) {
	printf("data: %s\n", node->data);
	printf("nextNodeAddr: %p\n", (void *) node->nextNode);
}


void traverseList(Node *node) {
	Node *currentNode = node;
	while(currentNode != NULL) {
		printNode(currentNode);
		printf("--------------------------\n");
		currentNode = currentNode->nextNode;
	}
}
