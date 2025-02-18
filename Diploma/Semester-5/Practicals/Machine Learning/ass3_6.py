# Step 1: Import necessary libraries
import numpy as np
import pandas as pd
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import confusion_matrix, classification_report


# Step 2: Load and preprocess the dataset
iris = load_iris()
X = iris.data  # features
y = iris.target  # target labels

# Step 3: Split the dataset into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Step 4: Train the model
model = LogisticRegression(max_iter=200)
model.fit(X_train, y_train)

# Step 5: Predict the class labels
y_pred = model.predict(X_test)

# Step 6: Evaluate the model using confusion matrix
cm = confusion_matrix(y_test, y_pred)

# Step 8: Show classification report
report = classification_report(y_test, y_pred, target_names=iris.target_names)
print("Classification Report:\n", report)
