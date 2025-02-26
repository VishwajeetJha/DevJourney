import numpy as np
import pandas as pd
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

# Seed for reproducibility
np.random.seed(42)

# Create a dataset with CGPA values
cgpa_high = np.random.normal(loc=9.5, scale=0.5, size=50)  # CGPA above 9
cgpa_medium = np.random.normal(loc=7, scale=0.5, size=50)  # CGPA between 6 and 8
cgpa_low = np.random.normal(loc=4.5, scale=0.5, size=50)   # CGPA below 5

# Combine all data
cgpa = np.concatenate([cgpa_high, cgpa_medium, cgpa_low])
labels = np.concatenate([np.ones(50), np.ones(50) * 2, np.ones(50) * 3])

# Create a DataFrame
df = pd.DataFrame({
    'CGPA': cgpa,
    'Label': labels
})

# Prepare the data
X = df[['CGPA']].values

# Initialize k-Means with 3 clusters
kmeans = KMeans(n_clusters=3, random_state=42)
kmeans.fit(X)
 
# Predict the cluster labels
df['Cluster'] = kmeans.predict(X)

# Get the cluster centers
centers = kmeans.cluster_centers_

# Plot the results
plt.figure(figsize=(10, 6))
plt.scatter(df['CGPA'], df['Cluster'], c=df['Label'], cmap='viridis', marker='o', alpha=0.6, edgecolors='w', s=100)
plt.scatter(centers, np.arange(3), c='red', marker='x', s=200, label='Cluster Centers')  # Cluster centers
plt.xlabel('CGPA')
plt.ylabel('Cluster')
plt.title('k-Means Clustering of Students by CGPA')
plt.colorbar(label='True Label')
plt.legend()
plt.grid(True)
plt.show()