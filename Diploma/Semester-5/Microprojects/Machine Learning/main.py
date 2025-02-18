import tkinter as tk
from tkinter import ttk
import joblib
import numpy as np
import pandas as pd

# Load the data and the saved stacking model
data = pd.read_csv('')  # Update the path
model = joblib.load('')  # Update the path

# Function to dynamically update dropdown menus based on selected car
def update_dropdowns(event):
    selected_car = car_var.get()
    
    # Filter the dataset for the selected car
    car_data = data[data['name'] == selected_car]
    
    # Get unique values for 'fuel', 'transmission', and 'year'
    unique_fuels = car_data['fuel'].unique()
    unique_transmissions = car_data['transmission'].unique()
    unique_years = car_data['year'].unique()
    
    # Update the fuel, transmission, and year dropdowns
    fuel_menu['values'] = list(unique_fuels)
    transmission_menu['values'] = list(unique_transmissions)
    year_menu['values'] = list(unique_years)
    
    # Set default selections
    fuel_var.set(unique_fuels[0])
    transmission_var.set(unique_transmissions[0])
    year_var.set(unique_years[0])

# Function to predict the selling price
def predict_price():
    # Get user input
    car_name = car_var.get()
    car_year = int(year_var.get())
    km_driven = int(km_entry.get())
    fuel_type = fuel_var.get()
    transmission_type = transmission_var.get()
    owner_type = owner_var.get()
    seller_type = seller_var.get()  # Get seller type from user

    car_age = 2024 - car_year  # Calculate car age
    
    # Prepare the input features in the raw form (before any encoding)
    input_data = pd.DataFrame({
        'km_driven': [km_driven],
        'car_age': [car_age],
        'fuel': [fuel_type],
        'transmission': [transmission_type],
        'owner': [owner_type],
        'seller_type': [seller_type]  # Include seller type
    })

    # Make prediction using the trained stacking model
    predicted_price = np.exp(model.predict(input_data))[0]  # Convert log back to original scale
    result_label.config(text=f"Predicted Selling Price: ₹ {predicted_price:,.2f}")


# Create the GUI window
root = tk.Tk()
root.title("Car Price Prediction")

# Input fields
ttk.Label(root, text="Select Car").grid(row=0, column=0)
car_var = tk.StringVar()
car_menu = ttk.Combobox(root, textvariable=car_var)
car_menu['values'] = list(data['name'].unique())  # Populate with car names from the CSV
car_menu.grid(row=0, column=1)
car_menu.bind("<<ComboboxSelected>>", update_dropdowns)  # Bind the update function to car selection

# Year dropdown
ttk.Label(root, text="Year").grid(row=1, column=0)
year_var = tk.StringVar()
year_menu = ttk.Combobox(root, textvariable=year_var)
year_menu.grid(row=1, column=1)

# Kilometers Driven entry
ttk.Label(root, text="Kilometers Driven").grid(row=2, column=0)
km_entry = ttk.Entry(root)
km_entry.grid(row=2, column=1)

# Seller Type dropdown
ttk.Label(root, text="Seller Type").grid(row=6, column=0)
seller_var = tk.StringVar()
seller_menu = ttk.Combobox(root, textvariable=seller_var)
seller_menu['values'] = ['Dealer', 'Individual']  # Possible options based on the dataset
seller_menu.grid(row=6, column=1)

# Fuel Type dropdown
ttk.Label(root, text="Fuel Type").grid(row=3, column=0)
fuel_var = tk.StringVar()
fuel_menu = ttk.Combobox(root, textvariable=fuel_var)
fuel_menu.grid(row=3, column=1)

# Transmission dropdown
ttk.Label(root, text="Transmission").grid(row=4, column=0)
transmission_var = tk.StringVar()
transmission_menu = ttk.Combobox(root, textvariable=transmission_var)
transmission_menu.grid(row=4, column=1)

# Owner Type dropdown
ttk.Label(root, text="Owner Type").grid(row=5, column=0)
owner_var = tk.StringVar()
owner_menu = ttk.Combobox(root, textvariable=owner_var)
owner_menu['values'] = ['First Owner', 'Second Owner', 'Third Owner', 'Fourth & Above Owner']
owner_menu.grid(row=5, column=1)

# Prediction button
predict_button = ttk.Button(root, text="Predict Price", command=predict_price)
predict_button.grid(row=7, column=1)

# Label to show result
result_label = ttk.Label(root, text="Predicted Selling Price will appear here")
result_label.grid(row=8, column=0, columnspan=2)

# Run the GUI loop
root.mainloop()
