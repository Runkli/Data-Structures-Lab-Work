#include<stdio.h>

struct node{
    int val;
    struct node* left;
    struct node* right;
};

void addleaf(struct node* parent,int val){
	if(parent->left==NULL && parent->right==NULL)
		
}

void traverse(struct node* head){
	if(head==NULL){
		return;
	}
	traverse(head->left);
	printf("%d",node->val);
	
	traverse(head->right);
	
}

void main(){
    struct node* head = malloc(sizeof(struct node));
    head->left = NULL;
    head->right = NULL;
    
    
}
