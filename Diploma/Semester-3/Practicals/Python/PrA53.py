with open('test.txt', 'r') as file:
        content = file.read()
        words = content.split()
        total_words = len(words)
        total_characters = len(content)

print(f"Total number of words: {total_words}")
print(f"Total number of characters: {total_characters}")
