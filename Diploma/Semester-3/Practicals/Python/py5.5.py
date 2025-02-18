n = 49  #Numerator
series_sum = 0
for i in range(n):
    numerator = 2 * i + 1
    denominator = 2 * i + 3 
    term = numerator / denominator
    print(numerator,"/",denominator,"\r")
    series_sum += term
print(f"Sum of the series: {series_sum}")