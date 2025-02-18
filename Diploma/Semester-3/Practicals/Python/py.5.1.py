#Program to Find Avg of N numbers.
n = int(input("Enter the number of elements: ")) #n = count of numbers you want to add. for ex. you want to add 5 random numbers therefore: n=5
total = 0
for i in range(n):
    num = float(input(f"Enter number {i+1}: "))
    total += num  #num is assigned and added in total for ex: total = 0, num = 1, total = 0+1: total = 1, total=1, num2=3,total:1+3=4 and it repeats till n(all numbers are added.)
average = total / n #Simple formula of Average. Sum on N Numbers/Total Number of Elements.
print(f"The sum  of {n} numbers you entered is: {total}")
print(f"The average of {n} numbers you entered is: {average}")