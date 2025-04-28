with open("sample_file.txt","r") as file:
    chars = file.read()

for char in chars:
    print(char,"\n")