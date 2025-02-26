# Chatbot with enhanced responses
import datetime

def chatbot_response(user_input):
    user_input = user_input.lower()

    # Greeting
    if "hello" in user_input or "hi" in user_input:
        return "Hello! How can I assist you today?"

    # Asking about well-being
    elif "how are you" in user_input:
        return "I'm a chatbot, so I don't have feelings, but thanks for asking! How can I assist you?"

    # Time-related query
    elif "time" in user_input:
        current_time = datetime.datetime.now().strftime("%H:%M:%S")
        return f"The current time is {current_time}."

    # Date-related query
    elif "date" in user_input:
        current_date = datetime.datetime.now().strftime("%Y-%m-%d")
        return f"Today's date is {current_date}."

    # Weather-related query
    elif "weather" in user_input:
        return "I can't check the weather right now, but you can check your favorite weather app for the latest update."

    # Asking about the chatbot's name
    elif "your name" in user_input:
        return "I'm just a simple chatbot. You can call me your assistant!"

    # Asking about capabilities
    elif "can you do" in user_input:
        return "I can chat with you, provide basic information, and assist with simple tasks. What would you like to know?"

    # Farewell
    elif "bye" in user_input or "goodbye" in user_input:
        return "Goodbye! Have a great day!"

    # Default response for unknown queries
    else:
        return "I'm sorry, I don't understand that. Could you please rephrase your question?"

if __name__ == "__main__":
    print("Chatbot: Hello! How can I assist you today?")
    while True:
        user_input = input("You: ")
        if user_input.lower() == "exit":
            print("Chatbot: Goodbye! Have a great day!")
            break
        response = chatbot_response(user_input)
        print("Chatbot:", response)