#include<stdio.h>

toh(int n, char source, char dest, char spare);

int main(){
	int n;
	printf("Enter the number of discs:  ");
	scanf("%d", &n);
	toh(n,'A','C','B');
}

toh(int n, char source, char dest, char spare){
	if(n==1){
		printf("move from %c to %c\n", source, dest);
	}
	else{
		toh(n-1,source,spare,dest);
		toh(1,source,dest,spare);
		toh(n-1,spare,dest,source);
	}
}
