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
        src = random.randint(0,size-1)
        dest = random.randint(0,size-1)
        weight = random.randint(0,100)
        # vertices = input("Enter from and to vertices and weight(followed by a space): ") 
        # vertices = vertices.split()
        # vertices = [int(vertex) for vertex in vertices]
        # self.add_edge(vertices[0], vertices[1], vertices[2])
        if src != dest:
            self.add_edge(src, dest, weight)
            
    def find_parent(self, parent, v):
        while parent[v] != v:
            v = parent[v]
        return v
    
    def update_parent(self, parent, i, j):
        a = self.find_parent(parent, i)
        b = self.find_parent(parent, j)
        parent[a] = b
        
    def KMST(self):
        MST = Graph(self.size)
        parent = [i for i in range(self.size)]
        KMST_Cost = 0
        e = 0
        while e < (self.size - 1):
            min = float('inf')
            a = -1
            b = -1
            
            for i in range(self.size):
                temp = self.graph[i]
                while temp:
                    j = temp.vertex
                    if self.find_parent(parent, i) != self.find_parent(parent, j) and temp.weight < min:
                        min = temp.weight
                        a = i
                        b = j
                    temp = temp.next

           
        
            
            if b!=-1:
                self.update_parent(parent, a, b)
                MST.add_edge(a, b, min)  
                KMST_Cost += min
            e += 1
            
        print()
        print("Kruskal's Minimum Spanning Tree: ")
        MST.print_graph()
        print()
        print("MST Cost = {}".format(KMST_Cost))
        
        
if __name__ == "__main__":
    len = int(input("Enter the number of vertices of the graph: "))
    g = Graph(len)
    n = int(input("Enter number of edges in the graph: "))
    for i in range(n):
        g.get_graph(len)

    print()
    g.print_graph()
    
    start_time_1 = time.time()
    g.KMST()
    end_time_1 = time.time()
    execution_time_1 = round((end_time_1 - start_time_1),2)
    print("\nExecution time: ", execution_time_1, "seconds\n")