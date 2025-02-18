# Import necessary libraries
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.datasets import load_iris
from sklearn.metrics import accuracy_score

# Load the dataset (Iris dataset for this example)
iris = load_iris()
X, y = iris.data, iris.target

# Split the dataset into training and testing sets (80% train, 20% test)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create the K-NN model
k = 3  # Number of neighbors
knn = KNeighborsClassifier(n_neighbors=k)

# Train the model
knn.fit(X_train, y_train)

# Make predictions on the test set
y_pred = knn.predict(X_test)

# Evaluate the modelb 
accuracy = accuracy_score(y_test, y_pred)
print(f"Accuracy: {accuracy * 100:.2f}%")
 
# Optionally, you can test with a new sample
new_sample = np.array([[5.0, 3.6, 1.4, 0.2]])  # Example sample
prediction = knn.predict(new_sample)
print(f"Predicted class for the new sample: {iris.target_names[prediction][0]}")

# o/p:-
# Accuracy: 100.00%
# Predicted class for the new sample: setosa