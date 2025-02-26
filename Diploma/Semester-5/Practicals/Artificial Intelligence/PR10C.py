import numpy as np
import pandas as pd
from sklearn.impute import KNNImputer

# Function to impute missing values using mean, median, or KNN
def impute_missing_values(data, strategy='mean', n_neighbors=3):
    if strategy == 'mean':
        imputed_data = data.fillna(data.mean())
    elif strategy == 'median':
        imputed_data = data.fillna(data.median())
    elif strategy == 'knn':
        # KNN Imputer
        imputer = KNNImputer(n_neighbors=n_neighbors)
        imputed_data = pd.DataFrame(imputer.fit_transform(data), columns=data.columns)
    else:
        raise ValueError("Strategy not recognized. Use 'mean', 'median', or 'knn'.")
    
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

# Impute missing values using KNN
imputed_knn = impute_missing_values(data, strategy='knn', n_neighbors=2)
print("\nData after imputing missing values using KNN:")
print(imputed_knn)
