#include <iostream>

using namespace std;

//uma lista encadeada circular com nó raíz

typedef struct _node{
	int data;
	struct _node *next;
	struct _node *prev;
}Node;

void createNode(Node *head, int x){
	
}

Node * search(Node *head, int x){
	if (head == NULL) return NULL;
	else if(head->next == head) return NULL;
	
	Node *tmp = head;
	
	do{
		tmp = tmp->next;
	}while(tmp->data < x && tmp->data != (int)NULL);
	
	if(tmp->data == x) return tmp;
	return NULL;		
}

void remove(Node *head, int x){
	if (head != NULL && head->next != head){
		Node *node = search(head, x);
		
		if(node == NULL) return;
		
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete node;
	} 						
}


int main(int argc, char const *argv[]){
	
	Node *head = new Node;
	Node *node1 = new Node;
	Node *node2 = new Node;
	
	head->data = (int)NULL;
	node1->data = 2;
	node2->data = 3;

	head->next = node1;
	head->prev = node2;
	
	node1->next = node2;
	node1->prev = head;
	
	node2->next = head;
	node2->prev = node1;

	cout << search(head, 2) << endl;
	remove(head, 2);
	cout << search(head, 2) << endl;
	return 0;
}