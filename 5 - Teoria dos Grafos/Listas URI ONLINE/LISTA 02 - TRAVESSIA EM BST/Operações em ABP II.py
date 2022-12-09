"""
Marcela nem terminou de fazer o programa anterior e o professor já lhe pediu um novo programa, com aprimoramentos sobre o programa anterior. Este novo programa é a implementação de uma Árvore Binária de Pesquisa (ou Busca) mas utilizando números inteiros agora, e que deve aceitar um comando extra (R) com relação ao programa anterior:

    I n: Insere na árvore binária de pesquisa o elemento n.
    INFIXA: lista os elementos já inseridos segundo o percurso infixo
    PREFIXA: lista os elementos já inseridos segundo o percurso prefixo
    POSFIXA: lista os elementos já inseridos segundo o percurso posfixo
    P n: Pesquisa se o elemento n existe ou não na árvore.
    R n: Remove o elemento n da árvore, caso ele exista.

A qualquer momento pode-se inserir um elemento, visitar os elementos previamente inseridos na ordem infixa, prefixa ou posfixa, procurar por um elemento na árvore para saber se o elemento existe ou não ou ainda retirar um elemento.

Nota: Se um elemento com duas sub-árvores (direita e esquerda) for removido, o antecessor (o elemento maior de sub-árvore esquerda, deve ocupar o seu lugar e ao tentar retirar um elemento que não existe, nenhuma mensagem deve ser apresentada.

Entrada
A entrada contém N operações utilizando números inteiros (1-106) sobre uma árvore binária de Busca, que inicialmente se encontra vazia. A primeira linha de entrada contém a inserção de algum elemento. As demais linhas de entrada podem conter quaiquer um dos comandos descritos acima, conforme exemplo abaixo. O final da entrada é determinado pelo final de arquivo (EOF).

Saída
Cada linha de entrada, com exceção das linhas que contém os comandos "I" ou "R", deve produzir uma linha de saída. A saída deve ser de acordo com o exemplo fornecido abaixo. Não deve haver espaço em branco após o último caractere de cada linha, caso contrário, sua submissão receberá Presentation Error.

Exemplo de Entrada	    Exemplo de Saída
I 5
I 2
I 4
I 1
INFIXA                  1 2 4 5
PREFIXA                 5 2 1 4
POSFIXA                 1 4 2 5
P 3                     3 nao existe
P 1                     1 existe
INFIXA                  1 2 4 5
R 1
INFIXA                  2 4 5

"""

def maiorEsquerda( node):
        if node.right:
            return maiorEsquerda(node.right)
        else:
            return node.data

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
    
    def remove(self, data):
        if self.data:
            if data < self.data:
                if self.left:
                    self.left.remove(data)
            elif data > self.data:
                if self.right:
                    self.right.remove(data)
            elif data == self.data:
                if self.left is None and self.right is None:
                    self.data = None
                elif self.left is None:
                    self.data = self.right.data
                    self.right.remove(self.right.data)
                elif self.right is None:
                    self.data = self.left.data
                    self.left.remove(self.left.data)
                else:
                    self.data = maiorEsquerda(self.left)
                    self.left.remove(self.data)


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
    
    def remove(self, data):
        if self.root:
            self.root.remove(data)
    
    


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
                tree.insert(int(values[1]))
            elif values[0] == 'P':
                tree.search(int(values[1]))
            elif values[0] == 'R':
                tree.remove(int(values[1]))
            else:
                break
        else:
            break
        
        del values[:]
