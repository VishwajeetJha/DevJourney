import numpy as np
import pandas as pd

series = pd.Series([10, 20, 30, 40, 50])


mean = series.mean()

deviation = series.std()

print("\nMean of the Series:")
print(mean)
print("Standard Deviation of the Series:")
print(deviation)

# o/p:-
# Mean of the Series:
# 30.0
# Standard Deviation of the Series:
# 15.811388300841896