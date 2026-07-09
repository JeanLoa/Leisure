num = int(input("Ingrese un numero: "))
limite = int(input("Ingrese el limite de la tabla de multiplicar: "))

for i in range(1, limite + 1):
    resultado = num * i
    print(f"{num} * {i} = {resultado}")
