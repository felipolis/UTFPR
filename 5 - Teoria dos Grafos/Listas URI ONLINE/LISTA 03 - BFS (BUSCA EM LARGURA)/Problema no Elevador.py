"""
beecrowd | 3250
Problema no Elevador

Você está a caminho de sua primeira entrevista de emprego como testador de programa e já está atrasado. A entrevista é em um arranha-céu e você está no andar s, onde vê um elevador. Ao entrar no elvator, você aprende que ele possui apenas dois botões, marcados “UP u” e “DOWN d”. Você conclui que o botão UP leva o elevador u andares para cima (se não houver andares suficientes, pressionar o botão UP não faz nada, ou pelo menos é o que você supõe), enquanto o botão DOWN leva você d andares para baixo (ou nenhum se não houver o suficiente). Sabendo que a entrevista é no andar g e que há apenas f andares no prédio, você rapidamente decide escrever um programa que fornece a quantidade de apertos de botão que você precisa para executar. Se você simplesmente não conseguir chegar ao andar correto, seu programa é interrompido com a mensagem “use as escadas”.

Dada a entrada f, s, g, u e d (andares, início, meta, cima, baixo), encontre a sequência mais curta de pressionamentos de botão que você deve pressionar para ir de s para g, em um edifício de f andares, ou a saída “use as escadas” se você não puder ir de s para g pelo elevador fornecido.

Entrada
A entrada consistirá em uma linha, ou seja, f s g u d, onde 1 ≤ s, g ≤ f ≤ 1000000 e 0 ≤ u, d ≤ 1000000. Os pisos são indexados em um, ou seja, se houver 10 andares, s e g estarão em [1, 10].

Saída
Você deve responder com o número mínimo de empurrões que você deve fazer para ir de s para g, ou a saída "use the stairs" se for impossível dada a configuração do elevador.


Exemplo de Entrada	Exemplo de Saída
10 1 10 2 1         6
100 2 1 1 0         use the stairs
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
            print("Vertice: ", i, " Cor: ", self.adj[i].cor, " Pai: ", self.adj[i].pai, " Distancia: ", self.adj[i].dist, " Vizinhos: ", self.adj[i].to)

def main():
    f, s, g, u, d = map(int, input().split())
    grafo = Graph(f+1)
    for i in range(1, f+1):
        if i+u <= f:
            grafo.addEdge(i, i+u)
        if i-d >= 1:
            grafo.addEdge(i, i-d)
    grafo.BFS(s)
    if grafo.adj[g].dist == float("inf"):
        print("use the stairs")
    else:
        print(grafo.adj[g].dist)

if __name__ == "__main__":
    main()
