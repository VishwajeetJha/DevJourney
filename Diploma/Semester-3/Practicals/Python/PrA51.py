content_to_write = "Hello, this is the content that'll be written to First.txt!\nNew Line..."

# Writing to First.txt
with open("First.txt", "w") as f1:
    f1.write(content_to_write)

with open("First.txt", "r") as f1:
    content_read = f1.read()
    print("\nFirst.txt:-\n{}".format(content_read))

# Writing to Second.txt
with open("Second.txt", "w") as f2:
    f2.write(content_read)

with open("Second.txt", "r") as f2:
    print("\nSecond.txt:-\n{}".format(f2.read()))

