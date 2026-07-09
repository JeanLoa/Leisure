import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import MeanShift, estimate_bandwidth

# Generamos datos completamente aleatorios (distribución uniforme)
X = np.random.rand(300, 2) * 10  # Datos en el rango [0,10] en ambas coordenadas

# Estimamos h adaptativo
bandwidth = estimate_bandwidth(X, quantile=0.2, n_samples=100)

# Aplicamos Mean-Shift
ms = MeanShift(bandwidth=bandwidth)
ms.fit(X)

# Obtenemos resultados
labels = ms.labels_
cluster_centers = ms.cluster_centers_

# Graficamos
plt.scatter(X[:, 0], X[:, 1], c=labels, cmap='viridis', alpha=0.6)
plt.scatter(cluster_centers[:, 0], cluster_centers[:, 1], c='red', marker='x', s=200, label="Centroides")
plt.title("Mean-Shift con datos aleatorios")
plt.legend()
plt.show()
