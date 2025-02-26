import pandas as pd

# Example: Create a DataFrame manually or load from a CSV
data = {
    'Name': ['name1', 'name2', 'another name', 'so many names', 'HOW MANY-'],
    'Age': [17, 17, 18, 18, 19],
    'Score': [85, 90, 78, 88, 95]
}
df = pd.DataFrame(data)

# Add a new column based on existing columns (e.g., Age Group)
df['Age Group'] = df['Age'].apply(lambda x: 'Young' if x < 30 else 'Old')

# Add another column, e.g., whether the Score is above 80
df['Passed'] = df['Score'] > 80

# Filter rows based on specific conditions (e.g., Age > 30 and Passed)
filtered_df = df[(df['Age'] > 17) & (df['Passed'])]

# Show the resulting DataFrame
print(df)
print("\nFiltered DataFrame:")
print(filtered_df)
