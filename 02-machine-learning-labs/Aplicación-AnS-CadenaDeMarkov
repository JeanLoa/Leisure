import pandas as pd # Para la creación del DataFrame
import numpy as np # Para manejo de datos nulos y creación de arrays

from sklearn.preprocessing import MinMaxScaler # Para la limpieza de datos
import matplotlib.pyplot as plt # Para la visualización de los datos
from matplotlib.ticker import MultipleLocator, FuncFormatter # Para el manejo del paso numérico en el eje Y y el formateo del eje para mostrarlos en porcentajes aplicando funciones lambda.

from sklearn.manifold import TSNE # Para la reducción de dimensiones

data = {
          'Gemini 2.5 Pro Experimental' : [66, np.nan, 94, 86, 83, 17.7, 39, 97],

          'o3-mini (high)' :              [66, 57, 92, 80, 77, 12.3, 40, np.nan],

          'QwQ-32B' :                     [58, 49, 87, 76, 59, 8.2, 36, 98],

          'DeepSeek R1' :                 [60, 49, 82, 84, 71, 9.3, 36, 98],

          'Claude 3.7 Sonnet Thinking' :  [57, 44, 72, 84, 77, 10.3, 40, 98],

          'Gemini 2.0 Flash' :            [48, 32, 63, 78, 62, 5.3, 31.5, 90],

          'GPT-4o (March 2025)' :         [50, 40, 61, 80, 66, 5, 37, 96],

          'DeepSeek V3 (Dec 24)' :        [46, 36, 57, 75, 56, 3.6, 35, 91],

          'Gemma 3 27B' :                 [38, 17, 57, 67, 43, 4.7, 21, 89],

          'Claude 3.7 Sonnet' :           [57, 44, 72, 84, 77, 10.3, 40, 98],

          'Llama 3.3 70B' :               [41, 27, 54, 71, 50, 4, 26, 86],

          'Command A' :                   [40, 28, 46, 71, 53, 4.6, 28, 82],

          'GPT-4o mini' :                 [36, 23, 45, 65, 43, 4, 23, 88],

          'Nova Pro' :                    [28, 12, 39, 53, 36, 3.4, 9, 80],

          'Mistral Large 2 (Nov 24)' :    [38, 29, 42, 70, 49, 4, 29, 90],

          'Mistral Small 3.1' :           [35, 24, 40, 66, 45, 4.8, 27, 86],

          'Nova Micro' :                  [28, 12, 39, 53, 36, 4.7, 9, 80],
};

IA_pref = pd.DataFrame(data) # Creación del DataFrame

IA_pref = IA_pref.T # Trasposición para que las columnas sean los índices y los valores de columnas sean de cada índice

# Asignamos las columnas
IA_pref.columns = [
    'Análisis Inteligente', 'Análisis de Código', 'Análisis Matemático',
    'Razonamiento 1', 'Razonamiento 2', 'Razonamiento 3',
    'Codificación 1', 'Codificación 2'
]

# Rellenamos los datos nulos con los promedios de cada columna
IA_pref = IA_pref.apply(lambda x: x.fillna(x.mean(axis=0)))
# Mostramos el DataFrame crudo
IA_pref

scaler = MinMaxScaler() # Normalizamos por columnas (predeterminadamente primer axis, en este caso las filas)

IA_pref_normalized = pd.DataFrame(scaler.fit_transform(IA_pref), columns = IA_pref.columns, index=IA_pref.index) # Creamos el DataFrame con la escala dentro de la función

IA_pref_normalized.index.name = 'Modelo de IA' # Título de los índices

# Definición del modelo - n_components, componentes de salida por muestra - perplexity, equilibrio de varianza respecto a los datos - random_state, estado aleatorio definido
tsne = TSNE(n_components=3, perplexity=4, random_state=42)

# Generamos la nueva matriz reducida con TSNE
IA_transformed = tsne.fit_transform(IA_pref_normalized)

# Escalamos nuevamente por problemas de exactitud
scaler.fit_transform(IA_transformed)

# Creamos el nuevo DataFrame a partir de la transformación
IA_transformed = pd.DataFrame(IA_transformed, dtype=np.float64)

def MatrizDeTransicion(df): # Recibe el DataFrame
  n = df.shape[0] # Obtenemos la dimensión el primer eje (las filas)
  new_df = np.zeros((n, n), dtype='float64') # Creamos la matriz de salida (vacía por ahora)

  for j in range (df.shape[1]): # Recorremos las columnas (selector)
    for i in range (n): # Recorremos las filas (selector)
      for k in range (n): # Recorremos las filas de la columna (comparador)

        if i != k:
          # Para cada par de caracteristicas j de la fila i y k calculamos la diferencia absoluta
          diferencia = abs(df.iloc[i, j] - df.iloc[k, j])
          # Actualizamos con ^1/3 para suavizar el impacto de las distancias
          diferencia = np.pow(diferencia, 1/3)
          # Calculamos la ponderación con la función 1 / 1 + x (suave), con un factor de amplitud de 2 para que la función no considere distancias cercanas y lejanas de manera similar
          new_df[i, k] = (1/(1 + diferencia)) * 2
          # Esto hace que las distancias grandes tengan menos peso y las pequeñas, mas

  # Para calcular la diagonal de la matriz, aproximamos respecto al máximo de la columna y lo multiplicamos por 1.4 (aumentamos 40%), debido a la predominancia de que un evento (como estado), sea probable de volver a ocurrir
  np.fill_diagonal(new_df, new_df.max(axis=0) * 1.4)

  # Escalar por fila (cada fila debe sumar 1)
  row_sums = new_df.sum(axis=1, keepdims=True)
  # Divide cada fila por la suma de su fila
  new_df /= row_sums

  return new_df # Retornamos la matriz de transición

transicion = MatrizDeTransicion(IA_transformed) # Generamos la matriz de transición a partir de nuestro DataFrame reducido

def CadenaDeMarkov(transicion, estado, iter, iter_pron = 10000): # Argumentamos con la matriz de transición, el estado inicial, el número de épocas (iteraciones) y las iteraciones para el pronóstico (predeterminadamente en 10000)
  if (transicion.shape[0] != estado.shape[0]): return # Si el vector no coincide con las dimensiones de la matriz, retornamos de la función
  # Asignamos los 2 estados futuros
  estado_nuevo = estado
  estado_pron = estado
  # Generamos el estado nuevo pedido en las iteraciones argumentadas
  for i in range (iter):
    estado_nuevo = np.dot(estado_nuevo, transicion)
  # Generamos el estado pronosticado en las iteraciones de pronóstico (número alto para convergencia)
  for i in range (iter_pron):
    estado_pron = np.dot(estado_pron, transicion)
  # Retornamos el par de estados
  return estado_nuevo, estado_pron

# Creamos nuestro estado con ceros de tamaño de 1 dimensión
estado = np.zeros((17), dtype=np.float16)
# Definimos en una lista los nombres con el diccionario original
names = list(data.keys())
# Crear la cadena con los índices (sumados con 1) y los nombres
indice_con_nombre = [f"{i+1}. {name}" for i, name in enumerate(names)]
# Definimos el índice de verdad (estado inicial)
key = int(input(f'Escoge el estado inicial (posicinal) respectivo de los modelos IA disponibles: {indice_con_nombre} ->'))
# Convertimos el estado en el índice índicado a verdad
estado[key - 1] = 1
# Definimos las iteraciones
iter = int(input('Ingrese el número de épocas a evaluar el estado inicial: '))

# Obtenemos el nombre del evento en estado de verdad
name_key = names[key - 1]

# Asignamos el par de estado aplicando la función CadenaDeMarkov con los argumentos necesarios
estado_nuevo, estado_pronosticado = CadenaDeMarkov(transicion, estado, iter)

# Creamos los subplots con fig (contenedor principal encargado de las leyendas, etiquetas, títulos) y los objetos Axes (contenedores de los gráficos individuales encargados de manejar los ejes, su tamaño, fuente, etc)
fig, ax = plt.subplots(3, 1, figsize=(20, 18))

# Creamos la paleta de colores en un espaciado de 0 y 1 en la escala de viridis, generando un color equitativamente distante de sus vecinos
colores = plt.cm.viridis(np.linspace(0, 1, len(data)))

# Gráfico de la matriz de transición
ax[0].imshow(transicion, cmap='coolwarm')

ax[0].set_title('Matriz de Transición', fontsize=8)

ax[0].set_xlabel('Consecuente', fontsize=7)
ax[0].set_ylabel('Antecedente', fontsize=7)

ax[0].set_xticks(np.arange(len(names)))  # Establecer posiciones para las etiquetas en el eje X
ax[0].set_yticks(np.arange(len(names)))  # Establecer posiciones para las etiquetas en el eje Y

ax[0].set_xticklabels(names)
ax[0].set_yticklabels(names)

ax[0].tick_params(axis='x', labelsize=5, rotation=90)
ax[0].tick_params(axis='y', labelsize=5)

# Agregar los valores dentro de cada celda de la matriz
for i in range(len(names)):
    for j in range(len(names)):
        ax[0].text(i, j, f'{transicion[i, j]:.2f}', ha='center', va='center', color='white', fontsize=5)

# Gráfico del nuevo estado
ax[1].bar(x=data.keys(), height=estado_nuevo, width=0.5, color=colores)

ax[1].set_xlabel('Modelos', fontsize=8)
ax[1].set_ylabel(f'Probabilidad de uso despues de usar a {name_key} en {iter} iteraciones', fontsize=6.5)
ax[1].set_title('Probabilidades con cadena de Markov', fontsize=9)

ax[1].tick_params(axis='x', labelsize=5, rotation=45) # Modificamos la orientación y tamaño de las etiquetas en cada punto del eje x

ax[1].yaxis.set_major_locator(MultipleLocator(0.01)) # Asignamos el paso del eje Y en 0.01 debido al tamaño de los probabilidades
formatter = FuncFormatter(lambda x, _: f'{x*100:.0f}%')  # Multiplicamos por 100 y agregamos '%' con lambda, asignamos _ porque el segundo valor respecta al eje y, pero no lo usamos
ax[1].yaxis.set_major_formatter(formatter) # Aplicamos el formateo en el eje Y

ax[1].set_ylim(0, 0.1) # Asignamos el límite de muestra respecto del eje Y

# Gráfico del estado pronosticado
ax[2].bar(x=data.keys(), height=estado_pronosticado, width=0.5, color=colores)

ax[2].set_xlabel('Modelos', fontsize=8)
ax[2].set_ylabel(f'Probabilidad de uso despues de usar a {name_key} pronosticádamente', fontsize=6.5)
ax[2].set_title('Probabilidades con cadena de Markov', fontsize=9)

ax[2].tick_params(axis='x', labelsize=5, rotation=45)
ax[2].yaxis.set_major_locator(MultipleLocator(0.01)) # Asignamos el paso del eje Y en 0.01 debido al tamaño de las probabilidades
formatter = FuncFormatter(lambda x, _: f'{x*100:.0f}%')  # Multiplicamos por 100 y agregamos '%' con lambda, asignamos _ porque el segundo valor respecta al eje y, pero no lo usamos
ax[2].yaxis.set_major_formatter(formatter) # Aplicamos el formateo en el eje Y

ax[2].set_ylim(0, 0.1) # Asignamos el límite de muestra respecto del eje Y

plt.subplots_adjust(hspace=0.5)  # Aumentar hspace para mayor separación vertical
plt.show() # Mostramos el plot
