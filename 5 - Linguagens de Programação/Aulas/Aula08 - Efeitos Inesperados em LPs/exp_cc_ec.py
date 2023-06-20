def funcao1():
    print("Executando função 1")
    return False

def funcao2():
    print("Executando função 2")
    return True

if funcao1() and funcao2():
    print("Expressão verdadeira")
else:
    print("Expressão falsa")