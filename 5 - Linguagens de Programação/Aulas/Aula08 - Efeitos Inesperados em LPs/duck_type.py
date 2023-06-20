class Carro:

    def __init__(self, name):
        self.name = name
    
    def faz_barulho(self):
        print(f"O {self.name} faz vrummm")

class Caminhão:

    def __init__(self, name):
        self.name = name
    
    def faz_barulho(self):
        print(f"O {self.name} faz vrummm")

def ação(obj):
    obj.faz_barulho()

c1 = Carro("Voyage")
c2 = Caminhão("Volvo")
ação(c1)
ação(c2)