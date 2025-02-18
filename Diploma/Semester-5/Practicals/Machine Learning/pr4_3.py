#Practical 4.3
import numpy as np

l1 = np.array([[2,4], [3,5]])

sum1 = np.mean(l1, axis=0)
sum2 = np.mean(l1, axis=1)

print("Sum Mean(c): ", sum1)
print("Sum Mean(r): ", sum2)

#OUTPUT:-
#Sum Mean(c):  [2.5 4.5]
#Sum Mean(r):  [3. 4.]