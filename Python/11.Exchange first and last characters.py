
text=input("Enter a string: ")
if len(text) < 2:
    print("String is too short to exchange characters.")
else:
    text = text[-1] + text[1:-1] + text[0]

print("After exchanging first and last characters:",text)


