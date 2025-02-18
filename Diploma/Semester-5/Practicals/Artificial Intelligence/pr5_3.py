import pandas as pd
import matplotlib.pyplot as plt

# Sample Employee Data
employee_data = {
    'Employee Name': ['dev', 'vihaan', 'milan', 'kavan', 'shreyas'],
    'Age': [28, 34, 40, 22, 30],
    'Salary': [60000, 48000, 55000, 45000, 67000],
    'Years of Experience': [5, 12, 15, 3, 10]
}
df = pd.DataFrame(employee_data)

# Line Plot: Age vs Salary
df.plot(x='Age', y='Salary', kind='line', title='Age vs Salary')
plt.xlabel('Age')
plt.ylabel('Salary')
plt.show()
  
# Bar Plot: Salary of different employees
df.plot(x='Employee Name', y='Salary', kind='bar', title='Salary by Employee')
plt.xlabel('Employee Name')
plt.ylabel('Salary')
plt.show()

# Histogram: Distribution of Salaries
df['Salary'].plot(kind='hist', bins=5, title='Salary Distribution')
plt.xlabel('Salary')
plt.show()

# Scatter Plot: Years of Experience vs Salary
df.plot(x='Years of Experience', y='Salary', kind='scatter', title='Experience vs Salary')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')
plt.show()

# Box Plot: Age distribution
df['Age'].plot(kind='box', title='Age Distribution')
plt.ylabel('Age')
plt.show()
  