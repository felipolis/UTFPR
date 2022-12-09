"""
beecrowd | 2230
Pedágio

Como prêmio pela primeira colocação na Olimpíada Brasileira de Informática, Juquinha e sua família ganharam uma viagem de uma semana à Coréia do Sul. Como o país é deslumbrante, com tradições, cultura, arquitetura e culinária muito diferentes das do Brasil, o pai de Juquinha, o Sr. Juca, decidiu alugar um carro para conhecer melhor o país. As estradas são muito bem cuidadas; todas são de sentido duplo, e duas cidades podem ser ligadas diretamente por mais de uma estrada. No entanto, em todas as estradas paga-se um pedágio de valor fixo (há um pedágio em cada direção, entre duas cidades). Como o Sr. Juca não tem muito dinheiro para gastar, as viagens com o carro devem ser muito bem planejadas.

Escreva um programa que, conhecidas as cidades e estradas existentes no país, e a cidade onde Juquinha e sua família estão, encontre cada cidade (que não a cidade onde eles estão) que possa ser visitada por eles, dada a restrição de que o Sr. Juca deseja pagar no máximo P pedágios (considerando apenas a viagem de ida).

Entrada
A entrada é composta de vários conjuntos de teste. A primeira linha de um conjunto de teste contém quatro números inteiros C (0 ≤ C ≤ 50), E (0 ≤ E ≤ 2500), L (0 ≤ L ≤ C) e P (0 ≤ P ≤ C). Os valores C e E indicam respectivamente o número de cidades e o número de estradas existentes. As cidades são identificadas por inteiros de 1 a C. os valores L e P indicam, respectivamente, a cidade onde a família de Juquinha está no momento e o número máximo de pedágios que o Sr. Juca está disposto a pagar. As E linhas seguintes contêm cada uma a informação de uma estrada, representada por um par de números inteiros positivos X e Y (1 ≤ X,Y ≤ C), indicando que há uma estrada (de sentido duplo) da cidade X para a cidade Y. O final da entrada é indicado por C = E = L = P = 0.

Saída
Para cada conjunto de teste da entrada seu programa deve produzir três linhas na saída. A primeira linha deve conter um identificador do conjunto de teste, no formato “Teste n”, onde n é numerado a partir de 1. Na segunda linha devem aparecer os identificadores das cidades que podem ser alcançadas, em ordem crescente, separados por pelo menos um espaço em branco. A terceira linha deve ser deixada em branco. A grafia mostrada no Exemplo de Saída, abaixo, deve ser seguida rigorosamente.

Exemplo de Entrada	Exemplo de Saída
5 4 2 1             Teste 1
1 2
2 3
3 4
4 5                 1 3
9 12 1 2            Teste 2
2 1
1 5                 2 3 4 5 6
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
    Printar o grafo, com seus vertices, arestas e cores
    """
    def printGraph(self):
        for i in range(self.n):
            print("Vertice: ", i, " Cor: ", self.adj[i].cor, " Pai: ", self.adj[i].pai, " Distancia: ", self.adj[i].dist, " Vizinhos: ", [(v.destino, v.linha) for v in self.adj[i].to])

def main():
    n, m, l, p = map(int, input().split())
    teste = 1
    while n != 0:
        g = Graph(n)
        for i in range(m):
            u, v = map(int, input().split())
            g.addEdge(u-1, v-1)
            g.addEdge(v-1, u-1)
        g.BFS(l-1)
        print("Teste", teste)
        for i in range(n):
            if i != l-1 and g.adj[i].dist <= p:
                if i == n-1:
                    print(i+1)
                else:
                    print(i+1, end=" ")
        print()
        print()        
        teste += 1
        n, m, l, p = map(int, input().split())


if __name__ == "__main__":
    main()
    

