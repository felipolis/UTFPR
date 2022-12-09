""" 
beecrowd | 1610
Dudu Faz Serviço

Dudu precisa de um documento para finalizar uma tarefa em seu trabalho. Após pesquisar um pouco, ele descobre que este documento depende de outros documentos que, por sua vez, necessitam de outros documentos e assim por diante.

Dudu chegou a uma lista final com todos os documentos que deverá precisar. Com essa lista em mãos, ele suspeita que a mesma possui loops. Por exemplo, se um documento A depende do documento B que por sua vez depende do documento A, tornaria a tarefa interminável. Veja que neste caso o loop tem apenas dois documentos, pode haver loops com três ou mais!

Dada a lista das dependências entre os documentos, ajude Dudu a saber se um dia conseguirá todos os documentos, ou seja, se não existe um loop na lista.

Entrada
Na primeira linha você terá um inteiro T (T = 100) indicando o número de casos de teste.

Na primeira linha de cada caso teremos os números inteiros N (2 ≤ N ≤ 100* ou 2 ≤ N ≤ 104**) e M (1 ≤ M ≤ 300* ou 1 ≤ M ≤ 3*104​**), indicando o número de documentos e as dependências existentes. Em cada uma das M linhas seguintes, terão dois inteiros A (1 ≤ A) e B (B ≤ N, com A != B), indicando que o documento A depende do documento B. Pode haver dependências repetidas!

*Ocorre em aproximadamente 90% dos casos de teste;

**Ocorre nos demais casos de teste.

Saída
Para cada caso, imprima SIM caso exista pelo menos um loop e NAO caso contrário.


Exemplo de Entrada	Exemplo de Saída
3
2 1
1 2                 NÃO
2 2
1 2
2 1                 SIM
4 4
2 3
3 4
4 2
1 3                 SIM

Usar algoritmo de kahn
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
    Verifica se o grafo possui um ciclo
    """
    def hasCycle(self):
        fila = []
        for i in range(self.n):
            if self.adj[i].grauEntrada == 0:
                fila.append(i)
        while fila:
            u = fila.pop(0)
            for v in self.adj[u].to:
                self.adj[v].grauEntrada -= 1
                if self.adj[v].grauEntrada == 0:
                    fila.append(v)
        for i in range(self.n):
            if self.adj[i].grauEntrada > 0:
                return True
        return False

def main():
    t = int(input())
    for i in range(t):
        n, m = map(int, input().split())
        g = graph(n)
        for j in range(m):
            u, v = map(int, input().split())
            g.addEdge(u-1, v-1)
        if g.hasCycle():
            print("SIM")
        else:
            print("NAO")

if __name__ == "__main__":
    main()
    