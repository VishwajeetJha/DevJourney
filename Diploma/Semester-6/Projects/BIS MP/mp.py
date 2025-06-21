import tkinter as tk
from tkinter import filedialog, messagebox, simpledialog
from PIL import Image
import os

MARKER = "STEGANO_MARK"
PIXEL_LIMIT = 200000  # Increased pixel limit for larger text storage

def encode_text_length(text):
    """Encodes text length as a 16-bit binary string."""
    return format(len(text), '016b')  # 16-bit binary representation

def decode_text_length(binary_data):
    """Decodes a 16-bit binary string to get the text length."""
    return int(binary_data[:16], 2)  # Convert first 16 bits back to integer

def check_marker(image_path):
    """Checks if an image contains the marker indicating hidden text."""
    try:
        img = Image.open(image_path)
        data = list(img.getdata())

        binary_text = "".join(str(pixel[0] & 1) for pixel in data[:PIXEL_LIMIT])
        extracted_bytes = [binary_text[i:i+8] for i in range(0, len(binary_text), 8)]
        extracted_text = ''.join(chr(int(byte, 2)) for byte in extracted_bytes if int(byte, 2) > 0)

        return MARKER in extracted_text  # True if marker is found
    except Exception:
        return False  # Assume no marker if there's an error

def select_image():
    """Handles image selection and adjusts UI based on marker detection."""
    global selected_image
    file_path = filedialog.askopenfilename(filetypes=[("Image Files", "*.png;*.jpg;*.jpeg")])
    
    if not file_path:
        return  # No file selected, do nothing

    selected_image = file_path
    has_marker = check_marker(selected_image)  # Check if marker exists in image

    # Adjust UI based on marker presence
    read_btn.pack_forget()
    write_btn.pack_forget()
    modify_btn.pack_forget()

    if has_marker:
        read_btn.pack()   # Show Read button
        modify_btn.pack()  # Show Modify button
    else:
        write_btn.pack()  # Show Write button

def prompt_text_input():
    """Opens a dialog box to get user input for hidden text."""
    text = simpledialog.askstring("Input Hidden Text", "Enter the text to hide in the image:")
    return text.strip() if text else None  # Return stripped text or None if empty

def attach_hidden_text(is_modify=False):
    """Embeds text in an image using LSB steganography."""
    global selected_image
    if not selected_image:
        messagebox.showerror("Error", "No image selected!")
        return

    text_to_hide = prompt_text_input()  # Get text input from dialog box
    if not text_to_hide:
        messagebox.showerror("Error", "No text entered!")
        return

    full_text = MARKER + text_to_hide  # Append marker
    text_binary = encode_text_length(full_text) + ''.join(format(ord(char), '08b') for char in full_text)  # Convert to binary

    img = Image.open(selected_image).convert("RGB")
    data = list(img.getdata())

    # Ensure image has enough pixels to store the message
    if len(text_binary) > len(data):
        messagebox.showerror("Error", "Text is too long for this image.")
        return

    # Modify LSB of red channel only
    new_data = []
    for i, pixel in enumerate(data):
        if i < len(text_binary):
            red = (pixel[0] & ~1) | int(text_binary[i])  # Modify only red channel LSB
            new_pixel = (red, pixel[1], pixel[2])
        else:
            new_pixel = pixel  # Keep remaining pixels unchanged
        new_data.append(new_pixel)

    img.putdata(new_data)

    # Determine save path
    save_path = selected_image if is_modify else f"{os.path.splitext(selected_image)[0]}_steg{os.path.splitext(selected_image)[1]}"
    
    img.save(save_path)

    messagebox.showinfo("Success", f"Hidden text {'modified' if is_modify else 'attached'} successfully!\nSaved as: {save_path}")

    # Hide UI elements after embedding
    write_btn.pack_forget()
    modify_btn.pack()
    read_btn.pack()

def read_hidden_text():
    """Extracts hidden text from an image."""
    global selected_image
    if not selected_image:
        messagebox.showerror("Error", "No image selected!")
        return

    img = Image.open(selected_image)
    data = list(img.getdata())

    # Extract binary data from LSB of red channel
    binary_text = "".join(str(pixel[0] & 1) for pixel in data[:PIXEL_LIMIT])

    # Get the text length from first 16 bits
    text_length = decode_text_length(binary_text)
    binary_text = binary_text[16:16 + (text_length * 8)]  # Extract only the required length

    # Convert binary to text
    extracted_bytes = [binary_text[i:i+8] for i in range(0, len(binary_text), 8)]
    extracted_text = ''.join(chr(int(byte, 2)) for byte in extracted_bytes)

    if MARKER in extracted_text:
        hidden_text = extracted_text.split(MARKER, 1)[1]
        messagebox.showinfo("Hidden Text", f"Extracted Text:\n{hidden_text}")
    else:
        messagebox.showerror("Error", "No hidden text found in this image.")

def exit_program():
    global selected_image
    if selected_image:
        selected_image = None  # Clear the selected image reference
    root.destroy()  # Close the GUI

# Tkinter UI
root = tk.Tk()
root.title("Steganography Tool")
root.minsize(300, 200)

selected_image = None

select_btn = tk.Button(root, text="Select Image", command=select_image)
select_btn.pack()

read_btn = tk.Button(root, text="Read Hidden Text", command=read_hidden_text)
read_btn.pack_forget()  # Initially hidden

write_btn = tk.Button(root, text="Write Hidden Text", command=lambda: attach_hidden_text(is_modify=False))
write_btn.pack_forget()  # Initially hidden

modify_btn = tk.Button(root, text="Modify Message", command=lambda: attach_hidden_text(is_modify=True))
modify_btn.pack_forget()  # Initially hidden

exit_btn = tk.Button(root, text="Exit", command=exit_program)
exit_btn.pack(side="bottom", fill="none")

root.mainloop()