#include <stdio.h>


int inner_product(int *a, int *b, int n){
	int i,final=0;
	
	for(i=0;i<n;i++){
		final = final + a[i]*b[i];
	}
	return final;
	
}

void main(){
	int size,i,result;
	printf("How many elements?: ");
	scanf("%d",&size);
	int arr1[size],arr2[size];
	for(i=0;i<size;i++){
		printf("Enter element to store in first array: ");
		scanf("%d",&arr1[i]);
	}

	for(i=0;i<size;i++){
		printf("Enter element to store in second array: ");
		scanf("%d",&arr2[i]);
	}
	
	result = inner_product(&arr1,&arr2,size);
	
	printf("Inner product is %d",result);
}
