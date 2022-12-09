"""
beecrowd | 1128
Ir e Vir

Numa certa cidade há N intersecções ligadas por ruas de mão única e ruas com mão dupla de direcão. É uma cidade moderna, de forma que muitas ruas atravessam túneis ou têm viadutos. Evidentemente é necessário que se possa viajar entre quaisquer duas intersecções, isto é, dadas duas intersecções V e W, deve ser possível viajar de V para W e de W para V.

Sua tarefa é escrever um programa que leia a descrição do sistema de tráfego de uma cidade e determine se o requisito de conexidade é satisfeito ou não.

Entrada
A entrada contém vários casos de teste. A primeira linha de um caso de teste contém dois números inteiros N e M, separados por um espaço em branco, indicando respectivamente o número de intersecções (2 ≤ N ≤ 2000) e o número de ruas (2 ≤ M ≤ N(N-1)/2). O caso de teste tem ainda mais M linhas, que contêm, cada uma, uma descrição de cada uma das M ruas. A descrição consiste de três inteiros V, W e P, separados por um espaço em branco, onde V e W são identificadores distintos de intersecções (1 ≤ V, W ≤ N , V ≠ W ) e P pode ser 1 ou 2; se P = 1 então a rua é de mão única, e vai de V para W; se P = 2 então a rua é de mão dupla, liga V e W. Não existe duas ruas ligando as mesmas intersecções.

O ultimo caso de teste é seguido por uma linha que contém apenas dois números zero separados por um espaço em branco.

Saída
Para cada caso de teste seu programa deve imprimir uma linha contendo um inteiro G, onde G é igual a 1 se o requisito de conexidade está satisfeito, ou G é igual a 0, caso contrário.


Exemplo de Entrada	Exemplo de Saída
4 5
1 2 1
1 3 2
2 4 1
3 4 1
4 1 2               1
3 2
1 2 2
1 3 2               1
3 2
1 2 2
1 3 1               0
4 2
1 2 2
3 4 2               0
0 0
"""

class Vertex:
    def __init__(self):
        self.cor = "BRANCO"
        self.pai = None
        self.dist = float("inf")
        self.to = []


class Graph:
    def __init__(self, n):
        self.n = n
        self.adj = [Vertex() for i in range(n)]

    """
    Adiciona uma aresta direcionada que sai do vértice u para o vértice v com peso w
    u: inteiro que representa o vértice de origem
    v: inteiro que representa o vértice de destino
    w: inteiro que representa o peso da aresta (opcional)
    """
    def addEdge(self, u, v):
        self.adj[u].to.append(v)

    """
    Faz a busca em largura no grafo a partir do vértice s
    s: inteiro que representa o vértice de origem
    """
    def BFS(self, s):
        self.adj[s].cor = "CINZA"
        self.adj[s].dist = 0
        self.adj[s].pai = None
        fila = [s]
        while fila:
            u = fila.pop(0)
            for v in self.adj[u].to:
                if self.adj[v].cor == "BRANCO":
                    self.adj[v].cor = "CINZA"
                    self.adj[v].dist = self.adj[u].dist + 1
                    self.adj[v].pai = u
                    fila.append(v)
            self.adj[u].cor = "PRETO"
    
    """
    Verifica se o grafo é conexo
    """
    def isConexo(self):
        for i in range(self.n):
            self.BFS(i)
            for j in range(self.n):
                if self.adj[j].cor == "BRANCO" or self.adj[j].cor == "CINZA":
                    return False
            self.reset()
        return True
    
    """
    Reseta o grafo
    """
    def reset(self):
        for i in range(self.n):
            self.adj[i].cor = "BRANCO"
            self.adj[i].pai = None
            self.adj[i].dist = float("inf")
    
    """
    Printar o grafo, com seus vertices, arestas e cores
    """
    def printGraph(self):
        for i in range(self.n):
            print("Vertice: ", i, " Cor: ", self.adj[i].cor, " Pai: ", self.adj[i].pai, " Distancia: ", self.adj[i].dist, " Vizinhos: ", self.adj[i].to)



if __name__ == '__main__':
    while True:
        n, m = map(int, input().split())
        if n == 0 and m == 0:
            break
        g = Graph(n)
        for i in range(m):
            u, v, p = map(int, input().split())
            g.addEdge(u-1, v-1)
            if p == 2:
                g.addEdge(v-1, u-1)
        if g.isConexo():
            print(1)
        else:
            print(0)
