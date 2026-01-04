import math

a = float(input("Enter coefficient a: "))
b = float(input("Enter coefficient b: "))
c = float(input("Enter coefficient c: "))
d = b**2 - 4*a*c
if a == 0:
     print("Coefficient 'a' cannot be zero for a quadratic equation.")
elif d > 0:
     root1 = (-b + math.sqrt(d)) / (2*a)
     root2 = (-b - math.sqrt(d)) / (2*a)
     print(f"Roots are real and different: {root1} and {root2}")
elif d == 0:
     root = -b / (2*a)
     print(f"Roots are real and equal: {root}")
else:
     real_part = -b / (2*a)
     imag_part = math.sqrt(-d) / (2*a)
     print(f"Roots are complex and imaginary: {real_part} + {imag_part}i and {real_part} - {imag_part}i")
