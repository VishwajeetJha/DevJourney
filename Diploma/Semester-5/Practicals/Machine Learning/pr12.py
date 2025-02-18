import pandas as pd

# Load your dataset (replace 'your_dataset.csv' with the path to your dataset)
# You can also use read_excel or other methods depending on your file type
data = pd.read_csv('pr11.csv')

# Print the keys of the DataFrame (column names)
print("Keys of the dataset (column names):")
print(data.columns.tolist(), "\n")

# Get the number of rows and columns
num_rows, num_columns = data.shape
print(f"Number of rows: {num_rows}")
print(f"Number of columns: {num_columns}\n")

# Print the feature names (all column names)
print("Feature names:")
print(data.columns.tolist(), "\n")

# Print a description of the dataset
print("Dataset description:")
print(data.describe(include='all'))

# o/p:-
# Keys of the dataset (column names):
# ['A', 'B', 'C', 'D']

# Number of rows: 4
# Number of columns: 4

# Feature names:
# ['A', 'B', 'C', 'D']

# Dataset description:
#               A        B          C     D
# count  3.000000  2.00000   4.000000   3.0
# mean   2.333333  6.50000  10.500000  15.0
# std    1.527525  2.12132   1.290994   1.0
# min    1.000000  5.00000   9.000000  14.0
# 25%    1.500000  5.75000   9.750000  14.5
# 50%    2.000000  6.50000  10.500000  15.0
# 75%    3.000000  7.25000  11.250000  15.5
# max    4.000000  8.00000  12.000000  16.0
