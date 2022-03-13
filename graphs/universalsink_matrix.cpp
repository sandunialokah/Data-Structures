#include<iostream>
using namespace std;

int adj_matrix[20][20];
void create_matrix(int n);
void add_edge(int f, int t);
void in_out_degree(int n, int ind[], int outd[]);
void sink(int n, int ind[], int outd[]);
void display(int n);

int main(){
    int n;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    int ind[n], outd[n];
    create_matrix(n);
    display(n);
    in_out_degree(n,ind,outd);
    sink(n,ind,outd);
}

void create_matrix(int n){
    int e,f,t;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj_matrix[i][j]=0;
        }
    }

    cout << "Enter the numbre of edges in the graph: ";
    cin >> e;
    for(int i=0;i<e;i++){
        cout << "Enter edge " << i+1 << ": ";
        cin>> f >> t;
        add_edge(f,t);
    }
   
}

void add_edge(int f, int t){
    adj_matrix[f][t]=1;
    // adj_matrix[t][f]=1;  // this line is used only if it is an undirected graph if direct comment this line
}

void in_out_degree(int n, int ind[], int outd[]){
    for(int i=0;i<n;i++){
        outd[i]=0;
        for(int j=0;j<n;j++){
            outd[i] += adj_matrix[i][j];
        }
    }
    cout << "Outdegree: " << endl;
    for(int i=0;i<n;i++){
        cout << i << ": " << outd[i] << endl;
    }
    for(int i=0;i<n;i++){
        ind[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ind[i] += adj_matrix[j][i];
        }
    }
    cout << "Indegree: " << endl;
    for(int i=0;i<n;i++){
        cout << i << ": " << ind[i] << endl;
    }
}

void sink(int n, int ind[], int outd[]){
    int flag=0;
    for(int i=0;i<n;i++){
        if(ind[i]==n-1 && outd[i]==0){
            flag=1;
            cout << i << " is an universal sink." << endl;;
        }
    }
    if(flag==0){
        cout << "There are no universal sinks in this graph." << endl;
    }
}

void display(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}