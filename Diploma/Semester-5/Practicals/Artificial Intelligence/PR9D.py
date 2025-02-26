import numpy as np

# Function to calculate sine, cosine, and tangent of angles
def trigonometric_operations(angles):
    sine_values = np.sin(angles)
    cosine_values = np.cos(angles)
    tangent_values = np.tan(angles)

    return sine_values, cosine_values, tangent_values

# Example array of angles in radians
angles = np.array([0, np.pi/6, np.pi/4, np.pi/3, np.pi/2])

# Calculate sine, cosine, and tangent
sine, cosine, tangent = trigonometric_operations(angles)

print("Sine values:", sine)
print("Cosine values:", cosine)
print("Tangent values:", tangent)
