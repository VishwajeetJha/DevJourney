import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
import matplotlib.pyplot as plt

np.random.seed(42)  # For reproducibility

# Features
num_houses = 100
rooms = np.random.randint(1, 10, num_houses)  # Number of rooms (1-9)
size = np.random.randint(500, 3500, num_houses)  # Size in square feet (500-3500)
age = np.random.randint(1, 100, num_houses)  # Age of the house (1-100 years)

# House price (target variable) with some random noise added
prices = (rooms * 50000) + (size * 150) - (age * 1000) + np.random.randint(-50000, 50000, num_houses)

# Combine features into a single dataset
X = np.column_stack((rooms, size, age))
y = prices

# Step 1: Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Step 2: Initialize and train the Linear Regression model
model = LinearRegression()
model.fit(X_train, y_train)

# Step 3: Make predictions on the test set
y_pred = model.predict(X_test)

# Step 4: Evaluate the model
mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)
print(f'Mean Squared Error: {mse}')
print(f'R-squared: {r2}')
print(f'Coefficients: {model.coef_}')
print(f'Intercept: {model.intercept_}')

# Step 5: Plot the results
plt.figure(figsize=(10, 6))

# Plotting the actual vs predicted values
plt.scatter(y_test, y_pred, color='blue', label='Predicted vs Actual')
plt.plot([min(y_test), max(y_test)], [min(y_test), max(y_test)], color='red', linewidth=2, label='Ideal Fit')

plt.xlabel('Actual House Prices')
plt.ylabel('Predicted House Prices')
plt.title(f'Actual vs Predicted House Prices\nMSE: {mse:.2f}, R-squared: {r2:.2f}')
plt.legend()
plt.show()