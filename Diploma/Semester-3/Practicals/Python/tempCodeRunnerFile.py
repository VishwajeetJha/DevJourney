a= int(input("enter your first number"))
b= int(input("enter your second number"))
operator=input("enter your any operator:+-*/")
if operator=='+':
   print('a+b',a+b)
elif operator=='-':
   print('a-b',a-b)
elif operator=='*':
   print('a*b',a*b)
elif operator=='/':
   print('a/b',a/b)
else:
   print('enter right operation')
