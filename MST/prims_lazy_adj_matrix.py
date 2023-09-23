from queue import PriorityQueue
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
        for i in range(self.size):
            if self.adjMatrix[s][i] < float('inf') and not visited[i]:
                pqueue.put((self.adjMatrix[s][i], s, i))
            

    def PMST(self, s):
        MST = Graph(self.size)
        #pqueue = [(weight, source, dest)]
        pqueue = PriorityQueue()
        visited = [False for i in range(self.size)]
        self.push(pqueue, visited, s)
        global n
        e =0 
        PMST_Cost = 0
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
        MST.print_matrix()
        print()
        print("MST Cost = {}".format(PMST_Cost))
        
    
if __name__ == '__main__':
    len = int(input("Enter size of the matrix: "))
    g = Graph(len)
    global n
    n = int(input("Enter number of edges in the graph: "))
    for i in range(n):
        g.get_matrix(len)

    print()
    print("Graph: ")
    g.print_matrix()
    
    
    start_time_1 = time.time()
    g.PMST(0)
    end_time_1 = time.time()
    execution_time_1 = round((end_time_1 - start_time_1),2)
    print("\nExecution time: ", execution_time_1, "seconds\n")