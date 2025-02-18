nl=[]
flag=1
while(flag==1):
    n=input("Enter number('E' to exit): ")
    if(n=='E'):
        flag=0
        break
    else: 
        if n.isdigit():
            n=int(n)
            nl.append(n)
        else:
            print("Enter Valid digit")     
distinct_numbers = []
for i in nl:
    if i not in distinct_numbers:
        distinct_numbers.append(i)
print("All Numbers: ", nl)
print("Distinct numbers:", distinct_numbers)