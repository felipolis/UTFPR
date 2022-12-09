""" 
Ordenação topologica com o algoritmo de Kahn
"""

class vertex:
    def __init__(self):
        self.cor = "BRANCO"
        self.grauEntrada = 0
        self.to = []

class graph:
    def __init__(self, n):
        self.n = n
        self.adj = [vertex() for i in range(n)]

    """
    Adiciona uma aresta direcionada que sai do vértice u para o vértice v
    u: inteiro que representa o vértice de origem
    v: inteiro que representa o vértice de destino
    """
    def addEdge(self, u, v):
        self.adj[u].to.append(v)
        self.adj[v].grauEntrada += 1

    """
    Faz a ordenação topológica no grafo
    """
    def topSort(self):
        fila = []
        for i in range(self.n):
            if self.adj[i].grauEntrada == 0:
                fila.append(i)
        while fila:
            u = fila.pop(0)
            print(u, end=" ")
            for v in self.adj[u].to:
                self.adj[v].grauEntrada -= 1
                if self.adj[v].grauEntrada == 0:
                    fila.append(v)
        print()

def main():
    while True:
        n, m = map(int, input().split())
        if n == 0 and m == 0:
            break
        g = graph(n)
        for i in range(m):
            u, v = map(int, input().split())
            g.addEdge(u-1, v-1)
        g.topSort()

if __name__ == "__main__":
    main()