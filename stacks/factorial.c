#include<stdio.h>
int main(){
	int n;
	printf("Enter the number: ");
	scanf("%d", &n);
	printf("The value of factorial %d is %d", n, fac(n));
	return 0;
}

int fac(int n){
	if(n==1){
		return 1;
	}
	else{
		return n*fac(n-1);
	}
}
