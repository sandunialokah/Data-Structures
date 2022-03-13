#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, *ptr, i, sum;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	ptr=(int*)malloc(n*sizeof(int));
	if(ptr==NULL){
		printf("Error!memory not allocated.\n");
		return 1;
	}
	printf("Enter elements of the array: ");
	for(i=0;i<n;i++){
		scanf("%d", ptr+i);
		sum+=*(ptr+i);
	}
	printf("sum= %d", sum);
	free(ptr);
	return 0;
}
