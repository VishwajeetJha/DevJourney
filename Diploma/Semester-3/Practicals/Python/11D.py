with open("textfile.txt", 'r') as input_file:
    lines = input_file.readlines()

modified_lines = []

for line in lines:
    words = line.split()
    modified_words = [word if len(word) != 4 else '****' for word in words]
    modified_line = ' '.join(modified_words)
    modified_lines.append(modified_line)

with open("textfilecensor.txt", 'w') as output_file:
    output_file.writelines(modified_lines)
