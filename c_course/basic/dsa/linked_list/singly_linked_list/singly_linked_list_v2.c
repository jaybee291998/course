#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char *data;
	struct Node *next;
} Node;

typedef struct LinkedList {
	Node *head;
	Node *tail;
	unsigned int length;	
} LinkedList;

Node* createNode(const char *data);
Node* add(LinkedList *list, const char *data);
Node* getElementAt(LinkedList *list, unsigned int pos);
unsigned int getLenght(LinkedList *list);
Node* removeAtEnd(LinkedList *list);
Node* insertAt(LinkedList *list, const char *data, unsigned int pos);
Node* removeAt(LinkedList *list, unsigned int pos);
unsigned int indexOf(LinkedList *list, const char *data);

int main() {
	return 0;
}

Node* createNode(const char *data) {
	Node *newNode = (Node*) malloc(sizeof(Node));
}

Node* add(LinkedList *list, const char *data) {

}

Node* getElementAt(LinkedList *list, unsigned int pos) {

}

unsigned int getLenght(LinkedList *list) {

}

Node* removeAtEnd(LinkedList *list) {

}

Node* insertAt(LinkedList *list, const char *data, unsigned int pos) {

}

Node* removeAt(LinkedList *list, unsigned int pos) {

}

unsigned int indexOf(LinkedList *list, const char *data) {

}

