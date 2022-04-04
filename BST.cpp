#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

struct node{
  	float key;
  	struct node *left,*right;
};

struct node *newNode(float item) {
  	struct node *temp=new node();
  	temp->key=item;
  	temp->left=temp->right=NULL;
  	return temp;
}

void inorder(struct node *root){
  	if(root!=NULL){
    	inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
  	}
}

struct node *insert(struct node *node,float key){
  	if(node==NULL) return newNode(key);
	if(key<node->key) node->left=insert(node->left,key);
  	else node->right=insert(node->right,key);
  	return node;
}

bool evaluteNumber(char text[]){
	for(int i=0;i<strlen(text);i++) if(!isdigit(text[i]) && text[i]!='.') return false;
	return true;
}

void leerTXT(node *&tree){
	char text[100];
	float numero;
	
	FILE *file=fopen("documento.txt","r");
	if(file==NULL) cout<<"No se encontro el txt"<<endl;
	else{
		while(feof(file)==0){
			fscanf(file,"%s",&text);
			if(evaluteNumber(text)){
				tree=insert(tree,atof(text));
			}
		}
	}
	fclose(file);
}

int main() {
  	struct node *tree = NULL;
  	
  	leerTXT(tree);
  	inorder(tree);
	
	return 0;
}
