text = input("Enter a string: ")

if text.endswith("ing"):
    text += "ly"
else:
    text += "ing"

print(text)
