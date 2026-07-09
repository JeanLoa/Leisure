import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.datasets import make_blobs

# Generar datos
X, _ = make_blobs(n_samples=300, centers=4, cluster_std=0.6, random_state=42)

# Aplicar K-Means
kmeans = KMeans(n_clusters=4, init='random', n_init=10, random_state=42)
labels = kmeans.fit_predict(X)

# Graficar resultados
plt.scatter(X[:, 0], X[:, 1], c=labels, cmap='viridis', alpha=0.6)
plt.scatter(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1], c='red', marker='x', s=200, label="Centroides")
plt.legend()
plt.title("Clustering con K-Means")
plt.show()
