file_name = input("Enter the file name: ")
alphabet_count = {}

with open(file_name, 'r') as file:
    content = file.read()
    for char in content:
        if char.upper() >= 'A' and char.upper() <= 'Z':
            char = char.upper()
            alphabet_count[char] = alphabet_count.get(char, 0) + 1

for alphabet, count in alphabet_count.items():
    print(f"{alphabet}: {count}")