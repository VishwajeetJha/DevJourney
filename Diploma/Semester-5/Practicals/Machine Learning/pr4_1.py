import numpy as np

l1 = np.array([1,3,7,5])
l2 = np.array([2,6,14,15])

sum = np.add(l1,l2)
diff = np.subtract(l2,l1)
product = np.multiply(l1,l2)
division = np.divide(l2,l1)


print("Sum: ",sum)
print("Difference: ",diff)
print("Product: ",product)
print("Division: ",division)

#OUTPUT:-
#Sum:  [ 3  9 21 20]
#Difference:  [ 1  3  7 10]
#Product:  [ 2 18 98 75]
#Devision:  [2. 2. 2. 3.]