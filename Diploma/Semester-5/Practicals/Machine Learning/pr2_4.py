import numpy as np

arr_3x2 = np.array([[1, 2], [3, 4], [5, 6]])

arr_2x3 = arr_3x2.reshape(2,3)

print(f"3X2 array \n{arr_3x2}")

print(f"\n After changing shape from 3X2 to 2X3 \n{arr_2x3}")
