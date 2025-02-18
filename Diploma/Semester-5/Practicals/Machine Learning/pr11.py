import pandas as pd

df = pd.read_csv('pr11.csv')

print("Original DataFrame:")
print(df)

columns_with_no_nans = df.dropna(axis=1)
print("\nColumns where all entries are present (no NaNs):")
print(columns_with_no_nans)

nan_locations = df.isnull()
print("\nRows and columns with NaN values (True indicates NaN):")
print(nan_locations)

df_cleaned = df.dropna(axis=0)
print("\nDataFrame after dropping rows with any NaN values:")
print(df_cleaned)

# Output:
# Original DataFrame:
#      A    B   C     D
# 0  1.0  5.0   9   NaN
# 1  2.0  NaN  10  14.0
# 2  NaN  NaN  11  15.0
# 3  4.0  8.0  12  16.0

# Columns where all entries are present (no NaNs):
#     C
# 0   9
# 1  10
# 2  11
# 3  12

# Rows and columns with NaN values (True indicates NaN):
#        A      B      C      D
# 0  False  False  False   True
# 1  False   True  False  False
# 2   True   True  False  False
# 3  False  False  False  False

# DataFrame after dropping rows with any NaN values:
#      A    B   C     D
# 3  4.0  8.0  12  16.0


# MCQ QUIZ:

# 1> D. Python
# 2> C. value, size
# 3> B. DataFrame
# 4> D. All of the above
# 5> D. All of the above
# 6> A. Panel Data

