""" 
beecrowd | 1640
Reservando Hotéis

Uma companhia de transportes frequentemente necessita transportar bens de uma cidade para outra. A companhia de transportes fez um acordo especial com uma rede de hotéis que permite que seus motoristas fiquem hospedados nos hotéis desta rede gratuitamente. Os motoristas podem dirigir apenas 10 horas por dia. A companhia de transportes deseja encontrar uma rota que parte da cidade inicial e termina na cidade de destino tal que o motorista possa sempre passar a noite em um dos hotéis da rede, e que este precise dirigir no máximo 10 horas de um hotel até o próximo, ou até o destino. Naturalmente, o número de dias necessários para a entrega ser realizada também deve ser minimizado.

Entrada
O arquivo de entrada contém diversos casos de teste. Cada caso de teste começa com uma linha contendo um inteiro n, (2 ≤ n ≤ 10000), indicando o número de cidades a serem consideradas durante o planejamento. Por simplicidade, as cidades são numeradas de 1 a n, onde 1 é a cidade inicial, e n é a cidade de destino. A próxima linha contem um inteiro h seguido pelos números c1, c2, ..., ch indicando o número de cidades nas quais os hotéis da rede estão localizados. Você pode assumir que 0 ≤ h ≤ min(n, 100). A terceira linha de cada caso de teste contém um inteiro m(1 ≤ m ≤ 105), que representa o número de estradas a serem consideradas para o planejamento da rota. As m linhas seguintes descrevem as estradas. Cada estrada é descrita por uma linha contendo três inteiros a, b, t(1 ≤ a, b ≤ n e t ≤ 600) onde a, b são duas cidades conectadas pela estrada, e t é o tempo em minutos necessário para o motorista dirigir do final de uma estrada ao outro. A entrada acaba quando n = 0.

Saída
Para cada caso de teste, imprima uma linha contendo o número mínimo de hotéis nos quais a companhia de transportes deve realizar reserva para uma entrega da cidade 1 à cidade n. Se não for possível encontrar uma rota que o motorista tenha de dirigir no máximo 10 horas por dia, imprima -1.

Exemplo de Entrada	Exemplo de Saída
6                   2
3 2 5 3             -1
8
1 2 400
3 2 80
3 4 301
4 5 290
5 6 139
1 3 375
2 5 462
4 6 300
3
0
2
1 2 371
2 3 230
0
"""

import heapq

class Grafo:
    def __init__(self, n):
        self.n = n
        self.adj = [[] for i in range(n)]
        self.peso = [[] for i in range(n)]
        self.hotel = [False for i in range(n)]
        self.dist = [float('inf') for i in range(n)]
        self.ant = [None for i in range(n)]

    def addAresta(self, a, b, t):
        self.adj[a].append(b)
        self.adj[b].append(a)
        self.peso[a].append(t)
        self.peso[b].append(t)

    def addHotel(self, h):
        self.hotel[h] = True

    def dijkstra(self, s):
        self.dist[s] = 0
        self.ant[s] = s
        fila = [(0, s)]
        while fila:
            d, u = heapq.heappop(fila)
            if d > self.dist[u]:
                continue
            for i, v in enumerate(self.adj[u]):
                if self.dist[v] > self.dist[u] + self.peso[u][i]:
                    self.dist[v] = self.dist[u] + self.peso[u][i]
                    self.ant[v] = u
                    heapq.heappush(fila, (self.dist[v], v))

    def caminho(self, s, t):
        self.dijkstra(s)
        if self.dist[t] == float('inf'):
            return -1
        else:
            u = t
            caminho = []
            while u != s:
                caminho.append(u)
                u = self.ant[u]
            caminho.append(s)
            caminho.reverse()
            print(caminho)
            return caminho

    def caminho_hotel(self, s, t):
        caminho = self.caminho(s, t)
        if caminho == -1:
            return -1
        else:
            h = 0
            for i in range(len(caminho) - 1):
                if self.hotel[caminho[i]] == True:
                    h += 1
                if self.dist[caminho[i + 1]] - self.dist[caminho[i]] > 600:
                    h += 1
            if self.hotel[caminho[-1]] == True:
                h += 1
            return h

    def printGraph(self):
        for i in range(self.n):
            print(i, self.adj[i], self.peso[i])


while True:
    n = int(input())                                    # numero de cidades
    if n == 0:
        break
    else:
        g = Grafo(n)                                    # cria grafo com n vertices
        h = list(map(int, input().split()))             # lista de hoteis
        for i in range(1, len(h)):                      # adiciona hoteis ao grafo
            g.addHotel(h[i] - 1)
        m = int(input())                                # numero de estradas
        for i in range(m):                              # adiciona estradas ao grafo
            a, b, t = map(int, input().split())
            g.addAresta(a - 1, b - 1, t)
        print(g.caminho_hotel(0, n - 1))
        # g.printGraph()

