# Algoritmo de Floyd-Warshall

class Grafo:
    def __init__(self, n):
        self.n = n
        self.distancias = [[float('inf') for _ in range(n)] for _ in range(n)]
        self.predecessores = [[-1 for _ in range(n)] for _ in range(n)]

    def add(self, u, v, custo):
        self.distancias[u][v] = custo
        self.predecessores[u][v] = u

    def floyd_warshall(self):
        for k in range(self.n):
            for i in range(self.n):
                for j in range(self.n):
                    if self.distancias[i][j] > self.distancias[i][k] + self.distancias[k][j]:
                        self.distancias[i][j] = self.distancias[i][k] + self.distancias[k][j]
                        self.predecessores[i][j] = self.predecessores[k][j]

    def caminho(self, s, t):
        self.floyd_warshall()
        if self.distancias[s][t] == float('inf'):
            return -1
        else:
            u = t
            caminho = []
            while u != s:
                caminho.append(u)
                u = self.predecessores[s][u]
            caminho.append(s)
            caminho.reverse()
            return caminho

# Exemplo de uso
g = Grafo(5)
g.add(0, 1, 3)
g.add(0, 2, 8)
g.add(0, 4, -4)
g.add(1, 3, 1)
g.add(1, 4, 7)
g.add(2, 1, 4)
g.add(3, 0, 2)
g.add(3, 2, -5)
g.add(4, 3, 6)
print(g.caminho(0, 3))

