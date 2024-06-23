#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char *data;
	struct Node *nextNode;
};

Node* createNode(const char *str);
Node* insertAtBeginning(Node *head, const char *str);
void printList(Node *head);

int main() {
	char *data1 = "jayvee";
	char *data2 = "irene";

	Node *linkedList = createNode(data1);
	linkedList = insertAtBeginning(linkedList, createNode(data2));

	char *d1 = linkedList-> data;

	printf("data1: %s\n", d1);
}

void printList(Node *head) {
	Node *currentNode = head;
	//while(currentNode)
}

Node* insertAtBeginning(Node *head, const char *str) {
	Node *newNode = createNode(str);
	if(!newNode) {
		return NULL;
	}
	newNode -> nextNode = head;
	return newNode;
}

Node* createNode(const char *str) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	if(!newNode) {
		printf("error allocating memory for new node");
		return NULL;
	}

	newNode -> data = (char*) malloc(strlen(str) + 1);
	if(!newNode -> data) {
		printf("error allocating memory for string data");
		free(newNode);
		return NULL;
	}
	strcpy(newnode -> data, str);
	newNode -> nextNode = NULL;
	return newNode;
}
