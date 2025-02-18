import pandas as pd
import matplotlib.pyplot as plt

# Step 1: Load Data from a Dataset (CSV file)
data = pd.read_csv('ass_2.csv')

# Step 2: Display first few rows to verify the data
print(data.head())

# Step 3: Create a Histogram using Matplotlib
plt.figure(figsize=(10, 6))
plt.hist(data['Profit'], bins=10, color='blue', edgecolor='black')

plt.title('Distribution of Monthly Profits')
plt.xlabel('Profit')
plt.ylabel('Frequency')
plt.grid(True)
plt.show()
   