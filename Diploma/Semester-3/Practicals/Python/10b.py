str = input("Enter String: ")
tupv = ()
tupc = ()
vowels = "aeiouAEIOU"
for x in range(len(str)):
    if str[x] in vowels:
        tupv += (str[x],)
    else:
        tupc += (str[x],)
print("Vowels in String: ", len(tupv))
print("Consonants in String: ", len(tupc))