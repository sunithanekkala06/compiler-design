# Lexical Analyzer in Python

keywords = ["int","float","char","if","else","while","for","return","break","continue"]

program = input("Enter a program line: ")

tokens = program.split()

count = 0

for token in tokens:
    
    if token in keywords:
        print(token, "-> Keyword")
    
    elif token.isdigit():
        print(token, "-> Integer")
    
    elif token.replace('.', '', 1).isdigit():
        print(token, "-> Real Number")
    
    elif token.isidentifier():
        print(token, "-> Identifier")
    
    else:
        print(token, "-> Operator / Symbol")
    
    count += 1

print("Total tokens =", count)