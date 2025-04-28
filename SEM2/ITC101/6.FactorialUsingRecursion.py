def factorial(x):
    if x==0:
        return 1
    else:
        return x*factorial(x-1)

num = int(input("Enter a number: "))
if num<0:
    print("Enter a non-zero positive integer and try again")
    exit()
else:
    print("Factorial is: ",factorial(num))