# Algoritmo de Bellman-Ford

class Grafo:
    def __init__(self, n):
        self.n = n
        self.matrix_adj = [[float('inf') for _ in range(n)] for _ in range(n)]
        self.arestas = []
        self.distancias = [float('inf') for _ in range(n)]
        self.predecessores = [-1 for _ in range(n)]

    def add(self, u, v, custo):
        self.matrix_adj[u][v] = custo
        self.arestas.append((u, v))

    def bellman_ford(self, s):
        self.distancias[s] = 0
        self.predecessores[s] = -1
        for _ in range(self.n - 1):
            for u, v in self.arestas:
                if self.distancias[v] > self.distancias[u] + self.matrix_adj[u][v]:
                    self.distancias[v] = self.distancias[u] + self.matrix_adj[u][v]
                    self.predecessores[v] = u

    def caminho(self, s, t):
        self.bellman_ford(s)
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
g = Grafo(5)
g.add(0, 1, -1)
g.add(0, 2, 4)
g.add(1, 2, 3)
g.add(1, 3, 2)
g.add(1, 4, 2)
g.add(3, 2, 5)
g.add(3, 1, 1)
g.add(4, 3, -3)

print(g.caminho(0, 3))
