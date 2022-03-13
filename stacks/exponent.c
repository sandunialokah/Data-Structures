#include<stdio.h>

int exp(int a, int b);

int main(){
	int index, exponent;
	printf("Enter the index: ");
	scanf("%d", &index);
	printf("Enter the exponent: ");
	scanf("%d", &exponent);
	printf("The value is %d", exp(index,exponent));
}

int exp(int a, int b){
	if(b==0){
		return 1;
	}
	else{
		return a*exp(a,b-1);
	}
}
