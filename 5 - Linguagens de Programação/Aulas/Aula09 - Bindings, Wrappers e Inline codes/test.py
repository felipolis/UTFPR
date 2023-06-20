# from example import fibo as cfibo

def pyfibo(n):
    if n < 2:
        return n
    return pyfibo(n - 1) + pyfibo(n - 2)

print(pyfibo(45))
# print(cfibo(45))
