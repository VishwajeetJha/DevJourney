#Practical 4.2
import numpy as np

l1 = np.array([3.132, 2.33, 5.97, 6.5])

print("Original Array:\n",l1)

newArr = np.rint(l1)

print("Modified Array:\n",newArr)

#OUTPUT:-
#Original Array:
# [3.132 2.33  5.97  6.5  ]
#Modified Array:
# [3. 2. 6. 6.]