I = 0
II = 1
NEXT = 1

def fibonacci(x):
    I = 0
    II = 1
    NEXT = 1
    while x>=3:
        print(I+II)
        I = II          #Update next iteration terms
        II = NEXT
        NEXT = I+II
        x-=1            #Update loop counter

num = int(input("Enter a number: "))
if num<0:
    print("Enter a non-zero positive integer and try again")
    exit()
else:
    print("Factorial is: ")
    print(f"{I}\n{II}") #Save performance and pre-print first two terms
    fibonacci(num)