import Pyro4

@Pyro4.expose
class Calculadora:
    def soma(self, a, b):
        return a + b
    
    def subtrai(self, a, b):
        return a - b
    
    def multiplica (self, a, b):
        return a * b
    
    def divide (self, a, b):
        return a // b
