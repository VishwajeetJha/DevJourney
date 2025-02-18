# Import the module
from factorial_module import nPr, nCr

# Example usage
n_value = 5
r_value = 2

# Calculate and print nPr and nCr
result_nPr = nPr(n_value, r_value)
result_nCr = nCr(n_value, r_value)

print(f"{n_value}P{r_value} =", result_nPr)
print(f"{n_value}C{r_value} =", result_nCr)
