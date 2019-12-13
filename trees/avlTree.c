#include<stdio.h>
#include<math.h>

struct node{
    int val;
    struct node* left;
    struct node* right;
};


struct node *newnode(int item)
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

	fflush(stdin);struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;


    return y;
}
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

int getBalance(struct node *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

int height(struct node* node){
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

struct node* rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;


    x->right = y;
    y->left = T2;

    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;


    return y;
}


struct node* avlinsert(struct node * node, int x){
    if(node==NULL){
		node = malloc(sizeof(struct node));
		node->val = x;
		node->left = node->right = NULL;
		return node;
	}

	else if(x<node->val){

		printf("smaller than curr node\n");
		node->left = insertbst(node->left,x);

	}else if(x>node->val){

		printf("larger than curr node\n");
		node->right = insertbst(node->right,x);

	}else{
        return node;
	}

    int balance = getBalance(node);

    if (balance > 1 && x < node->left->val) //left left
        return rightRotate(node);

    if (balance < -1 && x > node->right->val) //right right
        return leftRotate(node);


    if (balance > 1 && x > node->left->val){ //left right
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && x < node->right->val){ //right left
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}




void main(){
    struct node* root = malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;

    printf("root: ");
    scanf("%d",&root->val);
    int x=0;

    while(x!=-1){
        scanf("%d",&x);
        root = insert(root,x);

    }

	structure(root,0);

    abs(getBalance(root)) <= 1 ? printf("\nBalanced") : printf("\nNot Balanced");



}
