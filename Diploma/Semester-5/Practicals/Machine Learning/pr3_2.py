import numpy as np

arr1 = np.array([1, 2])
arr2 = np.array([3, 4, 5, 6])
arr3 = np.array([7, 8, 9, 10, 11, 12, 13, 14])

stacked = np.hstack((arr1, arr2, arr3))

print("Stacked Array (Horizontally):")
print(stacked)
