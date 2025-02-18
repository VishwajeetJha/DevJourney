import random
matrix = [[0] * 4 for i in range(4)]
for i in range(4):
    for j in range(4):
        matrix[i][j] = random.randint(0, 1)
print("Randomly generated 4x4 matrix:")
for row in matrix:
    print(" ".join(map(str, row)))
maxrow = 0
maxrow_indices = []
for i, row in enumerate(matrix):
    row_count = row.count(1)
    if row_count >maxrow:
        maxrow = row_count
        maxrow_indices = [i]
    elif row_count == maxrow:
        maxrow_indices.append(i)
max_col_count = 0
max_col_indices = []
for j in range(4):
    col_count = sum(matrix[i][j] for i in range(4))
    if col_count > max_col_count:
        max_col_count = col_count
        max_col_indices = [j]
    elif col_count == max_col_count:
        max_col_indices.append(j)
print("\nRows with the most 1s:", maxrow_indices, "with", maxrow, "1s")
print("Columns with the most 1s:", max_col_indices, "with", max_col_count, "1s")