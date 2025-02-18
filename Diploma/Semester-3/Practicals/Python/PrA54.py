name = "myName"
age = 88
country = "Bharat"

fstr = "Name: {}, Age: {}, Country: {}".format(name, age, country)
print("Formatted String (format method):", fstr)

centered_text = "Centered Text".center(30, '-')
left_justified_text = "Left Justified Text".ljust(30, '*')
right_justified_text = "Right Justified Text".rjust(30, '~')

print("\nText Justification Examples:")
print(centered_text)
print(left_justified_text)
print(right_justified_text)
