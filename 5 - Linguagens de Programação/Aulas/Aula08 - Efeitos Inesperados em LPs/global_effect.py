a = 5

def func():
    global a
    a = 15
    return 10

a = a + func()
print(a)