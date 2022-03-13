#include<stdio.h>

void insertion_sort(int arr[], int n);

int main(){
	int arr[50];
	int i, n;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("Enter the elemtsof the array: \n");
	for(i=0;i<n;i++){
		printf("Enter arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	printf("The input array: \n");
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);		
	}
	insertion_sort(arr,n);
	printf("\nThe sorted array: \n");
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);		
	}
}

void insertion_sort(int arr[], int n){
	int i,j,key;
	for(j=1;j<n;j++){
		key=arr[j];
		i=j-1;
		while(i>=0 && arr[i]> key){
			arr[i+1]=arr[i];
			i--;
		}
		arr[i+1]=key;
	}
}
