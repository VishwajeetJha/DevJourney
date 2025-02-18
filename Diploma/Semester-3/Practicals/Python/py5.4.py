start_char = ord('!')
end_char = ord('~')
chars_per_line = 3
current_char = start_char
while current_char <= end_char:
    print(f"Character: {chr(current_char)}, Decimal: {current_char}, Hexadecimal: {hex(current_char)}", end="\t")
    current_char += 1
    if (current_char - start_char) % chars_per_line == 0:
        print()
if (current_char - start_char) % chars_per_line != 0:
    print()