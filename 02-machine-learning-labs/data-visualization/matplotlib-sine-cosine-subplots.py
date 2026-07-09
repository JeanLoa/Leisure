import matplotlib.pyplot as plt
import numpy as np

fig, axes = plt.subplots(2, 1)

x = np.linspace(-2*np.pi, 2*np.pi, 100)
#Coseno
y_cos = np.cos(x)
axes[0].plot(x, y_cos, 'r--', label='Coseno')
axes[0].annotate('Maximo', xy=(0, 1), xytext=(0,0), arrowprops=dict(arrowstyle='->'))
axes[0].set_title('Grafica de coseno')
axes[0].set_xlabel('X')
axes[0].set_ylabel('Y')
#Seno
y_sin = np.sin(x)
axes[1].plot(x, y_sin, 'b-', label='Seno')
axes[1].annotate('Maximo', xy=(np.pi/2, 1), xytext=(np.pi/2, 0), arrowprops=dict(arrowstyle='->'))
axes[1].set_title('Grafica de seno')
axes[1].set_xlabel('X')
axes[1].set_ylabel('Y')

for ax in axes:
  ax.set_xlim(-2*np.pi, np.pi)
  ax.set_ylim(-1.5, 1.5)
  ax.set_xticks([-2*np.pi, -np.pi, 0, np.pi, 2*np.pi])
  ax.set_xticklabels(['-2π', '-π', '0', 'π', '2π'])
  ax.legend(loc='upper left', fontsize=14)

plt.tight_layout()
plt.show()
