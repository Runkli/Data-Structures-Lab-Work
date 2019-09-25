#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

void  calculate_volume_surface(int  radius,  float  *volume,  float *surface){
	*volume = 4/3 * M_PI * pow(radius,3);
	*surface = 4 * M_PI * pow(radius,2);
	
}

void main(){
	int radius;
	float volume,surface;
	scanf("%d",&radius);
	calculate_volume_surface(radius,&volume,&surface);
	printf("Volume is: %f\nSurface is: %f",volume,surface);
	
}
