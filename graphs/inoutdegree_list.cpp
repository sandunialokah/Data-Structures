#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void create_list(int n, list<int> adj_list[]);
void add_edge(list<int> adj_list[], int f, int t);
void in_outdegree(list<int> adj_list[], int n);

int main(){
    int n;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    list<int>adj_list[n];
    create_list(n,adj_list);
    in_outdegree(adj_list,n);
}

void create_list(int n, list<int> adj_list[]){
    int e, f, t;
    cout << "Enter the number of edges in the graph: ";
    cin >> e;
    for(int i=0;i<e;i++){
        cout << "Enter edge " << i+1 <<": ";
        cin >> f >> t;
        add_edge(adj_list,f,t);
    }
}

void add_edge(list<int> adj_list[], int f, int t){
    adj_list[f].push_back(t);
    adj_list[t].push_back(f); // this line is used only if it is an undirected graph if direct comment this line
}

void in_outdegree(list<int> adj_list[], int n){
    int outd[n], ind[n], val;
    
    for(int i=0;i<n;i++){
        ind[i]=0;
    }

    for(int i=0;i<n;i++){
        outd[i]=adj_list[i].size();
        list<int>:: iterator it;
        for(it=adj_list[i].begin();it!=adj_list[i].end();it++){
            ind[*it] += 1;
        }
    }

    cout << "Indegree: " << endl;
    for(int i=0;i<n;i++){
        cout << i << " " << ind[i] << endl;
    }

    cout << "Outdegree: " << endl;
    for(int i=0;i<n;i++){
        cout << i << " " << outd[i] << endl;
    }
}

