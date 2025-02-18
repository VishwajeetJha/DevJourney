# Get RGB color code from the user
rgb_hex = input("Enter RGB color code (e.g., #FF6347): ")

#To remove # or Caps the letter
str = rgb_hex.replace("#", "").upper()

red = int(str[0:2], 16)
green = int(str[2:4], 16)
blue = int(str[4:6], 16)

print(f"Red({red}) Green({green}) Blue({blue})")