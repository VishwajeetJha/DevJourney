import numpy as np

# Function to remove outliers using Z-score
def remove_outliers_zscore(data, z_threshold=1):
    mean_value = np.mean(data)
    std_dev = np.std(data)

    # Compute Z-scores
    z_scores = (data - mean_value) / std_dev

    # Keep values within the threshold
    cleaned_data = data[np.abs(z_scores) < z_threshold]
    return cleaned_data

# Function to remove outliers using IQR (Interquartile Range)
def remove_outliers_iqr(data):
    Q1 = np.percentile(data, 25)
    Q3 = np.percentile(data, 75)
    IQR = Q3 - Q1

    lower_bound = Q1 - 1.5 * IQR
    upper_bound = Q3 + 1.5 * IQR

    # Filter values within IQR range
    cleaned_data = data[(data >= lower_bound) & (data <= upper_bound)]
    return cleaned_data

if __name__ == "__main__":
    data = np.array([10, 12, 14, 13, 10, 100, 12, 13, 10, 12, 11, 99])  # Sample dataset

    print("Original Data:", data)
    
    cleaned_zscore = remove_outliers_zscore(data)
    print("Data after removing outliers using Z-score:", cleaned_zscore)

    cleaned_iqr = remove_outliers_iqr(data)
    print("Data after removing outliers using IQR:", cleaned_iqr)
