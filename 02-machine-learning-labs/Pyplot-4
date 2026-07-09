import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-2*np.pi, 2*np.pi, 1000)

y_sin = np.sin(x)
y_cos = np.cos(x)

tan_lim = np.pi/2 - 0.01
x_tan = np.linspace(-tan_lim, tan_lim, 1000)
y_tan = np.tan(x_tan)

fig, axs = plt.subplots(3, figsize=(20,10))

axs[0].plot(x, y_sin, 'r:', label='Seno')
axs[0].set_title('Grafica de Seno')

axs[1].plot(x, y_cos, 'b-', label='Coseno')
axs[1].set_title('Grafica de Coseno')

axs[2].plot(x_tan, y_tan, 'g--', label='Tangente')
axs[2].set_title('Grafica de Tangente')

for ax in axs:
  ax.set_xticks([-2*np.pi, -np.pi, 0, np.pi, 2*np.pi])
  ax.set_xticklabels(['-2π', '-π', '0', 'π', '2π'])
  ax.set_xlim(-2*np.pi, 2*np.pi)
  ax.set_xlabel('X')
  ax.set_ylabel('Y')
  ax.legend()

axs[2].set_xticks([-np.pi, 0, np.pi])
axs[2].set_xticklabels(['-π', '0', 'π'])
axs[2].set_xlim(-np.pi/2, np.pi/2)

plt.tight_layout()
plt.show()
