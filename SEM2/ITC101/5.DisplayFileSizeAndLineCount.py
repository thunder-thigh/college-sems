import sys
with open("sample_file.txt","r") as file:
    lines = file.readlines()
    print("Size: ", sys.getsizeof(lines))
    print("Nume of lines: ", len(lines))