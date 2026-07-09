import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

np.random.seed(42)
data = {
    "categoria": np.random.choice(["Electrónica", "Ropa", "Alimentos", "Juguetes", "Hogar"], 100),
    "dia": np.random.choice(["Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"], 100),
}

df = pd.DataFrame(data)

freq_table = pd.crosstab(df["categoria"], df["dia"])

plt.figure(figsize=(8, 5))
sns.heatmap(freq_table, annot=True, cmap="Blues", linewidths=0.5)

plt.title("Frecuencia de Compras por Categoría y Día de la Semana")
plt.show()
