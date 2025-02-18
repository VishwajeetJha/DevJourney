import tkinter as tk
from tkinter import filedialog, messagebox
from pyresparser import ResumeParser  # Better PDF reading capability by Omkar Pathak which uses SpaCy's NLP

# Reading the file
def upload_file():
    file_path = filedialog.askopenfilename(
        filetypes=[("PDF files", "*.pdf"), ("DOCX files", "*.docx")]
    )
    
    if file_path:
        try:
            # Use ResumeParser to extract data
            data = ResumeParser(file_path).get_extracted_data()
            
            # Process the extracted data
            result_text = format_extracted_data(data)
            
            # Display the extracted data
            text_box.delete(1.0, tk.END)
            text_box.insert(tk.END, result_text)
        except Exception as e:
            messagebox.showerror("Error", f"An error occurred: {e}")

def format_extracted_data(data):
    """
    Formatting the data into their respective fields from the pdf
    """
    result = []
    
    # Manually add each piece of data to the result list if it exists
    if 'name' in data:
        result.append(f"Name: {data['name']}")
    if 'email' in data:
        result.append(f"Email: {data['email']}")
    if 'phone_number' in data:
        result.append(f"Phone Number: {data['phone_number']}")
    if 'skills' in data:
        result.append(f"Skills: {', '.join(data['skills'])}")
    if 'experience' in data:
        result.append("Experience:")
        for exp in data['experience']:
            result.append(f"  - {exp}")
    if 'education' in data:
        result.append("Education:")
        for edu in data['education']:
            result.append(f"  - {edu}")
    
    # Joining each field by a newline then the other field
    return '\n'.join(result)

#Tk stuff below
root = tk.Tk()
root.title("Resume Parser GUI")
root.geometry("800x600")  # Set the window size

canvas = tk.Canvas(root, height=600, width=800, bg="#263D42")
canvas.pack(fill="both", expand=True)

frame = tk.Frame(root, bg="white", bd=5)
frame.place(relwidth=0.8, relheight=0.8, relx=0.1, rely=0.1)

upload_button = tk.Button(frame, text="Upload Resume", padx=10, pady=5, fg="white", bg="#263D42", command=upload_file)
upload_button.pack(pady=20)

text_box = tk.Text(frame, wrap=tk.WORD, width=80, height=20)
text_box.pack(padx=20, pady=20)

root.mainloop()
