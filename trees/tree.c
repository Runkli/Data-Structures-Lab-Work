#include<stdio.h>

struct node{
    int val;
    struct node* left;
    struct node* right;
};


struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->val = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

void addleaf(struct node* parent){
	
	char path;
	
	printf("Value at node: %d\n",parent->val);
	if(parent->left==NULL && parent->right==NULL){
		printf("Add value to left and right branch: ");
		parent->left = malloc(sizeof(struct node));
		parent->right = malloc(sizeof(struct node));
		parent->left->left = NULL;
		parent->left->right = NULL;
		parent->right->left = NULL;
		parent->right->right = NULL;
		
		scanf("%d %d",&parent->left->val, &parent->right->val);
        return;
	}
	
	fflush(stdin);
	printf("Traverse left or right: ");
	scanf("%c",&path);
	if(path=='r'){
		addleaf(parent->right);
		
	}
	else if(path=='l'){
		addleaf(parent->left);
		
	}

}

void traverse(struct node* head){
	if(head==NULL){
		return;
	}
	printf("%d\n",head->val);
	if(head->left!=NULL){
		traverse(head->left);
	}
	if(head->right!=NULL){
		traverse(head->right);
	}

}


void insertbst(struct node* head,int x){
	
	
	if(x<head->val){
		if(head->left!=NULL){
			insertbst(head->left,x);
		}
		printf("smaller than curr node\n");
		head->left = malloc(sizeof(struct node));
		head->left->val = x;
		head->left->left = NULL;
		head->left->right = NULL;
		
	}else if(x>head->val){
		if(head->right!=NULL){
			insertbst(head->right,x);
		}
		printf("larger than curr node\n");
		head->right = malloc(sizeof(struct node));
		head->right->val = x;
		head->right->left = NULL;
		head->right->right = NULL;
		
	}
	
	
}


void main(){
    struct node* head = malloc(sizeof(struct node));
    head->left = NULL;
    head->right = NULL;
    head->val = 8;
    
    int x;
    printf("Enter value: ");
    scanf("%d",&x);
    insertbst(head,x);
    traverse(head);
    
    printf("Enter value: ");
    scanf("%d",&x);
    insertbst(head,x);
    traverse(head);
    
    printf("Enter value: ");
    scanf("%d",&x);
    insertbst(head,x);
    traverse(head);
    
    printf("Enter value: ");
    scanf("%d",&x);
    insertbst(head,x);
    traverse(head);
    
    printf("Enter value: ");
    scanf("%d",&x);
    insertbst(head,x);
    traverse(head);
	
}
