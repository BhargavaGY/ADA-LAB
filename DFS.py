from collections import defaultdict

class Graph:
    
    def __init__(self):
        
        self.graph = defaultdict(list)
        
    def addEdge(self, vertice_1, vertice_2):
        
        self.graph[vertice_1].append(vertice_2)
        
    def DFSRec(self, s, visited):
        
        visited.append(s)
        print(s, end=" ")
        
        for vertice in self.graph[s]:
            if vertice not in visited:
                self.DFSRec(vertice, visited)
                    
    def DFS(self,s):
        visited = []
        
        self.DFSRec(s, visited)

g = Graph()

g.addEdge(0,1)
g.addEdge(0,2)
g.addEdge(1,2)
g.addEdge(2,0)
g.addEdge(2,3)
g.addEdge(3,3)

g.DFS(2)
