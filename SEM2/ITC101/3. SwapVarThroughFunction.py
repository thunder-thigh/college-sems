def swap_var(var1, var2):
    temp = var1         # Do not try to be a smart-ass and do code-golfing
    var1 = var2         # If you do a=a-b, b=a-b.... you are making a mistake
    var2 = temp         # Look up register scheduling and integer overflow vulnerability
    return var1, var2   # Temp vars are no problem especially in garbage collected languages.

x = input("Enter a value: ")
y = input("Enter the second value: ")

print(f"Before swap: {x} {y}")
x,y = swap_var(x,y)
print(f"After swap: {x} {y}")