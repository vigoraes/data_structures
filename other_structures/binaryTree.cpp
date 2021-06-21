#include <iostream>

using namespace std;


typedef struct _node{
	int chave, altura;
	struct _node *esq;
	struct _node *dir;

}Node;

Node * createNode(int chave){
	Node *tmp = new Node;
	tmp->chave = chave;
	tmp->altura = 0;
	tmp->esq = NULL;
	tmp->dir = NULL;

	return tmp;
}

void insert(Node **ptraiz,int chave){	
	
	if(*ptraiz == NULL){
		*ptraiz = createNode(chave);
		return;
	} 
	
	int  leftHeight = 0, rightHeight = 0;
	Node *tmp = *ptraiz;
	
	if(chave > tmp->chave){		
		if(tmp->dir == NULL) tmp->dir = createNode(chave);
		else insert(&tmp->dir, chave);
	}else if(chave < tmp->chave){	
		if(tmp->esq == NULL) tmp->esq = createNode(chave);
		else insert(&tmp->esq, chave);
	}else return;

	if(tmp->esq != NULL) leftHeight = tmp->esq->altura;

	if(tmp->dir != NULL) rightHeight = tmp->dir->altura;	
	
	tmp->altura = ((leftHeight > rightHeight)? leftHeight: rightHeight) + 1;

	*ptraiz = tmp;
}

void setHeightTree(Node *ptraiz){
	int  leftHeight = -1, rightHeight = -1;
	
	if(ptraiz->esq != NULL){
		setHeightTree(ptraiz->esq);
		leftHeight = ptraiz->esq->altura;
	} 

	if(ptraiz->dir != NULL){
		setHeightTree(ptraiz->dir);
		rightHeight = ptraiz->dir->altura;
	} 

	ptraiz->altura = ((leftHeight > rightHeight)? leftHeight: rightHeight) + 1;
}


void preOrder(Node *root){
    if(root != NULL){
        cout << "Chave: " << root->chave << " Altura: " << root->altura	<< endl;
        preOrder(root->esq);
        preOrder(root->dir);
    }
}



int main(int argc, char const *argv[]){
	Node *ptraiz = NULL;
	insert(&ptraiz, 5);
	insert(&ptraiz, 4);
	insert(&ptraiz, 3);
	insert(&ptraiz, 2);
	insert(&ptraiz, 1);
	insert(&ptraiz, 6);
	insert(&ptraiz, 7);
	insert(&ptraiz, 8);

	//setHeightTree(ptraiz);
	preOrder(ptraiz);
	return 0;
}