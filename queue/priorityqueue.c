#include <stdio.h>

struct Node{
	int val;
	struct Node* next;
	int priority;
};

struct Queue{
	struct Node* front;
	struct Node* rear;
	int size;	
};


struct Queue* createQueue() 
{ 
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
	q->rear = q->front; 
    return q; 
} 

struct Node* newNode(){
	int k, priority;
	printf("Enter value, priority: ");
	scanf("%d %d",&k,&priority);
	
	struct Node* temp = malloc(sizeof(struct Node));
	temp->val = k;
	temp->next = NULL;
	temp->priority = priority;
	
	return temp;
}


void enq(struct Queue* q) { 

	struct Node* holder;
	struct Node* temp = newNode();
	struct Node* p = q->front;
	
	int count = 0;
	if(q->front == NULL){
		q->front = temp;
		q->rear = q->front;
		return;
	}else{
		printf("Not empty\n");
	}
	
    
    while(p->next!=NULL && temp->priority < p->next->priority){
    	p = p->next;
	}
	
	holder = p->next;
	temp->next = holder;
	p->next = temp;
    return;
    
  	p = temp;
  	q->front = p;
  	q->rear = q->front;
    
} 

struct QNode* deq(struct Queue* q){
   	
 	printf("Dequeued: %d\n",q->front->val);  	
    struct QNode* temp = q->front;
    free(temp);
  	
    q->front = q->front->next;
  	
    if (q->front == NULL) 
        q->rear = NULL; 
    return temp;
} 

void displayQueue(struct Queue* q){
	struct Node *p;

	p = q->front;
	printf("List content:\n");

	while (p != NULL)
	{
		printf("--> %d\t", p->val);
		p = p->next;
	}
	printf("\n");
}


void main(){
	struct Queue* qHead;
	qHead = createQueue();
	
	enq(qHead);
	enq(qHead);
	enq(qHead);
	enq(qHead);
	
	displayQueue(qHead);
	/*deq(qHead);
	deq(qHead);
	deq(qHead);
	deq(qHead);*/
}
