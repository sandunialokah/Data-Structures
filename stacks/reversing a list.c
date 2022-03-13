#include<stdio.h>

int stk[20];
top=-1;

int main(){
	int n, i, value, arr[20];
	printf("Enter the number of elements to be stored in the stack: ");
	scanf("%d", &n);
	printf("Enter the elements to be stored: \n");
	for(i=0;i<n;i++){
		printf("Enter the %d element: ", i+1);
		scanf("%d", &arr[i]);
	}
	for(i=0;i<n;i++){
		push(arr[i]);
	}
	for(i=0;i<n;i++){
		value=pop();
		arr[i]=value;
	}
	for(i=0;i<n;i++){
		printf("%d", arr[i]);
	}
	
}

void push(int value){
	top++;
	stk[top]=value;
}

int pop(){
	int value;
	value=stk[top];
	top--;
	return value;
}
