# Algoritmo de prim

class Vertex:
    def __init__(self, index):
        self.usado = False
        self.custo = float('inf')

class Grafo:
    def __init__(self, n):
        self.n = n
        self.matrix_arestas = [[float('inf') for _ in range(n)] for _ in range(n)]
        self.mst = []
        self.custos = [Vertex(i) for i in range(n)]

    def add(self, u, v, custo):
        self.matrix_arestas[u][v] = custo
        self.matrix_arestas[v][u] = custo

    def prim(self, s):
        self.custos[s].custo = 0
        while len(self.mst) < self.n:
            u = self.min()
            self.mst.append(u)
            self.custos[u].usado = True
            for v in range(self.n):
                if self.matrix_arestas[u][v] != float('inf'):
                    if self.custos[v].custo > self.matrix_arestas[u][v] and not self.custos[v].usado:
                        self.custos[v].custo = self.matrix_arestas[u][v]

    def min(self):
        min = float('inf')
        u = -1
        for v in range (self.n):
            if self.custos[v].custo < min and not self.custos[v].usado:
                min = self.custos[v].custo
                u = v
        return u


    def soma(self):
        soma = 0
        for v in self.custos:
            soma += v.custo
        return soma

    



# Exemplo de uso
g = Grafo(5)
g.add(0, 1, 1)
g.add(0, 2, 7)
g.add(1, 2, 5)
g.add(1, 3, 4)
g.add(1, 4, 3)
g.add(2, 4, 6)
g.add(3, 4, 2)

g.prim(0)
print(g.soma())


