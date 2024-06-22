#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char *data;
	Node *nextNode;
}

Node* createNode(const char *str);

int main() {
	
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
