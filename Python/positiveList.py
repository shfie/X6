user_input = input("Enter numbers separated by spaces: ")
string_numbers = user_input.split()

numbers = []
for s in string_numbers:
    numbers.append(int(s))  # convert each string to int and add to list

positive_numbers = []
for num in numbers:
    if num > 0:
        positive_numbers.append(num)

print("Positive numbers:", positive_numbers)
