#include <iostream>

using namespace std;

typedef struct _node{
	int data;
	int color;
	struct _node *left;
	struct _node *right;
}Node;

Node * createNode(int chave){
	Node *tmp = new Node;
	tmp->data = chave;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}

int getColor(Node *node){
	if(node == NULL) return 0;
	else node->color;
}

void changeColor(Node *node){
	node->color = !node->color;
	if(node->left != NULL) node->left->color = !node->left->color;
	if(node->right != NULL) node->right->color = !node->right->color;
}

void leftRotation(Node **node){
	Node *dad = *node;
	sonRight = dad->right;
	dad->right = sonRight->left;
	sonRight->left = dad;
	sonRight->color = dad->color;
	dad->color = 1;
	*node = *sonRight;
}

void rightRotation(Node **node){
	Node *dad = *node;
	sonleft = dad->left;
	dad->left = sonleft->right;
	sonleft->right = dad;
	sonleft->color = dad->color;
	dad->color = 1;
	*node = *sonleft;
}


int main(int argc, char const *argv[]){
	
	return 0;
}