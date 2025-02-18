# Write down syntax of user defined functions and also find area of circle using 
# default argument function with example

def area(r, pi=3.14):
    return pi*(r**2)

r = int(input("Enter radius of circle: "))
print("The area of circle with radius %.2f is: %.2f"%(r, area(r)))