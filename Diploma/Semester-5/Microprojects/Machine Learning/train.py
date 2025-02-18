import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.ensemble import RandomForestRegressor, StackingRegressor, GradientBoostingRegressor
from sklearn.preprocessing import StandardScaler, OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.metrics import mean_squared_error, mean_absolute_error
from sklearn.pipeline import Pipeline
import joblib

# Load the data
data = pd.read_csv('ds.csv')

# Fill missing values
data.ffill(inplace=True)

# Add a new feature: car age
data['car_age'] = 2024 - data['year']

# Specify the categorical columns
categorical_features = ['fuel', 'seller_type', 'transmission', 'owner']

# Preprocessing pipeline
preprocessor = ColumnTransformer(
    transformers=[
        ('cat', OneHotEncoder(), categorical_features),
        ('num', StandardScaler(), ['km_driven', 'car_age'])
    ]
)

# Prepare the features and target variable
X = data.drop(['name', 'year', 'selling_price'], axis=1)
y = np.log(data['selling_price'])  # Log-transform the target variable

# Create base models for stacking
rf_model = Pipeline([
    ('preprocessor', preprocessor),
    ('model', RandomForestRegressor(random_state=42))
])

gb_model = Pipeline([
    ('preprocessor', preprocessor),
    ('model', GradientBoostingRegressor(random_state=42))
])

# Create a stacking model
stacked_model = StackingRegressor(
    estimators=[
        ('rf', rf_model),
        ('gb', gb_model)
    ],
    final_estimator=RandomForestRegressor(random_state=42)
)

# Define the parameter grid for grid search
param_grid = {
    'final_estimator__n_estimators': [50, 100, 200],
    'final_estimator__max_depth': [None, 10, 20],
    'rf__model__n_estimators': [50, 100, 200],
    'gb__model__n_estimators': [50, 100, 200]
}

# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Initialize GridSearchCV
grid_search = GridSearchCV(estimator=stacked_model, param_grid=param_grid,
                           scoring='neg_mean_squared_error', cv=3, verbose=2, n_jobs=-1)

# Fit the grid search model
grid_search.fit(X_train, y_train)

# Best parameters and score
print("Best parameters found: ", grid_search.best_params_)
print("Best cross-validation score: ", -grid_search.best_score_)

# Make predictions and evaluate the best stacked model
best_model = grid_search.best_estimator_
y_pred = best_model.predict(X_test)
mse = mean_squared_error(np.exp(y_test), np.exp(y_pred))  # Convert log back to original scale
rmse = np.sqrt(mse)
mae = mean_absolute_error(np.exp(y_test), np.exp(y_pred))  # Convert log back to original scale

# Print evaluation metrics
print('Mean Squared Error:', mse)
print('Root Mean Squared Error:', rmse)
print('Mean Absolute Error:', mae)

# Save the best stacked model to a file
model_filename = 'car_price_stacked_model_with_grid_search.pkl'
joblib.dump(best_model, model_filename)
print(f"Stacked model saved to {model_filename}")