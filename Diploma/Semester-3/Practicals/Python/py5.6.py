number = 1
list=[]
finallist=[]
def returndivisior(n):
    list.clear()
    for i in range(1, n//2+1):
      if n % i == 0:
       list.append(i)
    return list   
while number < 10000:
# print(divisors_sum)
    divisors_sum = returndivisior(number)  # Calculate the sum of divisors
    sum=0
    for i in divisors_sum:
      sum=sum+i
    if(sum==number):
      finallist.append(number)
    number=number+1
print(finallist)