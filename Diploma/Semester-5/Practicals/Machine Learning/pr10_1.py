import pandas as pd

data = pd.read_csv('pr11.csv')
df = pd.DataFrame(data)

print("Original DataFrame:\n", df)

df_no_missing = df.dropna()

print("\nDataFrame after dropping rows with missing values:\n", df_no_missing)

# Output:

# Original DataFrame:
#        Name    Age         City
# 0   Aarush   18.0   Ahemedabad
# 1      dev   17.0         None
# 2  Shreyas    NaN   Ahemedabad
# 3    milan   18.0   Ahemedabad
# 4   Jenish   18.0  Ahemedabad
# 5     None  15.0        Paris

# DataFrame after dropping rows with missing values:
#       Name   Age         City
# 0  Aarush  18.0   Ahemedabad
# 3   milan  18.0   Ahemedabad
# 4  Jenish  18.0  Ahemedabad