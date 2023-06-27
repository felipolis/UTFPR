# Analisador lexico com Máquina de Moore
# O programa deve receber como entrada um arquivo com um código fonte em C- pela linha de comando.
# Varrer caractere a caractere do arquivo de entrada.
# O programa deve gerar um arquivo com o resultado da análise lexica.
# Utilizar apenas bibliotecas padrão do Python.
# Não utilizar a função strip() ou split().


import sys
import re
import os


buffer = []


def main():
    # Definindo o arquivo de entrada
    if len(sys.argv) > 1:
        filename = sys.argv[1]
    else:
        print("Digite o nome do arquivo de entrada:")
        filename = input()

    # Verificando se o arquivo existe
    if not os.path.isfile(filename):
        print("Arquivo não encontrado!")
        sys.exit()

    # Abrindo o arquivo de entrada
    try:
        file = open(filename, "r")
    except:
        print("Erro ao abrir o arquivo de entrada!")
        sys.exit()

    # Definindo o arquivo de saida
    if len(sys.argv) > 2:
        out = sys.argv[2]
    else:
        out = filename + ".out"

    # Abrindo o arquivo de saida
    try:
        outfile = open(out, "w")
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
            if re.match(r'[0-9]', line[i]):
                outfile.write("NUMBER " + line[i] + "\n")

            # Verificando se o caractere é um operador
            elif re.match(r'[+-/*]', line[i]):
                if buffer:
                    outfile.write("ID " + "".join(buffer) + "\n")
                    buffer.clear()

                if line[i] == '+':
                    outfile.write("PLUS " + line[i] + "\n")
                elif line[i] == '-':
                    outfile.write("MINUS " + line[i] + "\n")
                elif line[i] == '*':
                    outfile.write("TIMES " + line[i] + "\n")
                elif line[i] == '/':
                    outfile.write("DIVIDE " + line[i] + "\n")

            # Verificando se o caractere é um delimitador
            elif re.match(r'[\(\)\[\]\{\}\;]', line[i]):
                if buffer:
                    outfile.write("ID " + "".join(buffer) + "\n")
                    buffer.clear()

                if line[i] == '(':
                    outfile.write("LPAREN " + line[i] + "\n")
                elif line[i] == ')':
                    outfile.write("RPAREN " + line[i] + "\n")
                elif line[i] == '[':
                    outfile.write("LBRACK " + line[i] + "\n")
                elif line[i] == ']':
                    outfile.write("RBRACK " + line[i] + "\n")
                elif line[i] == '{':
                    outfile.write("LBRACE " + line[i] + "\n")
                elif line[i] == '}':
                    outfile.write("RBRACE " + line[i] + "\n")
                elif line[i] == ';':
                    outfile.write("SEMICOLON " + line[i] + "\n")
                elif line[i] == ',':
                    outfile.write("COMMA " + line[i] + "\n")

            # Verificando se o caractere é um identificador ou palavra reservada
            elif re.match(r'[a-zA-Z]', line[i]):
                buffer.append(line[i])
                print(buffer)

                if "".join(buffer) == "if":
                    outfile.write("IF " + "if" + "\n")
                    buffer.clear()

                elif "".join(buffer) == "else":
                    outfile.write("ELSE " + "else" + "\n")
                    buffer.clear()

                elif "".join(buffer) == "int":
                    outfile.write("INT " + "int" + "\n")
                    buffer.clear()

                elif "".join(buffer) == "return":
                    outfile.write("RETURN " + "return" + "\n")
                    buffer.clear()

                elif "".join(buffer) == "while":
                    outfile.write("WHILE " + "while" + "\n")
                    buffer.clear()

                elif "".join(buffer) == "void":
                    outfile.write("VOID " + "void" + "\n")
                    buffer.clear()


if __name__ == '__main__':
    main()
