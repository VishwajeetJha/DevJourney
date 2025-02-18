with open("textfile.txt", "w") as tfile:
    tfile.write("This is a string\nWriting it to textfile.txt\nThis is a Test line 3\n")

with open("textfile.txt", "r") as tfile:
    print(tfile.read())

i=1
with open("textfile.txt", "r") as tfile:
    for line in tfile.readlines():
        print(f"Line {i}: {line}", end='')
        i+=1

strinp = input("\nEnter a string to write to TxtFile2.txt: ")
with open("textfile2.txt", "w") as tf2:
    tf2.write(strinp)

strinps = []

for i in range(5):
    inpstr = input(f"Enter string {i+1}(Enter 9 to exit): ")
    strinps.append(inpstr)


with open("textfile3.txt", "w") as tf3:
    for j in strinps:
        tf3.write(f"{j}\n")

i=0
with open("textfile3.txt", "r") as tf3:
    for line in tf3.readlines():
        i+=1

print(f"\nTxtfile3.txt has {i} lines")