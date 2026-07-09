from sklearn.cluster import MiniBatchKMeans

# Aplicar Mini-Batch K-Means
mini_kmeans = MiniBatchKMeans(n_clusters=4, batch_size=20, random_state=42)
labels_mini = mini_kmeans.fit_predict(X)

# Graficar resultados
plt.scatter(X[:, 0], X[:, 1], c=labels_mini, cmap='viridis', alpha=0.6)
plt.scatter(mini_kmeans.cluster_centers_[:, 0], mini_kmeans.cluster_centers_[:, 1], c='red', marker='x', s=200, label="Centroides")
plt.legend()
plt.title("Clustering con Mini-Batch K-Means")
plt.show()
