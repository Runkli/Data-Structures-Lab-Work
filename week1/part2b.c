#include <stdio.h>

int search (int *a, int n, int key){
	int i;
	for(i=0;i<n;i++){
		if(key==a[i]){
			printf("Key found");
			return 0;
		}
	}
	printf("Key not found");
}

void main(){
	int i,size;
	printf("How many elements?: ");
	scanf("%d",&size);
	int arr[size];
	for(i=0;i<size;i++){
		printf("Enter element to store: ");
		scanf("%d",&arr[i]);
	}
	int key;
	char choice = 'y';
	while(1){
		printf("Enter element to search: ");
		scanf("%d",&key);
		search(&arr, size, key);
		
		printf("Search again? (y/n): ");
		scanf("%c",&choice);
		if(choice=='n'){
			break;
		}
	}
	
}
