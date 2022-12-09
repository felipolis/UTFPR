
class Graph:
    def __init__(self, n):
        self.n = n
        self.adj = [[] for i in range(n)]

    """
    Adiciona uma aresta direcionada que sai do vértice u para o vértice v com peso w
    u: inteiro que representa o vértice de origem
    v: inteiro que representa o vértice de destino
    w: inteiro que representa o peso da aresta (opcional)
    """
    def addEdge(self, u, v, w=1):
        self.adj[u].append((v,w))
    
    """
    Retorna o grau de entrada do vértice V
    V: inteiro que representa o vértice
    """
    def getInDegree(self, v):
        sum = 0
        for i in self.adj:
            for j in i:
                if j[0] == v:
                    sum += 1
        return sum
    
    """
    Retorna o grau de saída do vértice V
    V: inteiro que representa o vértice
    """
    def getOutDegree(self, v):
        return len(self.adj[v])
    
    """
    Retorna o grau do vértice V
    V: inteiro que representa o vértice
    """
    def getDegree(self, v):
        return self.getInDegree(v) + self.getOutDegree(v)
