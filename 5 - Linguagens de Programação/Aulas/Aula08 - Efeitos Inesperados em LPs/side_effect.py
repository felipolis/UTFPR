# transparência referencial
# b = 0

# def func(a):
#     global b
#     b = 20
#     return a * a

# a = 2
# b = 10
# c = 2
# print((func(a) + b) // (func(a) - c))
# temp = func(a)
# print((temp + b) // (temp - c))

# listas de atribuição e troca
# possíveis em Perl, Ruby, Python, Lua ...

x, y = 1, 6
p = [7, 8]
a, b = p
a, b = b, a
print(a, b)