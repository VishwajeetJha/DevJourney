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
            nl.append(n) 
distinct = []
for i in nl:
    if i not in distinct:
        distinct.append(i)
print("Original values: ", nl)
print("Distinct values:", distinct)