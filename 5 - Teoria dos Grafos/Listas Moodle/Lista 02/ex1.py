""" 
Utilize a classe base para grafos e insira um método para imprimir na tela o resultado da Busca em Largura em um grafo, a partir de um vértice v, fornecido como parâmetro.

O protótipo da função é BFS(s), onde

- s é o vértice de origem da BFS

#Teste 1
g = Graph(4)
g.addEdge(0, 1) 
g.addEdge(0, 2) 
g.addEdge(1, 2) 
g.addEdge(2, 0) 
g.addEdge(2, 3) 
g.addEdge(3, 3) 
g.BFS(2)
Saída:
2 0 3 1

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
g.BFS(0) 
Saída:
0 1 2 3 4 5 6 7 8 9 10 11 12

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
g.BFS(5)  
Saída:
5 9 10

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
g.BFS(0)
Saída:
0 1 3 4 2 6 5 7 8

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
g.BFS(2)
Saída:
2 5

"""

from collections import defaultdict

# Classe base para grafos
class Graph:
    # Construtor
    def __init__(self,vertices):
        self.V= vertices # Número de vértices
        self.graph = defaultdict(list) # Dicionário de listas de adjacências

    # Função para adicionar uma aresta ao grafo
    def addEdge(self,u,v):
        self.graph[u].append(v)

    # Função para imprimir o grafo
    def printGraph(self):
        for i in range(self.V):
            print(i, ":", self.graph[i])

    # Função para imprimir o resultado da BFS
    def BFS(self, s):
        # Inicializa a fila
        queue = []
        # Marca todos os vértices como não visitados
        visited = [False] * (self.V)
        # Marca o vértice de origem como visitado e o insere na fila
        queue.append(s)
        visited[s] = True
        # Enquanto a fila não estiver vazia
        while queue:
            # Remove um vértice da fila
            s = queue.pop(0)
            # Imprime o vértice
            print(s, end=" ")
            # Para cada vértice adjacente a s
            for i in self.graph[s]:
                # Se o vértice não foi visitado
                if visited[i] == False:
                    # Marca o vértice como visitado e o insere na fila
                    queue.append(i)
                    visited[i] = True
