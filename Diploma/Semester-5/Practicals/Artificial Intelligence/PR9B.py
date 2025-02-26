import numpy as np

# Function to calculate mean and standard deviation
def calculate_stats(data):
    mean = np.mean(data)
    std_dev = np.std(data)
    return mean, std_dev

# Example dataset
data = [12, 15, 14, 10, 18, 16, 20, 17]

# Calculate mean and standard deviation
mean, std_dev = calculate_stats(data)

print(f"Mean: {mean}")
print(f"Standard Deviation: {std_dev}")
