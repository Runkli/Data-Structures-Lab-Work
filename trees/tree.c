#include<stdio.h>

struct node{
    int val;
    struct node* left;
    struct node* right;
};


struct node *newNode(int item)
{
    struct node *temp =  malloc(sizeof(struct node));
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


struct node* insertbst(struct node* head,int x){
	if(head==NULL){
		head = malloc(sizeof(struct node));
		head->val = x;
		head->left = head->right = NULL;
	}
	else if(x<head->val){

		printf("smaller than curr node\n");
		head->left = insertbst(head->left,x);

	}else if(x>head->val){

		printf("larger than curr node\n");
		head->right = insertbst(head->right,x);

	}
}

void bstiter(struct node* node){


}


void padding ( char ch, int n ){
  int i;

  for ( i = 0; i < n; i++ )
    putchar ( ch );
}

void structure ( struct node *root, int level ){
  int i;

  if ( root == NULL ) {
    padding ( '\t', level );
    puts ( "~" );
  } else {
    structure ( root->right, level + 1 );
    padding ( '\t', level );
    printf( "%d\n", root->val );
    structure ( root->left, level + 1 );
  }
}

void iterativemin(struct node* root){
	struct node* curr = root;
	while(curr->left!=NULL || curr->right!=NULL){
		if(curr->left!=NULL){

			curr = curr->left;
		}else if(curr->right!=NULL){

			curr = curr->right;
		}else{

		}
	}
	printf("min is: %d",curr->val);

}

void iterativemax(struct node* root){
	struct node* curr = root;
	while(curr->left!=NULL || curr->right!=NULL){
		if(curr->right!=NULL){
			curr = curr->right;
		}else if(curr->left!=NULL){

			curr = curr->left;
		}else{

		}
	}
	printf("max is: %d",curr->val);
}

int recursivemin(struct node* node){
	if(node->left!=NULL){
		return recursivemin(node->left);
	}
	return node->val;
}

int recursivemax(struct node* node){
	if(node->right!=NULL){
		return recursivemin(node->right);
	}
	return node->val;
}

int findelement(struct node* node,int val){
    if(val<node->val){
        findelement(node->left,val);
    }else if(val>node->val){
        findelement(node->right,val);
    }else{
        printf("found %d, memory pointer is %x\n",node->val,node);
        return node;
    }
}


void main(){
    struct node* root = malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;
    root->val = 5;

    int x;
	scanf("%d",&x);
    insertbst(root,x);
	scanf("%d",&x);
    insertbst(root,x);
	scanf("%d",&x);
    insertbst(root,x);

	structure(root,0);

    //int* add = findelement(root,3);
    //printf("\n\nelem at %x : %d",add,*add);

    recursivemin(root);
    recursivemax(root);
    iterativemax(root);
    iterativemin(root);


}
