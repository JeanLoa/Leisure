max = 0

limite = int(input("Ingrese el tamaño del arreglo: "))
lista = []

for i in range (limite):
    elemento = int(input(f"Ingrese el elemento {i+1}: "))
    lista.append(elemento)

for i in range (limite):
    if max < lista[i]:
        max = lista[i]

print(f"El maximo elemento es:", max)
