import pandas as pd
import matplotlib.pyplot as plt

# Sample data for demonstration
data = {
    'Name': ['name1', 'name2', 'another name', 'so many names', 'HOW MANY-'],
    'Age': [17, 17, 18, 18, 19],
    'Score': [88, 90, 88, 95, 85]
}
df = pd.DataFrame(data)

# Line Plot: Plotting Age vs Score
df.plot(x='Age', y='Score', kind='line', title='Age vs Score')
plt.xlabel('Age')
plt.ylabel('Score')
plt.show()

# Bar Plot: Scores of different individuals
df.plot(x='Name', y='Score', kind='bar', title='Scores by Name')
plt.xlabel('Name')
plt.ylabel('Score')
plt.show()

# Histogram: Distribution of Scores
df['Score'].plot(kind='hist', bins=5, title='Score Distribution')
plt.xlabel('Score')
plt.show()

# Scatter Plot: Age vs Score
df.plot(x='Age', y='Score', kind='scatter', title='Age vs Score')
plt.xlabel('Age')
plt.ylabel('Score')
plt.show()

# Box Plot: Age distribution
df['Age'].plot(kind='box', title='Age Distribution')
plt.ylabel('Age')
plt.show()