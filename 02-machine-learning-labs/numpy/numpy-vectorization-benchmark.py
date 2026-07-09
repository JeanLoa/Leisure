import numpy as np
import time

# Con listas de Python
lista1 = list(range(1_000_000))
lista2 = list(range(1_000_000))

start = time.time()
resultado_lista = [x + y for x, y in zip(lista1, lista2)]
end = time.time()
print("Tiempo con listas:", end - start)

# Con NumPy
arr1 = np.array(lista1)
arr2 = np.array(lista2)

start = time.time()
resultado_np = arr1 + arr2
end = time.time()
print("Tiempo con NumPy:", end - start)
