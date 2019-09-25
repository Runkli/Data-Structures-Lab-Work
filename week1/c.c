#include <stdio.h>


void  pay_month(int  dollars,  int  *twenties,  int  *tens,  int  *fives,  int *ones){
    *twenties = dollars/20;
    dollars = dollars - (*twenties*20);
    *tens = dollars/10;
    dollars = dollars - (*tens*10);
    *fives = dollars/5;
    dollars = dollars - (*fives*5);
    *ones = dollars;
    dollars = dollars - (*ones*1);

}




void main(){
    int dollars=134, twenties=0, tens=0, fives=0, ones=0;

    pay_month(dollars,&twenties,&tens,&fives,&ones);
    printf("%d twenties, %d tens, %d fives, %d ones",twenties,tens,fives,ones);

}
