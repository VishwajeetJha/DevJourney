l = []
n=int(input("Enter Size of List: "))

for i in range(0,n):
    l.append(int(input("Enter Item %d: "%(i+1))))
print("List:", l)

p=int(input("\nEnter Element You Want To Delete: "))
l.remove(p)           
print("Updated List:", l)
#ls = 
print("Number of elements:", len(l))
 
print("First element:",l[0])
print("Last element:",l[-1])

l.sort()
print("Sorted list:",l)

l.reverse()
print("Reversed List:", l)
