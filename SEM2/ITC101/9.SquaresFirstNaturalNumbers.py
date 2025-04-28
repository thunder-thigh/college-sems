x = int(input("Enter range/limit: "))

if x<=0:
    exit()

sum = 0
while (x>0):
    sum = sum+(x*x)
    x-=1
print("Sum is: ",sum)