#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph{
    int numVertices;
    list<int> *adjLists;
    bool *visited;
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);
    public:
        Graph(int V);
        void addEdge(int src, int dest);
        void topologicalSort();
};

Graph::Graph(int vertices){
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
}

void Graph::addEdge(int src, int dest){
    adjLists[src].push_back(dest);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack){
    visited[v] = true;
    list<int>::iterator i;
    for(i=adjLists[v].begin(); i!=adjLists[v].end(); i++){
        if(!visited[*i]){
            topologicalSortUtil(*i, visited, Stack);
        }
    }
    Stack.push(v);
}

void Graph::topologicalSort(){
    stack<int> Stack;

    for(int i=0;i<numVertices;i++){
        visited[i]=false;
    }
    for(int i=0;i<numVertices;i++){
        if(visited[i] == false){
            topologicalSortUtil(i, visited, Stack);
        }
    }
    while(Stack.empty() == false){
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();
}