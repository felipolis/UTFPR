import Pyro5.api as pyro
from Calculadora import Calculadora

daemon = pyro.Daemon()                   # executa o Daemon do Pyro4
ns = pyro.locate_ns()                    # localiza o servidor de nomes
uri = daemon.register(Calculadora)       # registra Calculadora como um objeto Pyro
ns.register("CalculadoraService", uri)   # registra o objeto com  um servidor de nomes

print("Objeto registrado.")
daemon.requestLoop()                     # servidor aguardando solicitações
