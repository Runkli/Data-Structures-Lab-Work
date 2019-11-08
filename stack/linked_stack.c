#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

struct Node
{
	int  val;
	struct Node *next;
};

struct StackRecord
{
	struct Node *head;
	struct Node *tail;
	int size;
};

typedef struct StackRecord *Stack;


Stack CreateStack()
{
	Stack l;

	l = (struct StackRecord *) malloc(sizeof(struct StackRecord));
	if (l == NULL)
		printf("Out of memory!\n");

	MakeEmptyStack(l);

	return l;
}

void MakeEmptyStack(Stack l)
{
	l->head = (struct Node *) malloc(sizeof(struct Node));
	if (l->head == NULL)
		printf("Out of memory!\n");

	l->head->next = NULL;
	l->tail = l->head;
	l->size = 0;
}

int IsEmptyStack(Stack l)
{
	return (l->size == 0);
}

int StackSize(Stack l)
{
	return (l->size);
}

int HeadOfStack(Stack l)
{
	if (!IsEmptyStack(l))
		return l->head->next->val;
	else
	{
		printf("The linked Stack is empty\n");
		return -1;
	}
}

int TailOfStack(Stack l)
{
	if (!IsEmptyStack(l))
		return l->tail->val;
	else
	{
		printf("The linked Stack is empty\n");
		return -1;
	}
}

/*
void DisplayStack(Stack l)
{
	struct Node *p;

	p = l->head->next;
	printf("Stack content:\n");

	while (p != NULL)
	{
		printf("--> %d\t", p->val);
		p = p->next;
	}
	printf("\n");
}
*/
void DisplayStack(Stack s)
{	
	struct Node *r = s->head;
	struct Node *p;
	printf("Stack content:\n");
	if (IsEmptyStack(s))
		printf("The stack is empty!\n");
	else{
		p = r->next;
		while (p != NULL)
		{
			printf("\t--> %d\n", p->val);
			p = p->next;
		}
	}
}

void PushStack(Stack l,int val){
	
    struct Node *p;
    p = l->head;
	
    while(p->next!=NULL){
		p = p->next; //gets to the end node

    }
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node)); //takes all details from user
   	
	new_node->val = val;
    new_node->next = p->next;
    p->next = new_node; //assigns it to be the next node
    (l->size)++; //increments size
}

void PopStack(Stack l){
    struct Node *p;
    p = l->head;
	struct Node *last_node = malloc(sizeof(struct Node));
    while(p->next!=NULL){
    	last_node = p;
        p = p->next;

    }
    
    printf("\nPopped -->%d\n\n",p->val);
	last_node->next = NULL;
    
	(l->size)--;
}


void DeleteStack(Stack l, int val){
    struct Node *p, *p_prev;

    p = l->head;

    while(p!=NULL && val != p->val){
        p_prev = p;
        p = p->next;
    }

    if(p!=NULL){
        p_prev->next = p->next;
        free(p);

    }
}


int GetPositionOfElement(Stack l, int pos){
    int cnt=0;
    struct Node *p;
    p = l->head;

    while( p!=NULL && cnt!=pos){
        cnt = cnt+1;
        p = p->next;

    }
    return cnt;

}

int GetElementAtPosition(Stack l, int pos){
    int cnt = -1;
    struct Node *p;
    p = l->head;

    while( p!=NULL && cnt!=pos){
        cnt = cnt+1;
        p = p->next;

    }
    return p->val;


}


int SortedInsert(Stack l, struct Node *new_node){
    int cnt=0;
    struct Node *p,*p_prev;
    p = l->head->next;
    int value = new_node->val;
    while(p!=NULL && p->val < new_node->val){
        p_prev = p;
        p = p->next;
    }
    p_prev->next = new_node;
    new_node->next = p;

    (l->size)++;
}


void InsertSort(Stack l){
    struct Node *p;

	p = l->head->next;
	printf("Stack content:\n");

	while (p!= NULL){

		SortedInsert(l, p);
		printf("here");
		p = p->next;
	}

}



int main()
{
	Stack myStack;
	int exit, val, pos,vall;
	char command;

	myStack = CreateStack();
	exit = FALSE;

	while (!exit)
	{
		fflush(stdin);
		printf("\n(i)nitialize\n");
		printf("(n)ew element\n");
		printf("(d)elete element\n");
		printf("(f)ind element\n");
		printf("(p)osition of element\n");
		printf("(h)ead of Stack\n");
		printf("(t)ail of Stack\n");
		printf("(e)xit\n");
		printf("(s)orted insert\n");
		printf("(u) InsertSort\n");
		printf("Enter command: ");
		scanf("%c", &command);
		fflush(stdin);

		switch (command)
		{
		case 'i':
			MakeEmptyStack(myStack);
			break;
		case 'n':
		    
			printf("enter value: ");
			scanf("%d", &val);
			PushStack(myStack, val);
			DisplayStack(myStack);
			break;
		case 'r':
			PopStack(myStack);
			break;
		case 'd':
			printf("enter value: ");
			scanf("%d", &val);
			DeleteStack(myStack, val);
			break;
		case 'p':
			printf("enter value: ");
			scanf("%d", &val);
			pos = GetPositionOfElement(myStack, val);
			if (pos > 0)
				printf("element %d at position %d\n", val, pos);
			break;
		case 'f':
			printf("enter position: ");
			scanf("%d", &pos);
			val = GetElementAtPosition(myStack, pos);
			if (val >= 0)
				printf("element at position %d is %d\n", pos, val);
			break;
        case 's':
                printf("enter value: ");
                scanf("%d",&vall);
                struct Node *node = (struct Node*)malloc(sizeof(struct Node));
                node->val = vall;
                SortedInsert(myStack,node);
                break;

		case 'u':
			InsertSort(myStack);
			break;

		case 'e':
			exit = TRUE;
			break;
		default:
			printf("command not recognized\n");
			break;
		}
		DisplayStack(myStack);
	}

	printf("\n");
	system("PAUSE");
	return 0;
}
