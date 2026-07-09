import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import DBSCAN
from sklearn.datasets import make_moons

# Generar datos en forma de luna creciente
X, _ = make_moons(n_samples=300, noise=0.05, random_state=42)

# Aplicar DBSCAN
dbscan = DBSCAN(eps=0.2, min_samples=5)  # Ajusta eps y min_samples según el dataset
labels = dbscan.fit_predict(X)

# Graficar resultados
plt.scatter(X[:, 0], X[:, 1], c=labels, cmap='viridis', alpha=0.6)
plt.title("Clustering con DBSCAN")
plt.xlabel("Eje X")
plt.ylabel("Eje Y")
plt.show()
