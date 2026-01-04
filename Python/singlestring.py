s1 = input("Enter string1: ")
s2 = input("Enter string2: ")

new_s1 = s2[0] + s1[1:]
new_s2 = s1[0] + s2[1:]
result = new_s1 + new_s2

print("New string:", result)
