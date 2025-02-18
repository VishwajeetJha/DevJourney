content = ""
with open("11fa.txt", "r") as f1, open("11fb.txt", "r") as f2:
    content_f1 = f1.read()
    content_f2 = f2.read()

    content_f1 = content_f1.replace(" ", "")
    content_f2 = content_f2.replace(" ", "")

    merged_output = ''.join([char1 + char2 for char1,char2 in zip(content_f1, content_f2)])
    min_len = min(len(content_f1),len(content_f2))

    merged_output += content_f1[min_len:] + content_f2[min_len:]


print(merged_output)