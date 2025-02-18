count = 0 
n = 10
total_combinations = 0
numbers = []
print("Enter 10 integers:")
for i in range(n):
    num_i = int(input(f"Enter integer {i + 1}: "))
    numbers.append(num_i)
print("Combinations of picking two numbers from the list:")
for i in range(n):
    for j in range(i + 1, n):
        num_i = numbers[i]
        num_j = numbers[j]
        combination = (num_i, num_j)
        count += 1
        total_combinations += 1
        print(f"Combination No. {count}: {combination}")
print(f"There are {total_combinations} combinations possible in total.")