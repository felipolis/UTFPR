import Pyro5.api as pyro

def main():
    ##pyro.locate_ns("127.0.0.1", 9090)
    ##calculadora = pyro.Proxy("PYRONAME:CalculadoraService")
    nameserver = pyro.locate_ns()
    uri = nameserver.lookup("CalculadoraService")
    calculadora = pyro.Proxy(uri)

    print("1 + 3 = ", calculadora.soma(1,3))
    print("1 - 3 = ", calculadora.subtrai(1,3))
    print("1 * 3 = ", calculadora.multiplica(1,3))
    print("1 / 3 = ", calculadora.divide(1,3))

if __name__ == "__main__":
    main()