import numpy as np
import pandas as pd
arr = np.array([10, 20, 30, 40, 50])
series = pd.Series(arr)
print("Pandas Series from NumPy array:")
print(series)


# op:-
# Pandas Series from NumPy array:
# 0    10
# 1    20
# 2    30
# 3    40
# 4    50
# dtype: int32
