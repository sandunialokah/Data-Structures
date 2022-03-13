#include<stdio.h>
#define MAX 20

int priorityq[MAX];
int rear=-1;
int front=-1;

void insert(int data);
void max_heapify(int i);
void build_maxheap();
void display();
void swap(int a, int b);
// void insert_value (int val);
// void increase_value (int i, int val);

int main(){
	// not finished
	insert(4);
	insert(6);
	insert(2);
	display();
}

void insert(int data){
	if(rear>=MAX-1){
		printf("Queue is full\n");
	}
	else if(rear==-1 && front==-1){
		front++;
		rear++;
		priorityq[rear]=data;
	}
	else{
		rear++;
		priorityq[rear]=data;
		build_maxheap();
	}
}

/*
void insert_value(int val)
{
    rear = rear + 1;
    priorityq[ rear ] = -1;  //assuming all the numbers greater than 0 are to be inserted in queue.
    increase_value(rear, val);
}

void increase_value (int i, int val)
{
    if(val <priorityq[ i ])
    {
        printf("New value is less than current value, can’t be inserted");
        return;
    }
    priorityq[ i ] = val;
    while( i > 1 && priorityq[ i/2 ] < priorityq[ i ])
    {
        swap(priorityq[ i/2 ], priorityq[ i ]);
        i = i/2;
    }
}
*/
void max_heapify(int i){
	int largest;
	int left=(2*i)+1; // left child
	int right=(2*i)+2; // right child
	if(left<=rear && priorityq[left]> priorityq[i]){
		largest=left;
	}
	else{
		largest=i;
	}
	if(right<=rear && priorityq[right]>priorityq[i]){
		largest=right;
	}
	if(largest!=i){
		swap(priorityq[i],priorityq[largest]);
		max_heapify(largest);
	}
}

void build_maxheap(){
	int i;
	for(i=(rear-1)/2;i>=0;i--){
		max_heapify(i);
	}
}

void swap(int a, int b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void display(){
	int i;
	for(i=front;i<=rear;i++){
		printf("%d ", priorityq[i]);
	}
}
