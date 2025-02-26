import pandas as pd

# Example: Employee Data
employee_data = {
    'Employee Name': ['name1', 'name2', 'another name', 'so many names', 'HOW MANY-'],
    'Age': [28, 34, 40, 22, 30],
    'Salary': [60000, 48000, 55000, 45000, 67000],
    'Years of Experience': [5, 12, 15, 3, 10]
}

# Create DataFrame
df = pd.DataFrame(employee_data)

# Add a new column 'Experience Level' based on Years of Experience
df['Experience Level'] = df['Years of Experience'].apply(lambda x: 'Senior' if x > 5 else 'Junior')

# Add another column 'High Salary' based on Salary > 50000
df['High Salary'] = df['Salary'] > 50000

# Filter rows where the employee is 'Senior' and has a High Salary
filtered_df = df[(df['Experience Level'] == 'Senior') & (df['High Salary'])]

# Display the DataFrame with added columns
print("Original DataFrame:\n", df)

# Display the filtered DataFrame
print("\nFiltered DataFrame:\n", filtered_df)
