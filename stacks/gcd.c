#include<stdio.h>
int main(){
	int n1, n2;
	printf("Enter the two numbers: ");
	scanf("%d %d", &n1, &n2);
	printf("The greatest common divisor is %d", GCD(n1,n2));
	return 0;
}

int GCD(int n1, int n2){
	int rem;
	rem=n1%n2;
	if(rem==0){
		return n2;
	}
	else{
		return GCD(n2,rem);
	}
}
