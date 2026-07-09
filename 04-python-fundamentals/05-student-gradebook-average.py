estudiantes = {}

for i in range (3):
    nombre = str(input("Ingrese el nombre de los estudiantes: "))
    estudiantes[nombre] = int(input("Ingrese la nota de los estudiantes: "))

promedio = sum(estudiantes.values()) / len(estudiantes)
print(f"Estudiantes y sus calificaciones: ", estudiantes)
print(f"El promedio de las notas de los estudiantes es: ", promedio)
