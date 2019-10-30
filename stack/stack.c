#include <stdio.h>

struct Stack {
    int top;
    int capacity;
    int* array;
};


struct Stack* createStack(int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}


void emptyStack(struct Stack* stack){
    stack->top = -1;
}


int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}


int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}


void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}


int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}


int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

void copy_array(int *arr1,int *arr2,int n){
    int i;
    for(i=0;i<=n;i++){
        arr2[i]=arr1[i];
    }
}

int main()
{
    struct Stack* stack = createStack(100);
    printf("Initialized stack...\n");
    int temp[500];

    char n;
    int a,j;
    printf("Commands: (a)dd/push, (p)op, (d)isplay, (e)xit, is(f)ull, is(e)mpty, (r)everse \nEnter command: ");
    scanf("%c",&n);
    while(n!='e'){
        if(n=='p'){
            printf("Popped %d\n",pop(stack));
        }else if(n=='a'){
            printf("Enter number to push onto stack: ");
            scanf("%d",&a);
            push(stack,a);
        }else if(n=='f'){
            if(isFull(stack)){
                printf("Full\n");
            }else{
                printf("Not full\n");
            }
        }else if(n=='d'){
            copy_array(stack->array,temp,stack->top);
            for(j=0;j<=stack->top;j++){
                printf("%d, ",temp[j]);
            }
        }else if(n=='e'){
            if(isEmpty(stack)){
                printf("Empty\n");
            }else{
                printf("Not Empty\n");
            }
        }else if(n=='r'){
            revPop(stack);
        }
        printf("Enter command: ");
        scanf("%c",&n);
    }

    return 0;
}

void revPop(struct Stack* stack){
    printf("Popping: ");
    while(stack->top!=-1){
        printf("%d ",pop(stack));
    }
}
