"""
Autores:
    - Felipe Archanjo da Cunha Mendes
    - RA: 2252740

Data:
    - 17/05/2022

Descrição:
    - Analisador lexico para uma Maquina de Moore.

"""


# Imports
import sys
import os

# Variaveis
buffer = []

tokens_operadores = {
    '+': 'PLUS',
    '-': 'MINUS',
    '*': 'TIMES',
    '/': 'DIVIDE',
    '=': 'ATTRIBUTION',
    '==': 'EQUALS',
    '!=': 'DIFFERENT',
    '>': 'GREATER',
    '<': 'LESS',
    '>=': 'GREATER_EQUAL',
    '<=': 'LESS_EQUAL',
}

tokens_delimitadores = {
    '(': 'LPAREN',
    ')': 'RPAREN',
    '[': 'LBRACK',
    ']': 'RBRACK',
    '{': 'LBRACE',
    '}': 'RBRACE',
    ';': 'SEMICOLON',
    ',': 'COMMA',
}

tokens_palavras_reservadas = {
    'if': 'IF',
    'else': 'ELSE',
    'while': 'WHILE',
    'int': 'INT',
    'return': 'RETURN',
    'void': 'VOID',
}

abc = "abcdefghijklmnopqrstuvwxyz"
numeros = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

# Funções
def main():
    # Definindo o arquivo de entrada
    if len(sys.argv) > 1:
        f_in = sys.argv[1]
    else:
        print("Digite o nome do arquivo de entrada:")
        f_in = input()

    # Verificando se o arquivo existe
    if not os.path.isfile(f_in):
        print("Arquivo não encontrado!")
        sys.exit()

    # Abrindo o arquivo de entrada
    try:
        file = open(f_in, "r")
    except:
        print("Erro ao abrir o arquivo de entrada!")
        sys.exit()

    # Definindo o arquivo de saida
    if len(sys.argv) > 2:
        f_out = sys.argv[2]
    else:
        f_out = "saida.out"

    # Abrindo o arquivo de saida
    try:
        outfile = open(f_out, "w")
    except:
        print("Erro ao abrir o arquivo de saida!")
        sys.exit()

    # Lendo o arquivo de entrada
    for line in file:
        for i in range(len(line)):

            # Verificando se é espaço em branco
            if line[i] == ' ' or line[i] == '\n' or line[i] == '\t':
                continue

            # Verificando se o caractere é um numero
            if line[i] in numeros:
                if buffer:
                    buffer.append(line[i])
                else:
                    outfile.write("NUMBER\n")

            # Verificando se o caractere é um operador
            elif line[i] in tokens_operadores:
                if buffer:
                    outfile.write("ID\n")
                    buffer.clear()

                outfile.write(tokens_operadores[line[i]] + "\n")

            # Verificando se o caractere é um delimitador
            elif line[i] in tokens_delimitadores:
                if buffer:
                    outfile.write("ID\n")
                    buffer.clear()

                outfile.write(tokens_delimitadores[line[i]] + "\n")

            # Verificando se é um identificador ou palavra reservada
            elif line[i] in abc:
                buffer.append(line[i])

                if "".join(buffer) in tokens_palavras_reservadas:
                    outfile.write(tokens_palavras_reservadas["".join(buffer)] + "\n")
                    buffer.clear()


# Função principal
if __name__ == "__main__":
    main()
    print("Análise finalizada!")
