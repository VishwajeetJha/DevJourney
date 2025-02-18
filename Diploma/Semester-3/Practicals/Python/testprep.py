# cities = []

# while True:
#     inp=input("Enter city name(9 to exit): ")
#     if not (inp.isalpha()) and int(inp)==9:
#         break
#     elif not(inp.isalpha()):
#         print("Invalid input..! Try again..")
#     else:
#         cities.append(inp)

# print("Cities:-")
# for i in cities:
#     print(i)


# a = float(input("Enter first number: "))
# b = float(input("Enter second number: "))

# print("\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Modulo\n9. Exit")

# while True:
#     ch = int(input("Enter your choice: "))

#     if ch==1:
#         print("Sum is: ", a+b)
#         break
#     elif ch==2:
#         print("Subtraction is: ", a-b)
#         break
#     elif ch==3:
#         print("Multiplication is: ", a*b)
#         break
#     elif ch==4:
#         if b==0:
#             print("ERROR: Division by 0")
#             break
#         else:
#             print("Quotient is: ", a/b)
#             break
#     elif ch==5:
#         print("Modulo is: ", a%b)
#         break
#     elif ch==9:
#         print("Exiting...")
#         break
#     else:
#         print("WARNING: Wrong choice.. Please try again..")
#         continue

# a = float(input("Enter first number: "))
# b = float(input("Enter second number: "))

# print("is a>b: ", a>b)
# print("is a<b: ", a<b)
# print("is a==b: ",a==b)
# print("is a>=b: ",a>=b)
# print("is a<=b: ",a<=b)
# print("is a!=b: ",a!=b)

# a = int(input("Enter first number: "))
# b = int(input("Enter second number: "))

# print("a^b: ", a^b)
# print("a&b: ", a&b)
# print("a|b: ", a|b)
# print("~a, ~b: ", ~a,", ", ~b)
# print("a<<b: ", a<<b)
# print("a>>b: ", a>>b)

# def fact(n):
#     f = 1
#     for i in range(1, (n+1)):
#         f = f*i
#     return f

# print(fact(4))

a = int(input("Enter a number: "))

if a%2 != 0 and a%i != 0 and [i for i in range(a)]:
    print(f"{a} is prime")
else:
    print(a, "is prime")
