import Pyro4

def main():
    Pyro4.locateNS("127.0.0.1", 9090)
    calculadora = Pyro4.Proxy("PYRONAME:CalculadoraService")
    
    print("1 + 3 = ", calculadora.soma(1,3))
    print("1 - 3 = ", calculadora.subtrai(1,3))
    print("1 * 3 = ", calculadora.multiplica(1,3))
    print("1 / 3 = ", calculadora.divide(1,3))

if __name__ == "__main__":
    main()