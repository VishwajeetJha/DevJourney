from matplotlib import pyplot as plt
def relu(x):
    return max(0, x)
# Create data points
x_values = [i for i in range(-5, 6)]
y_values = [relu(x) for x in x_values]
# Plotting
plt.figure(figsize=(8, 6))
plt.plot(x_values, y_values, label='ReLU Function', color='blue')
plt.xlabel('x')
plt.ylabel('ReLU(x)')
plt.title('ReLU Function: y = max(0, x)')
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.grid(True)
plt.legend()
plt.show()