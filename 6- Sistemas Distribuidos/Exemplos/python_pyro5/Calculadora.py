import Pyro5.api as pyro

@pyro.behavior(instance_mode="session")
@pyro.expose
class Calculadora:
    def soma(self, a, b):
        return a + b
    
    def subtrai(self, a, b):
        return a - b
    
    def multiplica (self, a, b):
        return a * b
    
    def divide (self, a, b):
        return a // b
