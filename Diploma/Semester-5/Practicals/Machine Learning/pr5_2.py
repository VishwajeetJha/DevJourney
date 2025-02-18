import numpy as np

l1 = np.array([[2,8,3], [2,8,9], [3,0,2]])

mean = np.mean(l1, axis=1)
std = np.std(l1, axis=1)
var = np.var(l1, axis=1)

mean = np.around(mean, decimals=2)
std = np.around(std, decimals=2)
var = np.around(var, decimals=2)

print("Mean:\n", mean )
print("Standard Deviation:\n", std)
print("Variance:\n",var)


#OUTPUT:-
# Mean:
#  [4.33 6.33 1.67]
# Standard Deviation:
#  [2.62 3.09 1.25]
# Variance:
#  [6.89 9.56 1.56]