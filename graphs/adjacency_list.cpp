#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void create_list(int n, list<int>adj_list[]);
void add_edge(int f, int t, list<int>adj_list[]);
void display(int n, list<int> adj_list[]);

int main(){
    int n;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    list<int>adj_list[n];
    create_list(n,adj_list);
    display(n,adj_list);
}

void create_list(int n, list<int> adj_list[]){
    int e, f, t;
    cout << "Enter the number of edges: ";
    cin >> e;
    for(int i=0;i<e;i++){
        cout << "Enter edge " << i+1 << ": ";
        cin >> f >> t;
        add_edge(f, t, adj_list);
    }
}

void add_edge(int f, int t, list<int> adj_list[]){
    adj_list[f].push_back(t);
    adj_list[t].push_back(f); // this line is used only if it is an undirected graph if direct comment this line
}

void display(int n, list<int> adj_list[]){
    for(int i=0;i<n;i++){
        cout << i << " --> ";
        list<int>::iterator it;
        for(it=adj_list[i].begin();it!=adj_list[i].end();it++){
            cout << *it << " ";
        }
        cout << "\n";
    }
}