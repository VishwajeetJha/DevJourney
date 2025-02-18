name = input("Enter Name: ")
numval = 0
name = name.replace(" ", "").upper()

for char in name:
    if 'A' <= char <= 'Z':
        char_value = ord(char) - ord('A') + 1
        numval += char_value

print(f"The Numeric Value of Name {name} = {numval}")