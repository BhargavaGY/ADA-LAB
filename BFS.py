from collections import defaultdict

class Graph:
    
    def __init__(self, n):
        
        self.graph = defaultdict(list)
        self.number_nodes = n
        
    def addEdge(self, vertice_1, vertice_2):
        
        self.graph[vertice_1].append(vertice_2)
        
    def BFS(self, s):
        
        visited = [False]*self.number_nodes
        
        queue = []
        queue.append(s)
        visited[s] = True
        
        while queue:
            
            s = queue.pop()
            print(s, end=" ")
            
            for i in self.graph[s]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True
                    
    
g = Graph(4)

g.addEdge(0,1)
g.addEdge(0,2)
g.addEdge(1,2)
g.addEdge(2,0)
g.addEdge(2,3)
g.addEdge(3,3)

g.BFS(2)
