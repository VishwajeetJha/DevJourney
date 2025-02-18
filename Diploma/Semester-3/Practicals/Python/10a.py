str1 = input("Enter String: ")

str_rev = str1[-1::-1]

if str1 == str_rev:
    print("String is a Palindrome.")
else:
    print("String is Not a Palindrome.")