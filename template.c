#include <stdio.h>
#include <stdlib.h>

/*True or False declaration*/
#define FALSE 0
#define TRUE 1

/*Node declaration of a Linked List*/
struct Node
{
	int val;
	struct Node* next;
};

/*Function signatures*/
void StaticBuild1234(void);
struct Node* DynamicBuild1234(void);
struct Node* DynamicBuild1234_Modified(void);
void PrintList(struct Node*);
int SearchItem(struct Node*, int);
int MinValue(struct Node*);
int SumList(struct Node*);
void RecursivePrintList(struct Node*);
void ReversePrintList(struct Node*);
struct Node* CopyList(struct Node*);
struct Node* DestroyList(struct Node*);
struct Node* ReverseList(struct Node*);
struct Node* RecursiveCopyList(struct Node*);
struct Node* RecursiveReverseList(struct Node*, struct Node*);
int inner_product(struct Node*, struct Node*);

int main()
{
	char command;
	int exit = FALSE;
    int ret=0;
	struct Node *myList;
	struct Node *mySecondList;
	int keysearch;

	while (!exit)
	{
		printf("a: Static Build\n");
		printf("d: Dynamic Build\n");
		printf("n: Dynamic Build Mod\n");
		printf("f: Find\n");
		printf("s: Sum\n");
		printf("m: Minimum\n");
		printf("r: Reverse Print\n");
		printf("x: Exit\n");
		printf("Enter command: ");
		scanf("%c", &command);
		fflush(stdin);
        struct Node* generalhead;
		switch (command)
		{
		case 'a':
			StaticBuild1234();
			break;
        case 'd':
		printf("d: Dynamic Build\n");
			generalhead = DynamicBuild1234();
			break;
        case 'n':
            generalhead = DynamicBuild1234_Modified();
            break;
        case 'f':
            printf("Which key to search?: ");
            scanf("%d",&keysearch);
			ret = SearchItem(generalhead,keysearch);
			printf(ret ? "Key found\n" : "Key not found\n");
			break;
        case 'm':
            printf("Min value is: %d\n",MinValue(generalhead));
			break;
        case 's':
            printf("The sum is: %d\n",SumList(generalhead));
			break;
        case 'r':
            ReversePrintList(generalhead);
			break;
		case 'x':
			exit = TRUE;
			break;


		default:
			printf("Command is not recognized!\n");
			break;
		}
	}

	printf("\n");
	system("PAUSE");
	return 0;
}


void StaticBuild1234(void)
{
	struct Node node1, node2, node3, node4, node5;
	struct Node *head;

	head = &node1;

	node1.val = 4;
	node1.next = &node2;

	node2.val = 5;
	node2.next = &node3;

	node3.val = 7;
	node3.next = &node4;

	node4.val = 6;
	node4.next = NULL;

	PrintList(head);
}

void PrintList(struct Node *p){
 	int key = 0;

 	while(p!= NULL){
        printf("%d\n",p->val);
        p = p->next;
 	}
}


struct Node* DynamicBuild1234(void){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node4 = (struct Node *)malloc(sizeof(struct Node));

    head = node1;
    node1->val = 4;
    node1->next = node2;
    node2->val = 5;
    node2->next = node3;
    node3->val = 7;
    node3->next = node4;
    node4->val = 6;
    node4->next = NULL;

    PrintList(head);
    return head;
}


struct Node* DynamicBuild1234_Modified(void){
 	struct Node *head = (struct Node*)malloc(sizeof(struct Node*));
 	struct Node *curr = head;

 	int temp = 0;
 	while(temp != -1){
        scanf("%d",&temp);
        if(temp!=-1){
            curr->val = temp;
            curr->next = (struct Node*)malloc(sizeof(struct Node*));
            curr = curr->next;
        } else {
            curr->next = NULL;

        }
 	}
 	PrintList(head);
 	return head;
}

/*A function that searches a value in a linked list*/
int SearchItem(struct Node *p, int key){
 	while(p!= NULL){
        printf("%d\n",p->val);
        if(key == p->val){
            return 1;
        }
        p = p->next;
 	}
 	return 0;
}

/*A function that traverses a linked list and returns the minimum value*/
int MinValue(struct Node *p)
{
 	int min=9999;
 	while(p!= NULL){
        printf("%d\n",p->val);
        if(p->val < min){
            min = p->val;
        }
        p = p->next;
 	}
 	return min;
}

/*A function that traverses a linked list and returns the sum of the values*/
int SumList(struct Node *p)
{
 	int sum=0;
 	while(p!= NULL){
        printf("%d\n",p->val);
        sum = sum + p->val;
        p = p->next;
 	}
 	return sum;
}

/*A function that prints the elements of a given linked list by using recursion*/
void RecursivePrintList(struct Node *p)
{
 	//TO BE COMPLETED
}

/*A function that prints the elements of a given linked list in reverse order by
using recursion*/
void ReversePrintList(struct Node *p)
{
    if(p != NULL){
        ReversePrintList(p->next);
        printf("%d\n",p->val);
    }
}

/*A function that takes a linked list and makes a copy of it - This function
returns the pointer to the first element of the list as a result.*/
struct Node* CopyList(struct Node *p)
{
 	//TO BE COMPLETED
}

struct Node* RecursiveCopyList(struct Node *head)
{
 	//TO BE COMPLETED
}

/*A function that traverses a linked list and frees the memory occupied by the
list elements one element at a time*/
struct Node* DestroyList(struct Node *p)
{
 	//TO BE COMPLETED
}

/*A function that takes a linked list and creates a new linked list where the
elements of the original list appear in reverse order in the new list*/
struct Node* ReverseList(struct Node *p)
{
 	//TO BE COMPLETED
}

struct Node* RecursiveReverseList(struct Node *ptr, struct Node *previous)
{
 	//TO BE COMPLETED
}

/*A function that calculates the inner product of two linked lists*/
int inner_product(struct Node *list1, struct Node *list2)
{
 	//TO BE COMPLETED
}
