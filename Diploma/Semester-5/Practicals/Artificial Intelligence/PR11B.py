import numpy as np

# Function to clean data using mean
def clean_data_mean(data, threshold=1.5):
    mean_value = np.mean(data)
    std_dev = np.std(data)

    # Replace values that exceed threshold with mean
    cleaned_data = np.where(np.abs(data - mean_value) > threshold * std_dev, mean_value, data)
    return cleaned_data

# Function to clean data using median
def clean_data_median(data, threshold=1.5):
    median_value = np.median(data)
    std_dev = np.std(data)

    # Replace values that exceed threshold with median
    cleaned_data = np.where(np.abs(data - median_value) > threshold * std_dev, median_value, data)
    return cleaned_data

if __name__ == "__main__":
    data = np.array([10, 12, 14, 13, 10, 100, 12, 13, 10, 12, 11, 99])  # Sample dataset

    print("Original Data:", data)
    
    cleaned_mean = clean_data_mean(data)
    print("Data cleaned using mean:", cleaned_mean)

    cleaned_median = clean_data_median(data)
    print("Data cleaned using median:", cleaned_median)
