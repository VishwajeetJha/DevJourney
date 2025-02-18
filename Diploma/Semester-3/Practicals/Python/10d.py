print("Please Input 2 Words in lowercase only and Avoid Giving Space.")
word1 = input("Enter the first word: ")
word2 = input("Enter the second word: ")

#But if Still Someone Gives Space or Add an Uppercase Letter:
modword1 = word1.replace(" ", "").lower() 
modword2 = word2.replace(" ", "").lower() 

if sorted(modword1) == sorted(modword2):
    print(f"{word1} and {word2} are anagrams.")
else:
    print(f"{word1} and {word2} are not anagrams.")