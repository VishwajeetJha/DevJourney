def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n-1) + fibonacci(n-2)

result = []
N = int(input("Enter number for Fibonacci Series: "))

for i in range(N):
    result.append(fibonacci(i))
print("Fibonacci number:", result)
