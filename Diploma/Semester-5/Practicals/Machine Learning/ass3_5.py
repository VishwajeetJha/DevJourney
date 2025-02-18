from sklearn.datasets import load_iris
from sklearn.model_selection import KFold
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score

# Step 1: Load the dataset (you can replace this with any dataset)
data = load_iris()
X = data.data  # Features
y = data.target  # Labels

# Step 2: Set up the K-Fold Cross Validation
kf = KFold(n_splits=5, shuffle=True, random_state=42)

# Step 3: Initialize a model
model = RandomForestClassifier()

# Step 4: Perform K-Fold Cross Validation
accuracies = []

# Loop through each split
for train_index, test_index in kf.split(X):
    X_train, X_test = X[train_index], X[test_index]
    y_train, y_test = y[train_index], y[test_index]
    
    # Train the model
    model.fit(X_train, y_train)
    
    # Make predictions
    y_pred = model.predict(X_test)
    
    # Evaluate the model
    accuracy = accuracy_score(y_test, y_pred)
    accuracies.append(accuracy)

# Step 5: Output the results
print(f'Accuracies for each fold: {accuracies}')
print(f'Average accuracy: {sum(accuracies)/len(accuracies):.2f}')
