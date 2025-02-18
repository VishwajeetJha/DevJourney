import numpy as np

l1 = np.array([[1,2,7],[0,4,6],[9,1,3]])

max1 = np.amax(l1, axis=0)
max2 = np.amax(l1, axis=1)

min1 = np.amin(l1, axis=0)
min2 = np.amin(l1, axis=1)

print("Max. Value among Rows:\n", max1)
print("Max. Value among Columns:\n", max2)

print("Min. Value among Rows:\n", min1)
print("Min. Value among Columns:\n", min2)

#OUTPUT:-
# Max. Value among Rows:
#  [9 4 7]
# Max. Value among Columns:
#  [7 6 9]
# Min. Value among Rows:
#  [0 1 3]
# Min. Value among Columns:
#  [1 0 1]
