file_name = input("Enter the file name: ")
digit_count = {}
numFound = False
with open(file_name, 'r') as file:
    content = file.read()
    for num in content:
        if num.isdigit():
            numFound = True
            digit_count[num] = digit_count.get(num, 0) + 1
if numFound:
    for digit, count in digit_count.items():
        print(f"Number: {digit} found {count} times")
elif not numFound:
    print("No digits were found in this file.")