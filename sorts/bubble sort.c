#include<stdio.h>

void swap(int arr[],int a, int b);

int main(){
	int n, i, arr[20], j;
	printf("Enter the number of elements to be entered to the array: ");
	scanf("%d", &n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++){
		printf("Elemenet %d: ", i);
		scanf("%d", &arr[i]);
	}
	for(i=0;i<n-1;i++){
		j=n-1;
		while(j>i){
			if(arr[j]< arr[j-1]){
				swap(arr,j,j-1);
			}
			j--;
		}
	}
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
}

void swap(int arr[],int a, int b){
	int temp;
	temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
