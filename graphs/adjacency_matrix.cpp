#include<iostream>
using namespace std;

int adj[20][20];
void add_edge(int n, int f, int t);
void create_matrix(int n);
void display(int n);

int main(){
    int n;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    create_matrix(n);
    display(n);
}

void create_matrix(int n){
    int e,f,t;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j]=0;
        }
    }

    cout << "Enter the number of edges in the graph: ";
    cin >> e;
    cout << "Enter the edges in the format \tfrom to" << endl;
    for(int i=0;i<e;i++){
        cout << "Enter edge " << i << ": ";
        cin >> f >> t;
        add_edge(n, f, t);
        
    }
} 

void add_edge(int n, int f, int t){
    adj[f][t]=1;
    adj[t][f]=1; // this line is used only if it is an undirected graph if direct comment this line
}

void display(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}