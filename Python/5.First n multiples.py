num = int(input("Enter the number: "))
n = int(input("Enter how many multiples you want: "))

print(f"First {n} multiples of {num} are:")

for i in range(1, n+1):
    print(num * i)
