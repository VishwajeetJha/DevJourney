import matplotlib.pyplot as plt

# s = scatter
# h = histogram
# p = pie
# a = area

x_s = [1, 2, 3, 4, 5]
y_s = [10, 12, 5, 8, 15]

x_h = [2, 3, 3, 4, 4, 4, 5, 5, 5, 5]
x_b = ['A', 'B', 'C', 'D']
y_b = [30, 50, 20, 40]

x_a = [1, 2, 3, 4, 5]
y_a = [10, 12, 5, 8, 15]

v_p = [30, 50, 20, 40]
c_p = ['A', 'B', 'C', 'D']

plt.figure(figsize=(12, 8))

plt.subplot(2, 3, 1)
plt.scatter(x_s, y_s, color='blue')
plt.title('Scatter Plot')

plt.subplot(2, 3, 2)
plt.hist(x_h, bins=range(2, 7), color='green', alpha=0.7)
plt.title('Histogram')

plt.subplot(2, 3, 3)
plt.bar(x_b, y_b, color='orange')
plt.title('Bar Graph')

plt.subplot(2, 3, 4)
plt.fill_between(x_a, y_a, color='purple', alpha=0.5)
plt.title('Area Plot')

plt.subplot(2, 3, 5)
explode = (0.1, 0, 0, 0)
plt.pie(v_p, labels=c_p, autopct='%1.1f%%', explode=explode, startangle=140, shadow=True)
plt.title('Pie Plot')

plt.tight_layout()
plt.show()
