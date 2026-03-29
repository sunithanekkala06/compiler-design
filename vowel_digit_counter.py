# Count vowels, consonants, and digits

string = input("Enter a string: ")

vowels = 0
consonants = 0
digits = 0

for ch in string:
    if ch.isalpha():
        if ch.lower() in "aeiou":
            vowels += 1
        else:
            consonants += 1
    elif ch.isdigit():
        digits += 1

print("Vowels:", vowels)
print("Consonants:", consonants)
print("Digits:", digits)