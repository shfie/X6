num=[]
a=int(input("Enter the number of elements you want in the list: "))
for i in range(a):
    b=int(input("Enter the number: "))
    num.append(b)

result = []
for n in num:
    if n % 2 != 0:  
        result.append(n)

print(result)  
