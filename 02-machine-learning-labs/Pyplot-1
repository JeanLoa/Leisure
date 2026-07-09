import matplotlib.pyplot as plt
import numpy as np
fig, axes = plt.subplots(2, 4, figsize=(12, 6))

x = np.linspace(-10, 10, 4000)
y1 = np.sin(x)
y2 = np.cos(x)
x_limited = np.linspace(-1, 1, 4000)  # Limitar rango para arcsin y arccos
y3 = np.arcsin(x_limited)
y4 = np.arccos(x_limited)
y5 = np.arcsinh(x)
y6 = np.arccosh(np.clip(x, 1, None))  # Limitar dominio de arccosh
y7 = np.sqrt(np.clip(x, 0, None))    # Limitar dominio de sqrt
y8 = np.power(x, 2)

# Gráfica de sin
axes[0, 0].plot(x, y1, label="sin(x)")
axes[0, 0].set_title("sin(x)")
axes[0, 0].set_ylabel("f(x)")
axes[0, 0].set_xlabel("x")
axes[0, 0].legend(loc="upper right")  # Agregar leyenda

# Gráfica de cos
axes[0, 1].plot(x, y2, label="cos(x)")
axes[0, 1].set_title("cos(x)")
axes[0, 1].set_ylabel("f(x)")
axes[0, 1].set_xlabel("x")
axes[0, 1].legend()  # Agregar leyenda

# Gráfica de arcsin
axes[0, 2].plot(x, y3, label="arcsin(x)")
axes[0, 2].set_title("arcsin(x)")
axes[0, 2].set_ylabel("f(x)")
axes[0, 2].set_xlabel("x")
axes[0, 2].legend()  # Agregar leyenda

# Gráfica de arccos
axes[0, 3].plot(x, y4, label="arccos(x)")
axes[0, 3].set_title("arccos(x)")
axes[0, 3].set_ylabel("f(x)")
axes[0, 3].set_xlabel("x")
axes[0, 3].legend()  # Agregar leyenda

# Gráfica de arcsinh
axes[1, 0].plot(x, y5, label="arcsinh(x)")
axes[1, 0].set_title("arcsinh(x)")
axes[1, 0].set_ylabel("f(x)")
axes[1, 0].set_xlabel("x")
axes[1, 0].legend()  # Agregar leyenda

# Gráfica de arccosh
axes[1, 1].plot(x, y6, label="arccosh(x)")
axes[1, 1].set_title("arccosh(x)")
axes[1, 1].set_ylabel("f(x)")
axes[1, 1].set_xlabel("x")
axes[1, 1].legend()  # Agregar leyenda

# Gráfica de raiz cuadrada
axes[1, 2].plot(x, y7, label="sqrt(x)")
axes[1, 2].set_title("sqrt(x)")
axes[1, 2].set_ylabel("f(x)")
axes[1, 2].set_xlabel("x")
axes[1, 2].legend()  # Agregar leyenda

# Gráfica de potencia cuadrada
axes[1, 3].plot(x, y8, label="pow^2(x)")
axes[1, 3].set_title("pow^2(x)")
axes[1, 3].set_ylabel("f(x)")
axes[1, 3].set_xlabel("x")
axes[1, 3].legend()  # Agregar leyenda

plt.tight_layout()
plt.show()
