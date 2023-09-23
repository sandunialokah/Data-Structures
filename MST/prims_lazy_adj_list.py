from queue import PriorityQueue
import random
import time

class Node:
    def __init__(self, val, weight):
        self.vertex = val
        self.weight = weight
        self.next = None
class Graph:
    def __init__(self, size):
        self.size = size
        self.graph = [None] * self.size
        
    def add_edge(self, v1, v2, w):
        node = Node(v1, w)
        node.next = self.graph[v2]
        self.graph[v2] = node
        
        node = Node(v2, w)
        node.next = self.graph[v1]
        self.graph[v1] = node
        
    def print_graph(self):
        for i in range(self.size):
            print(str(i) + ":", end="")
            temp = self.graph[i]
            while temp:
                print(" -> (" + str(temp.vertex) + ","+ str(temp.weight) + ")", end="")
                temp = temp.next
            print()
    
    def get_graph(self, size):
        # vertices = input("Enter from and to vertices and weight(followed by a space): ") 
        # vertices = vertices.split()
        # vertices = [int(vertex) for vertex in vertices]
        # self.add_edge(vertices[0], vertices[1], vertices[2])
        src = random.randint(0,size-1)
        dest = random.randint(0,size-1)
        weight = random.randint(0,100)
        if src != dest:
            self.add_edge(src, dest, weight)
        
    def push(self, pqueue, visited, s):
        
        visited[s] = True
        # for i in range(self.size):
        temp = self.graph[s]
        while temp:
            if not visited[temp.vertex]:
                pqueue.put((temp.weight, s, temp.vertex))
            temp = temp.next
 
        
    def PMST(self, s):
        MST = Graph(self.size)
        pqueue = PriorityQueue()
        visited = [False for i in range(self.size)]
        PMST_Cost = 0
        self.push(pqueue, visited, s)
        global n
        e = 0
        while not pqueue.empty() and e != n:
            min_edge = pqueue.get()
            if visited[min_edge[2]]:
                continue
            else:
                e += 1
                PMST_Cost +=  min_edge[0]
                MST.add_edge(min_edge[1], min_edge[2], min_edge[0])
                self.push(pqueue, visited, min_edge[2])
        print()
        print("Prim's Minimum Spanning Tree(Lazy): ")
        MST.print_graph()
        print()
        print("MST Cost = {}".format(PMST_Cost))
                
        
        
        
if __name__ == "__main__":
    len = int(input("Enter the number of vertices of the graph: "))
    g = Graph(len)
    n = int(input("Enter number of edges in the graph: "))
    for i in range(n):
        g.get_graph(len)

    print()
    g.print_graph()
    
    start_time_1 = time.time()
    g.PMST(0)
    end_time_1 = time.time()
    execution_time_1 = round((end_time_1 - start_time_1),2)
    print("\nExecution time: ", execution_time_1, "seconds\n")