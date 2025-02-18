exp = input("Enter Number: ")
dc = {}
for sym in exp:
    if sym.isdigit():  
        if sym in dc:
            dc[sym] += 1
        else:
            dc[sym] = 1
for d, c in dc.items():
    print("%s: %s times"%(d,c))
