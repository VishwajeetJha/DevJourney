import numpy as np

mat1 = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
mat2 = np.array([[9, 8, 7], [6, 5, 4], [3, 2, 1]])


res = np.add(mat1, mat2)

print("Matrix 1:")
print(mat1)

print("\nMatrix 2:")
print(mat2)

print("\nResult of Matrix Addition:")
print(res)
