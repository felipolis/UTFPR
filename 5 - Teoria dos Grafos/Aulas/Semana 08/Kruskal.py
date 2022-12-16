# Algoritmo de Kruskal

class Vertex:
    def __init__(self):
        self.parent = self
        self.rank = 0

class Grafo:
    def __init__(self, n):
        self.n = n
        self.vertices = [Vertex() for i in range(n)]
        self.tabela = []
        self.mst = []

    def addAresta(self, u, v, w):
        self.tabela.append({
            'origem': u,
            'destino': v,
            'peso': w
        })

    def find(self, u):
        if u != u.parent:
            u.parent = self.find(u.parent)
        return u.parent

    def UnionByRank(self, u, v):
        u = self.find(u)
        v = self.find(v)

        if u == v:
            return False

        if u.rank > v.rank:
            v.parent = u
        elif v.rank > u.rank:
            u.parent = v
        else:
            v.parent = u
            u.rank += 1
        return True

    def Kruskal(self):
        self.tabela.sort(key=lambda x: x['peso'])
        for i in self.tabela:
            if self.UnionByRank(self.vertices[i['origem']], self.vertices[i['destino']]):
                self.mst.append(i)
        return self.mst

    def soma(self):
        soma = 0
        for i in self.mst:
            soma += i['peso']
        return soma

# Exemplo de uso
g = Grafo(5)
g.addAresta(0, 1, 1)
g.addAresta(0, 2, 7)
g.addAresta(1, 2, 5)
g.addAresta(1, 3, 4)
g.addAresta(1, 4, 3)
g.addAresta(2, 4, 6)
g.addAresta(3, 4, 2)
print(g.Kruskal())
print(g.soma())
