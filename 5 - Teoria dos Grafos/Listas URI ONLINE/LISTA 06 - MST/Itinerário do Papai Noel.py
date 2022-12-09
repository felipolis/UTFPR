""" 
beecrowd | 1764
Itinerário do Papai Noel

Antes de Papai Noel começar a fazer as suas viagens de trenó pelo Brasil para entregar os presentes de Natal, ele solicitou que você o ajudasse a desenhar um mapa com todas as cidades que deverá visitar. A regra para desenhar este mapa é a seguinte: a soma de todas rotas (distâncias entre duas cidades) existentes no mapa deve ser a menor possível e deve-se poder chegar em qualquer cidade, independente de onde se esteja partindo. Noel não se importa de passar por uma determinada cidade mais de uma vez, contanto que ele utilize apenas as rotas desenhadas no mapa.

Entrada
A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém dois inteiros, M (2 ≤ M < 40000) e N (1 ≤ N < 50000), que indicam respectivamente a quantidade de cidades e a quantidade de caminhos existentes ligando estas cidades. A entrada é terminada por M = N = 0. Seguem N conjuntos de três valores X (0 ≤ X), Y (Y < M) e Z (1 ≤ Z ≤ 999), especificando que há uma rota bidirecional entre X e Y com distância de Z kilômetros, sendo que X ≠ Ye a soma total de todas as rotas de cada mapa é menor do que 231.

Saída
Para cada caso de teste de entrada, seu programa deverá imprimir um único valor, indicando a soma de todas as distâncias ou rotas existentes no seu mapa.

Exemplo de Entrada	Exemplo de Saída
6 8
0 1 350
1 2 180
0 3 270
3 4 200
4 5 300
1 4 190
3 5 500
2 5 400             1140
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11              39
0 0
"""

# utilizar Disjoint Sets
# MST - Kruskal

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

while True:
    m, n = map(int, input().split())
    if m == n == 0:
        break
    g = Grafo(m)
    for i in range(n):
        u, v, w = map(int, input().split())
        g.addAresta(u, v, w)
    g.Kruskal()
    print(g.soma())
