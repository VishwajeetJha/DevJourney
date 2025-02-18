#Practical 4.4
import numpy as np

l1 = np.array([1, 11, 9, 2, 7, 20, 10])

ndiff = np.diff(l1)

print("Differences of Neighbours(list[i+1] - list[i]): ", ndiff)


#OUTPUT:-
#Differences of Neighbours(list[i+1] - list[i]):  [ 10  -2  -7   5  13 -10]