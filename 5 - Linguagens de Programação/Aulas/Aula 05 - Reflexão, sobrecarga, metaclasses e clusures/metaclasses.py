class Meta(type):

    def __new__(self, name, bases, dct):
        x = super().__new__(self, name, bases, dct)
        x.attr = 2022
        return x

class Nova(metaclass=Meta):
    pass

print(Nova.attr)