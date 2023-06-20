func a = a * a

main = do
    let a = 2; b = 10; c = 2 in print((func a + b) / (func a - c))
    let temp = func 2; b = 10; c = 2 in print((temp + b) / (temp - c))