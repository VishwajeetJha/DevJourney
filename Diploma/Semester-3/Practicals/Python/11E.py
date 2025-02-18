file_name = input("Enter File Name: ")
wrdsum = ttlwrd = sentences = charcount = 0
with open(file_name, "r") as wrdcnt:
    for line in wrdcnt:
        words = line.split()
        for word in words:
            word = word.replace(" ", "")
            if word.isalpha():
                wrdsum += len(word)
                ttlwrd += 1

        charcount += len(line)
        sentences += line.count('.') + line.count('!') + line.count('?')

avgwrd = wrdsum / ttlwrd
avgsent = charcount / sentences
print("Average Word Length =", avgwrd)
print("Average Sentence Length =", avgsent)