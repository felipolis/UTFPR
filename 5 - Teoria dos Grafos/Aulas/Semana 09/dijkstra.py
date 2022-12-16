# Algoritmo de Dijsktra

class Grafo:
    def __init__(self, n):
        self.n = n
        self.matrix_adj = [[float('inf') for _ in range(n)] for _ in range(n)]
        self.distancias = [float('inf') for _ in range(n)]
        self.predecessores = [-1 for _ in range(n)]
        self.vertices = [i for i in range(n)]

    def add(self, u, v, custo):
        self.matrix_adj[u][v] = custo
        self.matrix_adj[v][u] = custo

    def dijkstra(self, s):
        self.distancias[s] = 0
        self.predecessores[s] = -1
        while self.vertices:
            u = self.vertices.pop(self.distancias.index(min(self.distancias)))
            for v in range(self.n):
                if self.matrix_adj[u][v] != float('inf'):
                    if self.distancias[v] > self.distancias[u] + self.matrix_adj[u][v]:
                        self.distancias[v] = self.distancias[u] + self.matrix_adj[u][v]
                        self.predecessores[v] = u

    def caminho(self, s, t):
        self.dijkstra(s)
        if self.distancias[t] == float('inf'):
            return -1
        else:
            u = t
            caminho = []
            while u != s:
                caminho.append(u)
                u = self.predecessores[u]
            caminho.append(s)
            caminho.reverse()
            return caminho

            
# Exemplo de uso
g = Grafo(6)
g.add(0, 1, 4)
g.add(0, 2, 2)
g.add(1, 2, 1)
g.add(1, 3, 5)
g.add(2, 3, 8)
g.add(2, 4, 10)
g.add(3, 4, 2)
g.add(3, 5, 6)
g.add(4, 5, 2)
print(g.caminho(0, 5))

