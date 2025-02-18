import numpy as np

# Function to detect and clean noisy data using mean
def clean_data_mean(data, threshold=1.5):
    mean_value = np.mean(data)
    std_dev = np.std(data)

    # Identify noisy data (outliers)
    cleaned_data = np.where(np.abs(data - mean_value) > threshold * std_dev, mean_value, data)

    return cleaned_data

# Function to detect and clean noisy data using median
def clean_data_median(data, threshold=1.5):
    median_value = np.median(data)
    std_dev = np.std(data)

    # Identify noisy data (outliers)
    cleaned_data = np.where(np.abs(data - median_value) > threshold * std_dev, median_value, data)

    return cleaned_data

# Function to detect and remove outliers using Z-score method
def remove_outliers_zscore(data, z_threshold=3):
    mean_value = np.mean(data)
    std_dev = np.std(data)

    # Compute Z-scores
    z_scores = (data - mean_value) / std_dev

    # Filter data points where the Z-score is less than the threshold
    cleaned_data = data[np.abs(z_scores) < z_threshold]

    return cleaned_data

# Function to detect and remove outliers using IQR method
def remove_outliers_iqr(data):
    Q1 = np.percentile(data, 25)
    Q3 = np.percentile(data, 75)
    IQR = Q3 - Q1

    lower_bound = Q1 - 1.5 * IQR
    upper_bound = Q3 + 1.5 * IQR

    # Filter out outliers outside the IQR range
    cleaned_data = data[(data >= lower_bound) & (data <= upper_bound)]

    return cleaned_data

# Sample data with noise
data = np.array([10, 12, 14, 13, 10, 100, 12, 13, 10, 12, 11, 99])

print("Original Data:", data)

# Clean data using mean
cleaned_mean = clean_data_mean(data)
print("Data cleaned using mean:", cleaned_mean)

# Clean data using median
cleaned_median = clean_data_median(data)
print("Data cleaned using median:", cleaned_median)

# Remove outliers using Z-score method
cleaned_zscore = remove_outliers_zscore(data)
print("Data after removing outliers using Z-score:", cleaned_zscore)

# Remove outliers using IQR method
cleaned_iqr = remove_outliers_iqr(data)
print("Data after removing outliers using IQR:", cleaned_iqr)