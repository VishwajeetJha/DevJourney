import random
def play_game():
        print("Let's play Rock-Paper-Scissors!")
        user_choice = get_user_choice()
        computer_choice = get_computer_choice()
        result = determine_winner(user_choice, computer_choice)
        print(result)
def get_user_choice():
    while True:
        print("Enter 0 for Rock, 1 for Paper, or 2 for Scissors:")
        user_input = int(input("Your choice: "))
        if user_input in [0, 1, 2]:
            return int(user_input)
        else:
            print("Invalid choice. Please enter 0, 1, or 2.")
def get_computer_choice():
    return random.randint(0, 2)
def determine_winner(user_choice, computer_choice):
    choices = ['rock', 'paper', 'scissors']
    user_choice_name = choices[user_choice]
    computer_choice_name = choices[computer_choice]
    if user_choice == computer_choice:
        return f"It's a tie! Both chose {user_choice_name}."
    elif (user_choice == 0 and computer_choice == 2) or \
         (user_choice == 1 and computer_choice == 0) or \
         (user_choice == 2 and computer_choice == 1):
        return f"You chose {user_choice_name}. Computer chose {computer_choice_name}. You win!"
    else:
        return f"You chose {user_choice_name}. Computer chose {computer_choice_name}. Computer wins!"

play_game()