string = input("Please enter a string: ")
split_words = string.split()
even_words = [x for x in split_words if len(x)%2==0]
print(even_words)