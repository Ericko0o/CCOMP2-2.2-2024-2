from sympy import *

# Define las variables simbólicas
x = symbols('x')

# Define la ecuación que quieres expandir
ecuacion = (((x * (x - 1) * (x - 2) * (x - 3) * x * (x - 1)) / x) + ((x * (x - 1) * (x - 2) * x * (x - 1)) / x)) - (x * (x - 1) * (x - 2) * (x - 3) + x * (x - 1) * (x - 2))

# Expande la ecuación
ecuacion_expandida = factor(ecuacion)

# Imprime el resultado
print(ecuacion_expandida)
