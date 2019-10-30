#include <stdio.h>
#include <string.h>

struct Stack {
    int top;
    int capacity;
    int* array;
};

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

struct Stack* createStack(int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    //printf("%d pushed to stack\n", item);
}


int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}


void main(){
    char str[100]; int i;
    printf("Enter your string: ");
    scanf("%s",str);
    struct Stack* stack = createStack(100);
    for(i=0;i<strlen(str);i++){

        if(str[i]=='('){
            push(stack,1);
        }else if(str[i]==')'){
            pop(stack);
        }
    }
    if(isEmpty(stack)){
        printf("Equal number of parentheses\n");
    }else{
        printf("Not equal\n");
    }

}
