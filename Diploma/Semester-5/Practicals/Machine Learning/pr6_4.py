import numpy as np
import pandas as pd

series = pd.Series([50, 20, 40, 10, 30])

sorted_series = series.sort_values()

print("\nSorted Series:")
print(sorted_series)


# o/p:-
# Sorted Series:
# 3    10
# 1    20
# 4    30
# 2    40
# 0    50
# dtype: int64