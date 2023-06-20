def antes_decora(func):
    def inner(*args, **kwargs):
        print("primeira a executar 'antes decora'")
        res = func(*args, **kwargs)
        return res
    return inner

def decora(func):
    def inner(*args, **kwargs):
        print("Antes da execução")
        resultado = func(*args, **kwargs)
        print("Depois da execução")
        return resultado
    return inner

@antes_decora
@decora
def soma(a, b):
    print("Função principal de soma")
    return a + b

a, b = 30, 20
print(f"Soma = {soma(a, b)}")