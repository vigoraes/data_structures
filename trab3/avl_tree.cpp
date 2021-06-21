#include <iostream>

using namespace std;

typedef struct _node{
	int data;
	int height;
	struct _node *left;
	struct _node *right;
}Node;

int getHeight(Node *node){
	if(node == NULL) return 0;
	return node->height;
}

Node * createNode(int data){
	Node *node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

void leftRotation(Node **node){
	Node *x = *node;
	Node *y = x->right;
	Node *left = y->left;

	y->left = x;
	x->right = left;

	x->height = ((getHeight(x->left) > getHeight(x->right)? getHeight(x->left): getHeight(x->right)) + 1);
	y->height = ( (getHeight(y->left) > getHeight(y->right)? getHeight(y->left): getHeight(y->right)) + 1);

	*node = y;
}

void rightRotation(Node **node){
    Node *y = *node;
    Node *x = y->left;
    Node *right = x->right;
    
    x->right = y;
    y->left = right;
 
	y->height = ((getHeight(y->left) > getHeight(y->right)? getHeight(y->left): getHeight(y->right)) + 1);
	x->height = ((getHeight(x->left) > getHeight(x->right)? getHeight(x->left): getHeight(x->right)) + 1);
    
    *node = x;
}

int getBalance(Node *node){
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

void insert(Node** node, int data){
    if (*node == NULL){
    	*node = createNode(data);
    	return;
    } 

    Node *tmp = *node;
 
    if (data < tmp->data) insert(&tmp->left, data);
    else if (data > tmp->data) insert(&tmp->right, data);
    else return;
 
    tmp->height = ((getHeight(tmp->left) > getHeight(tmp->right))? getHeight(tmp->left): getHeight(tmp->right)) + 1;

    int balance = getBalance(tmp);

    if (balance > 1){
        if(data < tmp->left->data) rightRotation(&tmp);
        else if(data > tmp->left->data){
        	leftRotation(&tmp->left);
        rightRotation(&tmp);
        }
    }

    if (balance < -1){
        if(data > tmp->right->data) leftRotation(&tmp);
        else if(data < tmp->right->data){
        	rightRotation(&tmp->right);
      	 	leftRotation(&tmp);
        }
    }
    *node = tmp;
}

void printTree(Node *node){
    if(node != NULL){
        cout << node->data << endl;
        printTree(node->left);
        printTree(node->right);
    }
}

int main(int argc, char const *argv[]){
	Node *root = NULL;
	int data;
	while(cin >> data){
		insert(&root, data);
	}
    
    printTree(root);
	return 0;
}