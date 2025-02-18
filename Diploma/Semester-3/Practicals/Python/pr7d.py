# 7D:

import random

day={
    'Monday': random.randint(28, 54),
    'Tuesday': random.randint(28, 54),
    'Wednesday': random.randint(28, 54),
    'Thursday': random.randint(28, 54),
    'Friday': random.randint(28, 54),
    'Saturday': random.randint(28, 54),
    'Sunday': random.randint(28, 54)
}

print("Days with High Temperature (40 °C to 50 °C)")
for i,j in day.items():
    if(j>=40 and j<=50):
        print(i,"-->Temperature:", j, "°C")