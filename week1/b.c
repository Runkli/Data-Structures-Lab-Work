#include <stdio.h>
#include <math.h>

void find_largest_smallest(int a[], int n, int *largest, int *smallest){
	int i;
	*largest = 0;
	for(i=0;i<n;i++){
		if (a[i]>*largest){
			*largest = a[i];
		}
	}
	*smallest=*largest;
	
	for(i=0;i<n;i++){
		if(a[i]<*smallest){
			*smallest = a[i];
		}
	}
}


void main(){
	int num,largest,smallest;
	
	printf("How many ints?: ");
	scanf("%d",&num);
	int *arr = (int*)malloc(sizeof(int)*num);
	int i;
	for(i=0;i<num;i++){
		printf("Enter element no%d: ",i+1);
		scanf("%d",&arr[i]);
	}

	for(i=0; i<num;i++){
		printf("%d ",arr[i]);
	}
	
	find_largest_smallest(arr,num,&largest,&smallest);
	printf("\nThe largest element is %d,\nThe smallest element is %d",largest,smallest);
}
