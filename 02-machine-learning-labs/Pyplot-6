import matplotlib.pyplot as plt
import numpy as np

# Datos
categories = ['Ciencias', 'Ingeniería', 'Humanidades', 'Artes', 'Medicina']
amount1 = [10, 20, 15, 18, 30]
amount2 = [16, 17, 12, 13, 23]
amount3 = [20, 30, 24, 22, 15]

# Ajustar posiciones
x_pos = np.arange(len(categories))

# Ancho de las barras
bar_width = 0.25

# Usar un esquema de colores agradables
colors = ['#ff9999', '#66b3ff', '#99ff99']

# Crear barras apiladas horizontales
plt.bar(x_pos - bar_width, amount1, width=bar_width, color=colors[0], label='Serie 1')
plt.bar(x_pos, amount2, width=bar_width, color=colors[1], label='Serie 2')
plt.bar(x_pos + bar_width, amount3, width=bar_width, color=colors[2], label='Serie 3')

# Etiquetas y título
plt.xticks(x_pos, categories)
plt.xlabel('Cantidad de estudiantes')
plt.title('Distribución apilada de estudiantes por departamentos')

# Añadir leyenda
plt.legend(title="Departamentos")

# Mostrar el gráfico
plt.tight_layout()
plt.show()
