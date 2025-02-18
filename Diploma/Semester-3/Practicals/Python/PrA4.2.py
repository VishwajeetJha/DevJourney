def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Example usage:
num1 = int(input("Enter number 1 for GcD: "))
num2 = int(input("Enter number 2 for GCD: "))

print("The GCD of %d and %d is: %d"%(num1,num2,gcd(num1, num2)))
