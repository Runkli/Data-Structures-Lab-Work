#include<stdio.h>

struct Node{
	int val;
	int priority;
	struct Node* next;
};

struct Queue{
	struct Node* front;
	struct Node* rear;
	int size;
};

void enq(struct Queue* q){
	
	struct Node* temp = malloc(sizeof(struct Node));
	printf("Enter value and priority: ");
	scanf("%d %d",&temp->val,&temp->priority);
	temp->next = NULL;
	if(q->front == NULL && q->rear == NULL){
		q->front = q->rear = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
}

void sortedenq(struct Queue* q){
	struct Node* curr;
	struct Node* new_node = malloc(sizeof(struct Node));
	printf("Enter value and priority: ");
	scanf("%d %d",&new_node->val, &new_node->priority);
	
	if(q->front == NULL || q->front->priority >= new_node->priority){
		new_node->next = q->front;
		q->front = new_node;
		return;
	}
	curr = q->front;
	while(curr->next!=NULL && curr->next->priority < new_node->priority){
		curr = curr->next;
	}
	
	new_node->next = curr->next;
	curr->next = new_node;
	
	
}

void deq(struct Queue* q){
	struct Node* temp = q->front;
	if(q->front==NULL) return;
	printf("Dequeued item is: %d\n",q->front->val);
	if(q->front==q->rear){
		q->front = q->rear = NULL;
	}else{
		q->front = q->front->next;
	}
	free(temp);
	
}

void display(struct Queue* q){
	struct Node* head = malloc(sizeof(struct Node));
	head = q->front;
	while(head!=NULL){
		printf("val is %d\n",head->val);
		head = head->next;
	}
	
}

void main(){
	struct Queue* q = malloc(sizeof(struct Queue));
	q->front = malloc(sizeof(struct Node));
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	
	enq(q);
	sortedenq(q);
	sortedenq(q);
	sortedenq(q);
	display(q);
	deq(q);
	deq(q);
	deq(q);
}
