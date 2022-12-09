"""
beecrowd | 1081
DFSr - Hierarquia de Profundidade

A rotina PathR é bem conhecida em grafos. É também chamada de dfs ou dfsr. Trata-se de uma busca em profundidade dos nodos do grafo, utilizando backtracking. A tarefa aqui é, dado o grafo de entrada, simplesmente gerar o desenho da hierarquia dos nodos pesquisados.

Entrada
A entrada será um arquivo contendo vários casos de teste. A primeira linha do arquivo de entrada contém um inteiro N que indica a quantidade de casos de teste que vem a seguir. Cada um dos N casos de teste contém, na primeira linha, duas informações: V (1 ≤ V ≤ 20) e E (1 ≤ E ≤ 20) que são, respectivamente, a quantidade de Vértices e de Arestas (Edges) do grafo. Seguem  E linhas contendo informações sobre cada uma das arestas do grafo.

Saída
Para cada caso de entrada, deve ser apresentada uma saída que representa a busca em profundidade de todos os nodos,  respeitando a hierarquia e profundidade de cada um deles. O símbolo b  representam um espaço em branco. Veja o exemplo abaixo para ilustrar:
bb0-2 pathR(G,2)
bbbb2-1 pathR(G,1)
bbbb2-4 pathR(G,4)
bbbbbb4-1

E assim sucessivamente...
Obs.: Há uma linha em branco depois de cada segmento impresso do grafo, inclusive após o último segmento.
Obs. Usar DFS

Exemplo de Entrada  Exemplo de Saída
2       
12 9                Caso 1:
0 1                   0-1 pathR(G,1)
1 5                     1-5 pathR(G,5)
5 6                       5-6 pathR(G,6)
0 4                     1-7 pathR(G,7)
4 2                       7-8 pathR(G,8)
2 3                   0-4 pathR(G,4)
7 8                     4-2 pathR(G,2)
1 7                   10-11 pathR(G,11)
10 11                     2-3 pathR(G,3)
11 8                Caso 2:
0 1                   0-1 pathR(G,1)
1 2                     1-2 pathR(G,2)
3 4                   3-4 pathR(G,4)
4 3                     4-3
5 6                   5-6 pathR(G,6)
6 8                     6-8 pathR(G,8)
7 9                   7-9 pathR(G,9)
9 10                    9-10 pathR(G,10)

"""

class Vertex:
    def __init__(self):
        self.cor = "BRANCO"
        self.tempoDescoberta = 0
        self.tempoTermino = 0
        self.contadorEspaco = 0
        self.to = []

class Graph:
    def __init__(self, n):
        self.n = n
        self.adj = [Vertex() for i in range(n)]
        self.tempo = 0

    def addEdge(self, u, v):
        self.adj[u].to.append(v)

    def dfs(self, u):
        self.tempo += 1
        self.adj[u].tempoDescoberta = self.tempo
        self.adj[u].cor = "CINZA"
        continua = False
        for v in self.adj[u].to:
            if self.adj[v].cor == "BRANCO":
                self.adj[v].contadorEspaco = self.adj[u].contadorEspaco + 1
                print(" " * self.adj[v].contadorEspaco, end="")
                print(f"{u}-{v} pathR(G,{v})")
                self.dfs(v)
            elif self.adj[v].cor == "CINZA":
                self.adj[v].contadorEspaco = self.adj[u].contadorEspaco + 1
                print(" " * self.adj[v].contadorEspaco, end="")
                print(f"{u}-{v}")

        self.adj[u].cor = "PRETO"
        self.tempo += 1
        self.adj[u].tempoTermino = self.tempo

    def dfsr(self, index):
        print(f"Caso {index+1}:")
        for u in range(self.n):
            if self.adj[u].cor == "BRANCO":
                self.adj[u].contadorEspaco = 0
                self.dfs(u)

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        v, e = map(int, input().split())
        g = Graph(v)
        for j in range(e):
            u, v = map(int, input().split())
            g.addEdge(u, v)
        g.dfsr(i)
        print()

