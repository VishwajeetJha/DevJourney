import numpy as np

# Function for matrix multiplication and element-wise addition
def matrix_operations(matrix1, matrix2):
    # Matrix multiplication
    mat_mul = np.dot(matrix1, matrix2)

    # Element-wise matrix addition
    mat_add = np.add(matrix1, matrix2)

    return mat_mul, mat_add

# Example matrices
matrix1 = np.array([[1, 2], [3, 4]])
matrix2 = np.array([[5, 6], [7, 8]])

# Perform operations
mat_mul, mat_add = matrix_operations(matrix1, matrix2)

print("Matrix Multiplication:\n", mat_mul)
print("Element-wise Matrix Addition:\n", mat_add)
