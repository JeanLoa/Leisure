import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-2*np.pi, 2*np.pi, 1000)

y_sin = np.sin(x)
y_cos = np.cos(x)
y_tan = np.tan(x)

plt.figure(figsize=(20,10))

plt.plot(x, y_sin, label='Seno', color='red', linestyle='-', linewidth=2)
plt.plot(x, y_cos, label='Coseno', color='blue', linestyle='--', linewidth=2)
plt.plot(x, y_tan, label='Tangente', color='green', linestyle=':', linewidth=2)

plt.axhline(0, color='black', linewidth=1)
plt.axvline(0, color='black', linewidth=1)

plt.xlim(-2*np.pi, 2*np.pi)
plt.ylim(-10, 10)

plt.title('Graficas de seno, coseno y tangente')
plt.xlabel('X')
plt.ylabel('Y')

plt.xticks([-2*np.pi, -np.pi, 0, np.pi, 2*np.pi], ['-2π', '-π', '0', 'π', '2π'])

plt.legend(loc='upper right')

plt.grid(True)
plt.tight_layout()
plt.show()
