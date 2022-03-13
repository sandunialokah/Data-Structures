#include<stdio.h>

void selection_sort(int arr[], int n);
void swap(int arr[], int i, int j);


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
	selection_sort(arr,n);
	printf("\nThe sorted array: \n");
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);		
	}	
}

void selection_sort(int arr[], int n){
	int j, min, i;
	int temp;
	for(j=0;j<n-1;j++){
		min=j;
		for(i=j+1;i<n;i++){
			if(arr[i]<arr[min]){
				min=i;
			}
		}
		printf("\n%d %d\n", min, j);
		temp=arr[min];
		arr[min]=arr[j];
		arr[j]=temp;
	}
}

