""" 
Marcela recebeu como trabalho de Algoritmos a tarefa de fazer um programa que implemente uma Árvore Binária de Pesquisa (ou Busca). O Programa deve aceitar os seguintes comandos:

    I n: Insere na árvore binária de pesquisa o elemento n.
    INFIXA: lista os elementos já cadastrado segundo o percurso infixo
    PREFIXA: lista os elementos já cadastrado segundo o percurso prefixo
    POSFIXA: lista os elementos já cadastrado segundo o percurso posfixo
    P n: pesquisa se o elemento n existe ou não.

A qualquer momento pode-se inserir um elemento, visitar os elementos previamente inseridos na ordem infixa, prefixa ou posfixa ou ainda procurar por um elemento na árvore para saber se o elemento existe ou não.

Entrada
A entrada contém N operações utilizando letras (A-Z,a-z) sobre uma árvore binária de Busca, que inicialmente se encontra vazia. A primeira linha de entrada contém a inserção de algum elemento. As demais linhas de entrada podem conter quaiquer um dos comandos descritos acima, conforme exemplo abaixo. O final da entrada é determinado pelo final de arquivo (EOF).

Obs: Considere que não serão inseridos elementos repetidos na árvore.

Saída
Cada linha de entrada, com exceção das linhas que contém o comando "I", deve produzir uma linha de saída. A saída deve ser de acordo com o exemplo fornecido abaixo. Não deve haver espaço em branco após o último caractere de cada linha, caso contrário, sua submissão receberá Presentation Error.


Exemplo de Entrada	    Exemplo de Saída
I c
I f
I a
I h
INFIXA                  a c f h
PREFIXA                 c a f h
POSFIXA                 c f a h
P z                     z nao existe
P h                     h existe
I g 
INFIXA                  a c f g h

"""

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def insert(self, data):
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
        else:
            self.data = data

    def infix(self):
        if self.left:
            self.left.infix()
        if self.data:
            print(self.data, end=' ')
        if self.right:
            self.right.infix()

    def prefix(self):
        if self.data:
            print(self.data, end=' ')
        if self.left:
            self.left.prefix()
        if self.right:
            self.right.prefix()

    def posfix(self):
        if self.left:
            self.left.posfix()
        if self.right:
            self.right.posfix()
        if self.data:
            print(self.data, end=' ')

    def search(self, data):
        if self.data:
            if data < self.data:
                if self.left is None:
                    print(data, 'nao existe')
                else:
                    self.left.search(data)
            elif data > self.data:
                if self.right is None:
                    print(data, 'nao existe')
                else:
                    self.right.search(data)
            else:
                print(data, 'existe')


class Tree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self.root.insert(data)

    def infix(self):
        if self.root:
            self.root.infix()

    def prefix(self):
        if self.root:
            self.root.prefix()

    def posfix(self):
        if self.root:
            self.root.posfix()

    def search(self, data):
        if self.root:
            self.root.search(data)
        else:
            print(data, 'nao existe')


if __name__ == '__main__':
    tree = Tree()
    
    while True:
        
        try:
            values = input().split()
        except EOFError:
            print(end='')


        if len(values) == 1:
            if values[0] == 'INFIXA':
                tree.infix()
                print()
            elif values[0] == 'PREFIXA':
                tree.prefix()
                print()
            elif values[0] == 'POSFIXA':
                tree.posfix()
                print()
            else:
                break
        elif len(values) == 2:
            if values[0] == 'I':
                tree.insert(values[1])
            elif values[0] == 'P':
                tree.search(values[1])
            else:
                break
        else:
            break
        
        del values[:]
