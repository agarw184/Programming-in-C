#ifndef STACK
#define STACK

typedef struct Node {
	float val;
	struct Node* next;
}Node;

typedef struct {
	Node* head;
}Stack;

int push(Stack* s, float val);
float pop(Stack* s);
void print(Stack* s);
int stackele(Stack* s);
#endif
