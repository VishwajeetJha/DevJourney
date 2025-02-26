import tkinter as tk
from tkinter import filedialog, messagebox
import openai
import pdfplumber

# OpenAI sKey
#openai.api_key = 'did you think I'd let this stay here ? :3'

def exPdfText(file_path):
    with pdfplumber.open(file_path) as pdf:
        text = ''
        for page in pdf.pages:
            text += page.extract_text()
    return text

#Using chatgpt to parse text then sort them into various fields
def parseResume(text):
    prompt = f"""
    Please extract and organize the following fields from this resume, and don't bolden text using the double asterisks :
    - Name
    - Email
    - Phone Number
    - Skills
    - Work Experience
    - Education
    - Languages
    - Contact Details
    Resume content:
    {text}
    """
    
    try:
        response = openai.ChatCompletion.create(
            model="gpt-4-turbo",  # Use GPT-4
            messages=[
                {"role": "system", "content": "You are a resume parsing assistant."},
                {"role": "user", "content": prompt}
            ],
            max_tokens=1500,
            temperature=0.0
        )
        return response['choices'][0]['message']['content'].strip()
    
    #handling exception also printing the exception, since I cannot find out what is causing a "{text}" error
    except Exception as e:
        print(f"Error calling OpenAI API: {e}")
        return "Error calling OpenAI API"

# as the name suggests
def chooseFile():
    file_path = filedialog.askopenfilename(
        filetypes=[("PDF files", "*.pdf")]
    )
    
    if file_path:
        try:
            text = exPdfText(file_path)
            
            # debugging: printing the extracted text to see if it's working( the pdfplumber)
            print(f"Extracted text: {text}")
            
            if not text:
                messagebox.showerror("Error", "No text extracted from the PDF")
                return
            
            result = parseResume(text)
            
            text_box.delete(1.0, tk.END)
            text_box.insert(tk.END, result)
            
        except Exception as e:
            messagebox.showerror("Error", f"An error occurred: {e}")

#Tk stuff
root = tk.Tk()
root.title("Resume Parser GUI")

root.geometry("800x600")

canvas = tk.Canvas(root, height=600, width=800, bg="#263D42")
canvas.pack(fill="both", expand=True)

upload_button = tk.Button(root, text="Upload Resume", command=chooseFile)
canvas.create_window(400, 50, window=upload_button)

text_box = tk.Text(root, wrap=tk.WORD, width=80, height=25)
canvas.create_window(400, 350, window=text_box)

root.mainloop()
