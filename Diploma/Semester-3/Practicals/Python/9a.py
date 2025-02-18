import math
def deviation(avg, nm):
    dev = math.sqrt(sum((x - avg) ** 2 for x in nm) / len(nm))
    print("Deviation: %.2f" %(dev))
def mean(): 
    N = int(input("How many numbers: "))
    nm = []
    sum1 = 0
    avg = 0
    for i in range(N):
        nm.append(int(input("Enter number: ")))
    for i in nm:
        sum1 = sum1 + i
        avg = sum1 / len(nm)
    print("Average: ", avg)
    deviation(avg, nm)
#Calling Main Function
mean()