"""Example 1"""
# import tkinter as tk

# # Create a function to handle button click
# def button_click():
#     label.config(text="Button Clicked!")

# # Create the main window
# window = tk.Tk()
# window.title("400x400 GUI Box")

# # Set the window size to 400x400 pixels
# window.geometry("400x400")

# # Create a label widget
# label = tk.Label(window, text="Hello, GUI!", font=("Helvetica", 16))
# label.pack(pady=20)

# # Create a button widget
# button = tk.Button(window, text="Click Me", command=button_click)
# button.pack()

# # Start the main loop
# window.mainloop()

"""Example 2"""
# import tkinter as tk

# # Create a Tkinter window
# root = tk.Tk()

# # Create a label to instruct the user
# label = tk.Label(root, text="Enter something:")
# label.pack()

# # Create an Entry widget for user input
# input_field = tk.Entry(root)
# input_field.get()

# # Function to handle user input
# def get_user_input():
#     user_text = input_field.get()
#     result_label.config(text=f"You entered: {user_text}")

# # Create a button to submit the input
# submit_button = tk.Button(root, text="Submit", command=get_user_input)
# submit_button.pack()

# # Create a label to display the result
# result_label = tk.Label(root, text="")
# result_label.pack()

# # Start the Tkinter main loop
# root.mainloop()

"""Example 3"""
# import tkinter as tk

# # Create the main window
# window = tk.Tk()
# window.title("Attractive GUI Example")
# window.geometry("400x300")

# # Define a color palette
# background_color = "#f0f0f0"
# button_color = "#007acc"
# button_text_color = "white"

# # Create a label
# label = tk.Label(window, text="Welcome to My App", font=("Helvetica", 16), bg=background_color)
# label.pack(pady=20)

# # Create a button with a custom style
# button = tk.Button(window, text="Click Me", bg=button_color, fg=button_text_color, font=("Helvetica", 12))
# button.pack(pady=10, padx=20)

# # Create an entry widget
# entry = tk.Entry(window, font=("Helvetica", 12))
# entry.pack(pady=10, padx=20)

# # Create a frame for organization
# frame = tk.Frame(window, bg=background_color)
# frame.pack(pady=10)

# # Create two buttons in the frame
# button1 = tk.Button(frame, text="Button 1", bg=button_color, fg=button_text_color, font=("Helvetica", 12))
# button1.pack(side="left", padx=10)
# button2 = tk.Button(frame, text="Button 2", bg=button_color, fg=button_text_color, font=("Helvetica", 12))
# button2.pack(side="left", padx=10)

# # Main loop to start the application
# window.mainloop()

# """Example 4"""
# import tkinter as tk

# # Create the main window
# window = tk.Tk()
# window.title("Buttons at Top Right")
# window.geometry("400x300")

# # Create a frame to hold the buttons
# button_frame = tk.Frame(window)
# button_frame.pack(side="top", fill="both", expand=True)

# # Create two buttons
# button1 = tk.Button(button_frame, text="Button 1")
# button2 = tk.Button(button_frame, text="Button 2")

# # Position the buttons in the top-right corner
# button1.pack(side="right")
# button2.pack(side="right")

# # Main loop to start the application
# window.mainloop()


import tkinter as tk
from tkinter import ttk

def on_button_click():
    label.config(text="Hello, " + entry.get())

# Create the main window
root = tk.Tk()
root.title("Beautiful GUI")

# Create and configure a style for ttk
style = ttk.Style()
style.configure("TButton", padding=10, relief="flat", background="#4CAF50", foreground="white")
style.configure("TEntry", padding=10, relief="flat")

# Create widgets with the configured style
label = tk.Label(root, text="Enter your name:")
label.pack(pady=10)

entry = ttk.Entry(root, style="TEntry")
entry.pack(pady=10)

button = ttk.Button(root, text="Click Me", command=on_button_click, style="TButton")
button.pack(pady=10)

# Start the main loop
root.mainloop()
