import numpy as np
import pandas as pd

# Function to impute missing values using mean or median
def impute_missing_values(data, strategy='mean'):
    if strategy == 'mean':
        imputed_data = data.fillna(data.mean())
    elif strategy == 'median':
        imputed_data = data.fillna(data.median())
    else:
        raise ValueError("Strategy not recognized. Use 'mean' or 'median'.")
    
    return imputed_data

# Example dataset with missing values (NaN)
data = pd.DataFrame({
    'A': [1, 2, np.nan, 4, 5],
    'B': [5, np.nan, np.nan, 3, 1],
    'C': [np.nan, 4, 2, 3, np.nan]
})

print("Original Data:")
print(data)

# Impute missing values using mean
imputed_mean = impute_missing_values(data, strategy='mean')
print("\nData after imputing missing values using mean:")
print(imputed_mean)

# Impute missing values using median
imputed_median = impute_missing_values(data, strategy='median')
print("\nData after imputing missing values using median:")
print(imputed_median)
