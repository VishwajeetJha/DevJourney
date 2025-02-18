from matplotlib import pyplot as plt
import numpy as np
np.random.seed(42)
student_marks = np.random.uniform(0, 10, 100)
plt.figure(figsize=(8, 6))
plt.hist(student_marks, bins=20, range=(0, 10), color='skyblue', edgecolor='black')
plt.xlabel('Marks')
plt.ylabel('Number of Students')
plt.title('Distribution of Student Marks')
plt.xticks(np.arange(0, 11, 1))
plt.grid(axis='y', linestyle='--', alpha=1)
plt.show()
print(student_marks)