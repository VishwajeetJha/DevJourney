# math_operations.py
def add(a, b):
    return a + b
def subtract(a, b):
    return a - b
def multiply(a, b):
    return a * b
def divide(a, b):
    if b != 0:
        return a / b
    else:
        return "Error: Division by zero"
def square(a):
    return a ** 2
def modulo(a, b):
    if b != 0:
        return a % b
    else:
        return "Error: Modulo by zero"
def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)