#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

struct Node
{
	int  val;
	struct Node *next;
	struct Node *prev;
};

struct ListRecord
{
	struct Node *head;
	struct Node *tail;
	int size;
};

typedef struct ListRecord *List;

List CreateList(void);
void MakeEmptyList(List);
int ListSize(List);
void InsertList(List l,int pos,int val);
int HeadOfList(List);
int TailOfList(List);
int GetPositionOfElement(List l, int val);
int GetElementAtPosition(List l, int pos);
int IsEmptyList(List);
void DisplayList(List);
void DeleteList(List l, int val);
int SortedInsert(List l, struct Node *node);
void InsertSort(List l);



List CreateList()
{
	List l;

	l = (struct ListRecord *) malloc(sizeof(struct ListRecord));
	if (l == NULL)
		printf("Out of memory!\n");

	MakeEmptyList(l);

	return l;
}

void MakeEmptyList(List l)
{
	l->head = (struct Node *) malloc(sizeof(struct Node));
	if (l->head == NULL)
		printf("Out of memory!\n");

	l->head->next = NULL;
	l->head->prev = NULL;
	l->tail = l->head;
	l->size = 0;
}

int IsEmptyList(List l)
{
	return (l->size == 0);
}



void DisplayList(List l)
{
	struct Node *p;

	p = l->head->next;
	printf("List content:\n");

	while (p != NULL)
	{
		printf("--> %d\t", p->val);
		p = p->next;
	}
	printf("\n");
}

void InsertList(List l,int pos,int val){
    int cnt=0;
    struct Node *p;
    p = l->head;

    while( p!=NULL && cnt!=pos){

        cnt = cnt+1;
        p = p->next;

    }
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->next = p->next; 
   	p->next = new_node; 
   	new_node->prev = p;
   	if(new_node->next !=NULL)
		new_node->next->prev = new_node;
	
    (l->size)++;


}

void DeleteList(List l, int val){
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


int GetPositionOfElement(List l, int pos){
    int cnt=0;
    struct Node *p;
    p = l->head;

    while( p!=NULL && cnt!=pos){
        cnt = cnt+1;
        p = p->next;

    }
    return cnt;

}

int GetElementAtPosition(List l, int pos){
    int cnt = -1;
    struct Node *p;
    p = l->head;

    while( p!=NULL && cnt!=pos){
        cnt = cnt+1;
        p = p->next;

    }
    return p->val;


}


int main()
{
	List myList;
	int exit, val, pos,vall;
	char command;

	myList = CreateList();
	
	
	MakeEmptyList(myList);
    printf("enter position: ");
	scanf("%d", &pos);
	printf("enter value: ");
	scanf("%d", &val);
	InsertList(myList, pos, val);
	DisplayList(myList);
		

	printf("\n");
	system("PAUSE");
	return 0;
}
