word = input("Enter a word: ")

vowels = ['a', 'e', 'i', 'o', 'u']
vowel_list = []

for char in word.lower():
    if char in vowels:
        vowel_list.append(char)

print("Vowels in the word:", vowel_list)
