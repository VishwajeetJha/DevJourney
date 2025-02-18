# 7C:

# Create a Dictionary
dict={0:'308',1:'302',2:'295',49:'000'}
dict2={3:'Yashraj',4:'Vishwajeet',5:'Kalp'}
# Print Dict Items
print(dict)
# Add Remove Key Value pair in/from dict
dict[32]='New Key'
dict.pop(32)
print("Updated Dictionary 1(pop 32):", dict)
# Check weather key exist or not
for i in dict.keys():
    if(i==2):
        flag=True
    else:
        flag=False
print("Whether key 2 exists in Dictionary: ", flag)
# Iterate Dictionary
for i in dict.items():
    print("Item: ",i)
# Concatenate Dictionary
dict_concatenated = {**dict, **dict2}
print(dict_concatenated)