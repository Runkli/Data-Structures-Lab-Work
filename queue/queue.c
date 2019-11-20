#include <stdio.h>

struct Node{
	int val;
	struct Node* next;
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

void enq(struct Queue* q, int k) { 
	struct Node* temp = malloc(sizeof(struct Node)); 
    temp->val = k;
    temp->next = NULL; 
     
    if (q->rear == NULL) { 
        q->front = q->rear = temp; 
        return; 
    } 
  
    q->rear->next = temp; 
    q->rear = temp; 
    
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


void main(){
	struct Queue* qHead;
	qHead = createQueue();
	
	enq(qHead,2);
	enq(qHead,3);
	deq(qHead);
	deq(qHead);
	
}
