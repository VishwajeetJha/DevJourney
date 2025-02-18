import pandas as pd

data =pd.read_csv('pr11.csv')

df = pd.DataFrame(data)

print("Original DataFrame:\n", df)

n_dub = df.drop_duplicates()

print("\nDataFrame after removing duplicates:\n", n_dub)

# o/p:-

# Original DataFrame:
#        Name   Age        City
# 0      dev  18.0  Ahemedabad
# 1   jenish  22.0        None
# 2   aarush   NaN       surat
# 3  shreyas  32.0      London
# 4      dev  18.0  Ahemedabad
# 5     None  25.0       Paris

# DataFrame after removing duplicates:
#        Name   Age        City
# 0      dev  18.0  Ahemedabad
# 1   jenish  22.0        None
# 2   aarush   NaN       surat
# 3  shreyas  32.0      London
# 5     None  25.0       Paris