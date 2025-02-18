import numpy as np


array = np.arange(1, 15)  

splitarr= np.split(array, [2, 6]) 

print("Split Arrays:")
for i, arr in enumerate(splitarr):
    print(f"Array {i+1}: {arr}")


