# Practical 2: Count vowels, digits and special symbols

text = input("Enter a string: ")

vowels = 0
digits = 0
special = 0

for ch in text:
    
    if ch.lower() in "aeiou":
        vowels += 1
    
    elif ch.isdigit():
        digits += 1
    
    elif not ch.isalnum() and ch != " ":
        special += 1

print("Number of vowels:", vowels)
print("Number of digits:", digits)
print("Number of special symbols:", special)