# Analisador lexico com Máquina de Moore
# O programa deve receber como entrada um arquivo com um código fonte em C- pela linha de comando.
# O programa deve gerar um arquivo com o resultado da análise lexica.


import sys
import os
import ply.lex as lex


# Lista de tokens
tokens = (
    'ID',
    'NUM',
    'PLUS',
    'MINUS',
    'TIMES',
    'DIVIDE',
    'LPAREN',
    'RPAREN',
    'LBRACKET',
    'RBRACKET',
    'LBRACE',
    'RBRACE',
    'EQUALS',
    'SEMICOLON',
    'COMMA',
    'IF',
    'ELSE',
    'WHILE',
    'RETURN',
    'INT',
    'VOID'
)


# Definindo os tokens
t_PLUS = r'\+'
t_MINUS = r'-'
t_TIMES = r'\*'
t_DIVIDE = r'/'
t_LPAREN = r'\('
t_RPAREN = r'\)'
t_LBRACKET = r'\['
t_RBRACKET = r'\]'
t_LBRACE = r'\{'
t_RBRACE = r'\}'
t_EQUALS = r'='
t_SEMICOLON = r';'
t_COMMA = r','
t_IF = r'if'
t_ELSE = r'else'
t_WHILE = r'while'
t_RETURN = r'return'
t_INT = r'int'
t_VOID = r'void'


# Definindo os tokens como identificadores
def t_ID(t):
    r'[a-zA-Z_][a-zA-Z_0-9]*'
    t.type = 'ID'
    return t


# Definindo os tokens como numeros
def t_NUM(t):
    r'\d+'
    t.type = 'NUM'
    return t


# Definindo os tokens como comentarios
def t_COMMENT(t):
    r'\#.*'
    pass


# Definindo os tokens como espaços em branco
def t_SPACE(t):
    r'\s+'
    pass


# Definindo os tokens como erros
def t_error(t):
    print("Caractere não reconhecido: '%s'" % t.value[0])
    t.lexer.skip(1)


# Definindo o analisador lexico
lexer = lex.lex()


# Definindo o arquivo de entrada
if len(sys.argv) > 1:
    filename = sys.argv[1]
else:
    print("Digite o nome do arquivo de entrada:")
    filename = input()


# Definindo o arquivo de saida
if len(sys.argv) > 2:
    outname = sys.argv[2]
else:
    outname = filename + ".out"


# Verificando se o arquivo de entrada existe
if not os.path.exists(filename):
    print("Arquivo de entrada não existe!")
    sys.exit(1)


# Verificando se o arquivo de saida existe
if os.path.exists(outname):
    print("Arquivo de saida já existe!")
    sys.exit(1)


# Abrindo o arquivo de entrada
try:
    f = open(filename, "r")
except IOError:
    print("Erro ao abrir o arquivo de entrada!")
    sys.exit(1)


# Abrindo o arquivo de saida
try:
    out = open(outname, "w")
except IOError:
    print("Erro ao abrir o arquivo de saida!")
    sys.exit(1)


# Analisando o arquivo de entrada
for line in f:
    lexer.input(line)
    while True:
        tok = lexer.token()
        if not tok:
            break
        out.write("%s\t%s\n" % (tok.type, tok.value))


# Fechando os arquivos
f.close()
out.close()


# Fim do programa
print("Análise lexica finalizada!")
