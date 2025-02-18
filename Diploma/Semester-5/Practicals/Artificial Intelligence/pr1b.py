import numpy as np

random_arr = np.random.randint(1, 101, size=10)


mean = np.mean(random_arr)

deviation = np.std(random_arr)

print("Random Array:")
print(random_arr)

print("\nMean of the array:")
print(mean)

print("\nStandard Deviation of the array:")
print(deviation)
