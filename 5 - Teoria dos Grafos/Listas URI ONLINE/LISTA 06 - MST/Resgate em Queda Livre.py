""" 
beecrowd | 1552
Resgate em Queda Livre

Ó, meu Deus! Um grupo de pessoas está caindo em queda livre! Elas saltaram todas exatamente ao mesmo tempo de vários aviões que estavam exatamente à mesma altura. A intenção era realizar o maior e mais belo salto sincronizado da História. No entanto, o malévolo Loki, para se deleitar com a insignificância humana, sabotara os paraquedas, e agora a única esperança está numa ação conjunta do Homem-Aranha com o Homem-de-Ferro. Como ambos são muito nerds, notaram que as pessoas estavam caindo todas num mesmo plano paralelo ao solo, a despeito da resistência do ar e de outros fatores. Então, bolaram um plano infalível. Primeiro, o aracnídeo unirá todas as pessoas através de cabos de teia entre elas. Uma vez que não haja pessoa que não esteja conectada ao grupo, o playboy poderá eletromagnetizar o grupo todo e, segurando na mão de uma apenas das pessoas do grupo, pousar todas elas em segurança.

Mas não há muito tempo para divagações. O Homem-Aranha precisa agir rápido, o que no caso dele significa gastar o mínimo possível de teia. Para tanto, o Homem-de-Ferro em seu screen projetou numa malha cartesiana o plano em que as pessoas estão, usando o centímetro como unidade de medida, e obteve as coordenadas de cada pessoa na malha. Agora, J.A.R.V.I.S. está computando qual o mínimo necessário de teia de que o Homem-Aranha precisará. Dependendo da resposta, o Homem-de-Ferro não esperará pelo garoto e improvisará alguma outra peripécia.

Entrada
A entrada é constituída por vários casos de teste. A primeira linha de entrada contém um inteiro C que determina a quantidade de casos de teste. Cada caso de teste começa com um inteiro positivo n (n ≤ 500), o qual representa o número de pessoas no grupo. Seguem, então, n linhas, cada uma designando uma pessoa do grupo pelas suas coordenadas x e y na malha (0 ≤ x, y ≤ 104).

Saída
Para cada caso de teste, seu programa deverá imprimir uma linha contendo o valor com precisão de duas casas decimais correspondente ao comprimento mínimo de teia, em metros, necessário para se conectarem todas as pessoas do grupo. Atente para que o separador das casas decimais seja . (ponto), não , (vírgula).

Exemplo de Entrada	Exemplo de Saída
2
5
0 0
0 100
100 200
200 400
300 300             6.06
4
1 5
1 4
2 3
3 2                 0.04
"""

class Vertex:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.custo = float('inf')

class Grafo:
    def __init__(self, n):
        self.n = n
        self.mst = []
        self.custos = []

    def addVertice(self, vertice):
        self.custos.append(vertice)

    def prim(self):
        self.custos[0].custo = 0                                            # custo do primeiro vertice é 0
        self.custos.sort(key=lambda x: x.custo)                             # ordena os custos
        while len(self.mst) < self.n:                                       # enquanto o mst não tiver todos os vertices
            vertice = self.custos.pop(0)                                        # pega o vertice com menor custo
            self.mst.append(vertice)                                            # adiciona o vertice no mst
            for v in self.custos:                                               # para cada vertice no grafo
                if v.custo > self.distancia(vertice, v):                            # se o custo do vertice for maior que a distancia entre o vertice e o vertice do mst
                    v.custo = self.distancia(vertice, v)                                # o custo do vertice é a distancia entre o vertice e o vertice do mst     

    def distancia(self, v1, v2):
        return ((v1.x - v2.x) ** 2 + (v1.y - v2.y) ** 2) ** 0.5

def main():
    casos = int(input())
    for _ in range(casos):
        n = int(input())
        grafo = Grafo(n)
        for _ in range(n):
            x, y = map(int, input().split())
            grafo.addVertice(Vertex(x, y))
        grafo.prim()
        print(f'{sum([v.custo for v in grafo.mst])/100:.2f}')

if __name__ == '__main__':
    main()