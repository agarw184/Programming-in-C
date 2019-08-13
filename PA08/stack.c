#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


//Puts in elements on the stack
int push(Stack* s, float val) 
{
	Node* newNode = malloc(sizeof(Node));
	if(newNode == NULL)
	{
		return EXIT_FAILURE;
	} 
	newNode->val = val;
	newNode->next = s->head;
	s->head = newNode;
	return EXIT_SUCCESS;
}

//Pops out elements of the stack
float pop(Stack* s) 
{
	if(s->head == NULL)
	{
		return EXIT_FAILURE; 
	}
	Node* toDelete = s->head;
	s->head = s->head->next;
	float retVal = toDelete->val;
	free(toDelete);
	return retVal;
}

//Points to the head of stack and prints there onwards 
void print(Stack* s) 
{
	Node* head = s->head;
	while(head != NULL) 
	{
		printf("%.2f \n", head->val);
		head = head->next;
	}
}

//Gives Height
int stackele(Stack* s) 
{
	Node* head = s->head;
	int height = 0;
	while(head != NULL)
	{
		head = head->next;
		height++;
	}
	return height;
}
