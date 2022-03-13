#include<stdio.h>

void merge(int arr[], int beg, int mid, int end);
void merge_sort(int arr[], int beg, int end);

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
	merge_sort(arr,0,n-1);
	printf("\nThe sorted array: \n");
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);		
	}		
}

void merge(int arr[], int beg, int mid, int end){
	int i,j,index, temp[50], k;
	i=beg;
	j=mid+1;
	index=beg;
	while(i<=mid && j<=end){
		if(arr[i]<arr[j]){
			temp[index]=arr[i];
			i++;
		}
		else{
			temp[index]=arr[j];
			j++;
		}
		index++;
	}
	if(i>mid){
		while(j<=end){
			temp[index]=arr[j];
			index++;
			j++;
		}
	}
	else{
		while(i<=mid){
			temp[index]=arr[i];
			index++;
			i++;
		}
	}
	for(k=beg;k<index;k++){
		arr[k]=temp[k];
	}
}

void merge_sort(int arr[], int beg, int end){
	int mid;
	if(beg<end){
		mid=(beg+end)/2;
		merge_sort(arr,beg,mid);
		merge_sort(arr,mid+1,end);
		merge(arr,beg,mid,end);
	}
	
}
