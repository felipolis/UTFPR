def incremento(valor_inicial):
    atual = 0
    def proximo():
        nonlocal atual
        atual += valor_inicial
        return atual
    return proximo

proximo = incremento(2)
print(proximo())
print(proximo())
print(proximo())
print(proximo())
