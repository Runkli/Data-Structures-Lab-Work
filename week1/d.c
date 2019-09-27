#include <stdio.h>
#include <math.h>

void main(){
	int i,maxdeg;
	printf("Input the max degree: ");
	scanf("%d",&maxdeg);
	int coeffs[maxdeg];
	
	for(i=0;i<maxdeg;i++){
		printf("enter the coefficient no%d: ",i+1);
		scanf("%d",&coeffs[i]);
	}
	//get_poly(&coeffs,maxdeg);
	eval_poly(&coeffs,maxdeg,2);
}

void get_poly(int *coeff, int degreep){
	int i=0;
	for(i=0;i<degreep;i++){
		printf("enter the coefficient no%d: ");
		scanf("%d",coeff[i]);
	}
	for(i=0;i<degreep;i++){
		printf("%d ",coeff[i]);
	}
}

int eval_poly(int *coeff, int degree, int x){
	int sum,i=0;
	for(i=0;i<degree;i++){
		sum = sum + pow(coeff[i],degree)*x;
	}
	
	printf("Sum is: %d",sum);
}
