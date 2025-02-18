l = []

n = int(input("Enter Size of List: "))
for i in range(n):
    l.append(int(input("Enter the list:")))

print("List:", l, "\n")

p=ne=z=e=o=0
for i in l:
    if (i>0):
        p+=1
    elif(i<0):
        ne=ne+1
    else:
        z=z+1
print("Stats:-\nPositive Numbers:%d\nNegative Numbers:%d"%(p,ne))
for i in l:
    if(i%2 == 0 and i!=0):
        e=e+1
    elif(i%2 != 0):
        o=o+1
print("Zeroes:%d\nEven Numbers:%d\nOdd Numbers:%d"%(z,e,o))

print("Sum: ",sum(l))
print("Average: ",sum(l)/n)
