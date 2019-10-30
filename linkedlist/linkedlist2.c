#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

struct Node
{
	int  val;
	struct Node *next;
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



int main()
{
	List myList;
	int exit, val, pos,vall;
	char command;

	myList = CreateList();
	exit = FALSE;

	while (!exit)
	{
		fflush(stdin);
		printf("\n(i)nitialize\n");
		printf("(n)ew element\n");
		printf("(d)elete element\n");
		printf("(f)ind element\n");
		printf("(p)osition of element\n");
		printf("(h)ead of list\n");
		printf("(t)ail of list\n");
		printf("(e)xit\n");
		printf("(s)orted insert\n");
		printf("(u) InsertSort\n");
		printf("Enter command: ");
		scanf("%c", &command);
		fflush(stdin);

		switch (command)
		{
		case 'i':
			MakeEmptyList(myList);
			break;
		case 'n':
		    printf("enter position: ");
			scanf("%d", &pos);
			printf("enter value: ");
			scanf("%d", &val);
			InsertList(myList, pos, val);
			DisplayList(myList);
			break;
		case 'd':
			printf("enter value: ");
			scanf("%d", &val);
			DeleteList(myList, val);
			break;
		case 'p':
			printf("enter value: ");
			scanf("%d", &val);
			pos = GetPositionOfElement(myList, val);
			if (pos > 0)
				printf("element %d at position %d\n", val, pos);
			break;
		case 'f':
			printf("enter position: ");
			scanf("%d", &pos);
			val = GetElementAtPosition(myList, pos);
			if (val >= 0)
				printf("element at position %d is %d\n", pos, val);
			break;
        case 's':
                printf("enter value: ");
                scanf("%d",&vall);
                struct Node *node = (struct Node*)malloc(sizeof(struct Node));
                node->val = vall;
                SortedInsert(myList,node);
                break;

		case 'u':
			InsertSort(myList);
			break;
//		case 't':
//			val = TailOfList(myList);
//			if (val != -1)
//				printf("rear element is %d\n", val);
//			break;
		case 'e':
			exit = TRUE;
			break;
		default:
			printf("command not recognized\n");
			break;
		}
		DisplayList(myList);
	}

	printf("\n");
	system("PAUSE");
	return 0;
}

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
	l->tail = l->head;
	l->size = 0;
}

int IsEmptyList(List l)
{
	return (l->size == 0);
}

int ListSize(List l)
{
	return (l->size);
}

int HeadOfList(List l)
{
	if (!IsEmptyList(l))
		return l->head->next->val;
	else
	{
		printf("The linked list is empty\n");
		return -1;
	}
}

int TailOfList(List l)
{
	if (!IsEmptyList(l))
		return l->tail->val;
	else
	{
		printf("The linked list is empty\n");
		return -1;
	}
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


int SortedInsert(List l, struct Node *new_node){
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


void InsertSort(List l){
    struct Node *p;

	p = l->head->next;
	printf("List content:\n");

	while (p!= NULL){

		SortedInsert(l, p);
		printf("here");
		p = p->next;
	}

}
