limit=int(input("Enter the limit: "))
a=0
b=1
count=0
if limit<=0:
    print("Please enter a positive integer")
elif limit==1:
    print("Fibonacci sequence upto",limit,":")
    print(a)    
else:
    print("Fibonacci sequence:")
    while count<limit:
        print(a)
        c=a+b
        a=b
        b=c
        count+=1
        
    