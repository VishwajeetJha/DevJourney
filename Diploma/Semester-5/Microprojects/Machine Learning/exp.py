# import pandas as pd
# import numpy as np

# # Load the two datasets
# dataset1 = pd.read_csv('orig_ds.csv')  # Original dataset with name, year, etc.
# dataset2 = pd.read_csv('sec_ds.csv')  # New dataset with ID, Price, Levy, etc.

# # 1. Drop 'ID' and 'Levy'
# dataset2.drop(['ID', 'Levy'], axis=1, inplace=True)

# # 2. Multiply 'Price' by 84 to convert it to INR
# dataset2['Price'] *= 84

# # 3. Combine 'Manufacturer' and 'Model' into 'name'
# dataset2['name'] = dataset2['Manufacturer'] + ' ' + dataset2['Model']

# # 4. Rename 'Prod. year' to 'year'
# dataset2.rename(columns={'Prod. year': 'year'}, inplace=True)

# # 5. Drop 'Leather interior'
# dataset2.drop(['Leather interior'], axis=1, inplace=True)

# # 6. Rename 'Fuel type' to 'fuel'
# dataset2.rename(columns={'Fuel type': 'fuel'}, inplace=True)

# # 7. Drop 'Engine volume'
# dataset2.drop(['Engine volume'], axis=1, inplace=True)

# # 8. Rename 'Mileage' to 'km_driven'
# dataset2.rename(columns={'Mileage': 'km_driven'}, inplace=True)

# # 9. Drop 'Cylinders'
# dataset2.drop(['Cylinders'], axis=1, inplace=True)

# # 10. Rename 'Gear box type' to 'transmission'
# dataset2.rename(columns={'Gear box type': 'transmission'}, inplace=True)

# # 11. Drop 'Drive wheels', 'Doors', 'Wheel', 'Color', 'Airbags'
# dataset2.drop(['Drive wheels', 'Doors', 'Wheel', 'Color', 'Airbags'], axis=1, inplace=True)

# # 12. Add random values for 'seller_type'
# seller_types = ['Dealer', 'Individual']
# np.random.seed(42)  # For reproducibility
# dataset2['seller_type'] = np.random.choice(seller_types, size=len(dataset2))

# # 13. Add random values for 'owner'
# owner_types = ['First Owner', 'Second Owner', 'Third Owner', 'Fourth & Above Owner']
# dataset2['owner'] = np.random.choice(owner_types, size=len(dataset2))

# # Optional: Create categories based on engine size for dataset1
# # Assuming dataset1 has an 'engine_size' column, we can categorize cars
# def categorize_by_engine_size(engine_size):
#     if engine_size < 1.5:
#         return 'Small'
#     elif 1.5 <= engine_size <= 2.5:
#         return 'Medium'
#     else:
#         return 'Large'

# if 'engine_size' in dataset1.columns:
#     dataset1['category'] = dataset1['engine_size'].apply(categorize_by_engine_size)

# # Drop 'category' in dataset2 as per your request
# dataset2.drop(['Category'], axis=1, inplace=True)

# # Now combine the two datasets
# # Aligning the columns and selecting relevant ones
# dataset1 = dataset1[['name', 'year', 'selling_price', 'km_driven', 'fuel', 'seller_type', 'transmission', 'owner']]
# dataset2 = dataset2[['name', 'year', 'Price', 'km_driven', 'fuel', 'seller_type', 'transmission', 'owner']]

# # Renaming 'Price' in dataset2 to 'selling_price' to match dataset1
# dataset2.rename(columns={'Price': 'selling_price'}, inplace=True)

# # Combine the two datasets vertically
# combined_dataset = pd.concat([dataset1, dataset2], ignore_index=True)

# # Save the combined dataset to a new CSV file
# combined_dataset.to_csv('combined_dataset.csv', index=False)

# print("Combined dataset created and saved as 'combined_dataset.csv'.")


import pandas as pd

# Load the dataset
data = pd.read_csv('combined_dataset.csv')

# Drop "km" from the km_driven column and convert to numeric
data['km_driven'] = data['km_driven'].str.replace('km', '', regex=False).astype(float)

# Optionally, you can fill any NaN values that result from the conversion
data['km_driven'].fillna(0, inplace=True)

# Save the modified dataset to a new CSV file
data.to_csv('modified_combined_dataset.csv', index=False)

print("Modified dataset saved as 'modified_combined_dataset.csv'.")
