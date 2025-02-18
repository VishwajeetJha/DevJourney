# pyramid star pattern
print("Pyramid of * Pattern.")
n = 5
for i in range(1, n+1):
    for j in range(n - i):
        print(' ', end='')
    for k in range(2 * i - 1):
        print('*', end='')
    print()
#Pyramid of Number 
print("Pyramid of Numbers.")
rows = 5
for i in range(1, rows + 1):
    for j in range(1, i + 1):
        print(j, end=' ')
    print('')