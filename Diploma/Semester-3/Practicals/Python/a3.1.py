grade_list = []
scores = []
flag=1
while(flag==1):
    n=input("Enter score('E' to exit): ")
    if(n=='E'):
        flag=0
        break
    else: 
        if (n.isdigit() and int(n)>0 and int(n)<=100):
             n=int(n)
             scores.append(n)
        else:
            print("------>ERROR: Enter Valid Score!") 

best_score = max(scores)

for score in scores:
    if score >= best_score - 10:
        grade = 'A'
    elif score >= best_score - 20:
        grade = 'B'
    elif score >= best_score - 30:
        grade = 'C'
    elif score >= best_score - 40:
        grade = 'D'
    else:
        grade = 'F'
        
    grade_list.append(grade)

for i,score in enumerate(scores):           #i = 0 and score = first score, and goes 
                                            #vice versa; with the help of enumerate function
    print("Score: %d, Grade: %s"%(score,grade_list[i]))
