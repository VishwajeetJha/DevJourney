import pandas as pd

data = {'Column1': [1, 2, 3, 4, 5], 'Column2': [10, 20, 30, 40, 50]}
df = pd.DataFrame(data)

first_column = df.iloc[:, 0]  
print("\nFirst column as Series:")
print(first_column)

# op:-
# First column as Series:
# 0    1
# 1    2
# 2    3
# 3    4
# 4    5
# Name: Column1, dtype: int64