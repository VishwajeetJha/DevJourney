s = int(input("Enter your score: "))

if s>100:
    g = 'n/a'
elif (s>=90) and (s<=100):
    g = 'A'
elif s>=80:
    g = 'B'
elif s>=70:
    g = 'C'
elif s>=60:
    g = 'D'
else:
    g = 'F'

print("Your grade: "+str(g))
