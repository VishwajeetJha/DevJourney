# Chatbot with exception handling
import datetime

def chatbot_response(user_input):
    try:
        # Convert user input to lowercase for case-insensitive matching
        user_input = user_input.lower().strip()

        if not user_input:
            return "It seems you didn't enter anything. Can you please type your question?"

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
       
