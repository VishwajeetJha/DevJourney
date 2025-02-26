import numpy as np

def perform_math_functions(arr):
    # Calculate the mean, median, and standard deviation of the array
    mean_val = np.mean(arr)
    median_val = np.median(arr)
    std_val = np.std(arr)
    return mean_val, median_val, std_val

if __name__ == "__main__":
    # Replace this with your actual array or dataset
    data = np.array([10, 15, 12, 8, 20, 17, 25, 14, 19, 16])
    mean, median, std_dev = perfor
