

import pandas as pd

# Load the dataset from a CSV file
file_path = ('Mall_Customers.csv')  # Replace with your file path
data = pd.read_csv(file_path)

# Display summary statistics
summary_statistics = data.describe()

# Show the summary statistics
print(summary_statistics)
