#include<stdio.h>
#define MAX 5

void bfs(int adj[][MAX], int visited[], int start);

int main(){
    int visited[MAX]={0};
    int adj[MAX][MAX];
    printf("Enter the adjacency matrix: ");
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            scanf("%d", &adj[i][j]);
        }
    }
    bfs(adj,visited,0);
}

void bfs(int adj[][MAX], int visited[], int start){
    int queue[MAX], front, rear;
    front=-1;
    rear=-1;
    queue[++rear]=start;
    visited[start]=1;
    while(front!=rear){
        start=queue[++front];
        if(start==4){
            printf("%c ", 4+65);
        }
        else{
            printf("%c ", start+65);
        }
        for(int i=0;i<MAX;i++){
            if(adj[start][i]==1 && visited[i]!=1){
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}