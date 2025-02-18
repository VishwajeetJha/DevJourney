import pandas as pd

# Define the dataset
data = pd.DataFrame({
    'Month': ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'],
    'Profit': [15000, 12000, 18000, 22000, 17500, 21000, 16000, 19500, 18500, 20000, 19000, 17000]
})

# Create a DataFrame
df = pd.DataFrame(data)

# Save the DataFrame to a CSV file
df.to_csv('ass_2.csv', index=False)

print("CSV file 'sample_data.csv' has been created.")
