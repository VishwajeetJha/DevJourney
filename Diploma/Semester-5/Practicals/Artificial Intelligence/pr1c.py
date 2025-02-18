import numpy as np

def cal(arr1, arr2):
    dot_pro = np.dot(arr1, arr2)
    return dot_pro


arr1 = np.array([1, 2, 3])
arr2 = np.array([4, 5, 6])

res = cal(arr1, arr2)
print("Dot Product:", res)
