#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int numVertices;
    list<int> *adjLists;
    bool *visited;
    int time;
    public:
        Graph(int V);
        void addEdge(int src, int dest);
        void edgeClassification(int vertex);
};

Graph::Graph(int vertices){
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
    time= 0;
}

void Graph::addEdge(int src, int dest){
    adjLists[src].push_front(dest);
    //adjLists[dest].push_front(src);
}

void Graph::edgeClassification(int vertex){
    visited[vertex] = true;
    int startTime[numVertices];
    int endTime[numVertices];
    startTime[vertex] = time;
    ++time;
    list<int> adjList = adjLists[vertex];
   // cout << vertex << " ";
    list<int>::iterator i;
    for(i=adjList.begin();i!=adjList.end();i++){
        if(!visited[*i]){
            cout << "Tree edge: " << vertex << "--> " << *i;
            edgeClassification(*i);
        }
        else{
            if(startTime[vertex] > startTime[*i]){
                cout << "Back edge: " << vertex << "--> " << *i;
            }
            else if(startTime[vertex] < startTime[*i]){
                cout << "Forward edge: " << vertex << "--> " << *i;
            }
            else{
                cout << "Cross edge: " << vertex << "--> " << *i;
            }
        }
        endTime[vertex]=time;
        ++time;
    }
}

int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,3);
    g.addEdge(3,1);
    g.addEdge(4,2);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.edgeClassification(0);
}