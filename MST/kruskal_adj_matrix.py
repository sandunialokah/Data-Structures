import random
import time

class Graph():
    def __init__(self,size):
        self.adjMatrix = []
        for i in range(size):
            self.adjMatrix.append([float('inf') for i in range(size)])
        self.size = size
        
    def add_edge(self, v1, v2, w):
        self.adjMatrix[v1][v2] = w
        # if its an undirected graph following line should be added
        self.adjMatrix[v2][v1] = w
        
    def print_matrix(self):
        for row in self.adjMatrix:
            print([val for val in row])
    
    def get_matrix(self, size):
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
                for j in range(self.size):
                    if self.find_parent(parent, i) != self.find_parent(parent, j) and self.adjMatrix[i][j] < min:
                        min = self.adjMatrix[i][j]
                        a = i
                        b = j

            if b!=-1:
                self.update_parent(parent, a, b)
                MST.add_edge(a, b, min)
                KMST_Cost += min
            e += 1
            
        print()
        print("Kruskal's Minimum Spanning Tree: ")
        MST.print_matrix()
        print()
        print("MST Cost = {}".format(KMST_Cost))
    
if __name__ == '__main__':
    len = int(input("Enter size of the matrix: "))
    g = Graph(len)
    n = int(input("Enter number of edges in the graph: "))
    for i in range(n):
        g.get_matrix(len)

    print()
    print("Graph: ")
    g.print_matrix()
    start_time_1 = time.time()
    g.KMST()
    end_time_1 = time.time()
    execution_time_1 = round((end_time_1 - start_time_1),2)
    print("\nExecution time: ", execution_time_1, "seconds\n")