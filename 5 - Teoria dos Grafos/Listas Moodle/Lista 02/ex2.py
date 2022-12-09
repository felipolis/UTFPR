""" 
Utilizando a classe criada anteriormente, escreva uma função para imprimir na tela o resultado da Busca em Profundidade em um grafo, a partir de um vértice inicial v, fornecido como  parâmetro

O protótipo da função é DFS(s), onde s é o vértice de origem da DFS

OBS:

(1) é possível e indicado que vc crie funções auxiliares para sua resposta.
(2) selecione os vértices em ordem crescente de valor


#Teste 1
g = Graph(4) 
g.addEdge(0, 1) 
g.addEdge(0, 2) 
g.addEdge(1, 2) 
g.addEdge(2, 0) 
g.addEdge(2, 3) 
g.addEdge(3, 3) 
g.DFS(2) 
Saída: 
2 0 1 3

#Teste 2
g = Graph(13)
g.addEdge(0,1)
g.addEdge(1, 2) 
g.addEdge(1, 3) 
g.addEdge(1, 4) 
g.addEdge(2, 5)
g.addEdge(2, 6) 
g.addEdge(4, 7) 
g.addEdge(4, 8) 
g.addEdge(5, 9) 
g.addEdge(5, 10) 
g.addEdge(7, 11) 
g.addEdge(7, 12)
g.DFS(0) 
Saída:
0 1 2 5 9 10 6 3 4 7 11 12 8

#Teste 3
g = Graph(13)
g.addEdge(0,1)
g.addEdge(1, 2) 
g.addEdge(1, 3) 
g.addEdge(1, 4) 
g.addEdge(2, 5)
g.addEdge(2, 6) 
g.addEdge(4, 7) 
g.addEdge(4, 8) 
g.addEdge(5, 9) 
g.addEdge(5, 10) 
g.addEdge(7, 11) 
g.addEdge(7, 12)
g.DFS(2) 
Saída:
2 5 9 10 6

#Teste 4
g = Graph(9)
g.addEdge(0, 1) 
g.addEdge(0, 3)
g.addEdge(0, 4)
g.addEdge(1, 2)
g.addEdge(1, 4)
g.addEdge(2, 5) 
g.addEdge(3, 4)
g.addEdge(3, 6)
g.addEdge(4, 5)
g.addEdge(4, 7)
g.addEdge(6, 4)
g.addEdge(6, 7)
g.addEdge(7, 5)
g.addEdge(7, 8)
g.DFS(0)
Saída:
0 1 2 5 4 7 8 3 6

#Teste 5
g = Graph(9)
g.addEdge(0, 1) 
g.addEdge(0, 3)
g.addEdge(0, 4)
g.addEdge(1, 2)
g.addEdge(1, 4)
g.addEdge(2, 5) 
g.addEdge(3, 4)
g.addEdge(3, 6)
g.addEdge(4, 5)
g.addEdge(4, 7)
g.addEdge(6, 4)
g.addEdge(6, 7)
g.addEdge(7, 5)
g.addEdge(7, 8)
g.DFS( 2)
Saída:
2 5

"""

from collections import defaultdict

class Vertex:
    def __init__(self):
        self.cor = "BRANCO"
        self.tempo_descoberta = float("inf")
        self.tempo_finalizacao = float("inf")
        self.to = []


class Graph:
    def __init__(self, n):
        self.n = n
        self.adj = [Vertex() for i in range(n)]
        self.time = 0

    def addEdge(self, u, v):
        self.adj[u].to.append(v)

    def printGraph(self):
        for i in range(self.n):
            print(i, end=" ")
            for j in self.adj[i].to:
                print("->", j, end=" ")
            print()

    def DFS(self, s):
        self.time = 0
        for i in range(self.n):
            self.adj[i].cor = "BRANCO"
            self.adj[i].tempo_descoberta = float("inf")
            self.adj[i].tempo_finalizacao = float("inf")
        self.DFS_VISIT(s)

    def DFS_VISIT(self, u):
        self.time += 1
        self.adj[u].tempo_descoberta = self.time
        self.adj[u].cor = "CINZA"
        print(u, end=" ")
        for v in self.adj[u].to:
            if self.adj[v].cor == "BRANCO":
                self.DFS_VISIT(v)
        self.adj[u].cor = "PRETO"
        self.time += 1
        self.adj[u].tempo_finalizacao = self.time

