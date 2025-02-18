# 7E:
import random

score = 0
capital = {
    'Bihar': 'Patna',
    'Gujarat': 'Gandhinagar',
    'Karnataka': 'Bengaluru',
    'Maharashtra': 'Mumbai',
    'Punjab': 'Chandigarh',
    'Rajasthan': 'Jaipur',
    'Uttar Pradesh': 'Lucknow',
    'Madhya Pradesh': 'Bhopal',
    'Tamil Nadu': 'Chennai',
    'Telangana': 'Hyderabad',
    'West Bengal': 'Kolkata'
}
print("Enter 9 to exit-->")
cnt=0
asked_states=[]
while(len(asked_states)<len(capital.keys())):       #while number of states in asked_states 
    cur_state=random.choice(list(capital.keys()))                 #less than the number of states in the dictionary
    cur_ans=capital[cur_state]
    if(cur_state not in asked_states):
        pass
    else:
        continue
    print("What is The Capital of",cur_state,end='')
    x=input(": ")
    if(x==capital[cur_state]):
        print("Correct")
        score = score + 1
        cnt = cnt + 1
    elif(x.isdigit() and int(x)==9):
        print("Exiting...")
        break
    else:
        print("Incorrect")
        cnt = cnt + 1
    asked_states.append(cur_state)

print("Your Score out of %d: %d"%(cnt,score))