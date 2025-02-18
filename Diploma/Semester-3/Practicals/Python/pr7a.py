# 7A:

#Create Tuple with Different Datatypes
tuple1=(1, 'ABC', 2.5, True)
#Print Tuple
print("Tuple: ",tuple1)
#Convert Tuple into List
list = list(tuple1)
print("List: ", list)
#Remove Data from List
list.remove(2.5)
print("Updated List: ", list)
#Convert List into Tuple
tuple1 = tuple(list)
#Print Tuple
print("Updated Tuple: ", tuple1)