# 7B:

#Create Two Different sets with the data.
set1={'Hello', 24, False, 69, 42}
set2={'World', 10.5, True, 88, 42}
#Print set items
print("Set 1: ", set1)
print("Set 2: ", set2)
sset1={1,2,3,4}     #set only for subset function
sset2={3,4}     #set only for subset function
#Add/Remove items in/from set
set1.add('abc')
set2.add('def')
print("(Adding) Updated Set 1: ", set1)
print("(Adding) Updated Set 2: ", set2)
set1.remove('Hello')
set2.remove('World')
print("(Removing) Updated Set 1: ", set1)
print("(Removing) Updated Set 2: ", set2)
#UNION, INTERSECT, DIFFERENCE, SYMMETRIC DIFFERENCE, CHECK SUBSET OF ANOTHER SET
print("Set1 Union Set2: ", set1 | set2)
print("Set1 Difference Set2: ", set1 - set2)
print("Set1 Symmetric Difference Set2: ", set1 ^ set2)
print("Set1 Intersect Set2: ", set1 & set2)
print("Is sset1 a Subset of sset2? :", sset2 <= sset1)  #<= subset operator