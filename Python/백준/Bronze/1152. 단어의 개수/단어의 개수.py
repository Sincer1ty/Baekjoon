str = input()

word = 0

for i in range(len(str)):
    if i == 0:
        if str[i] == " ":
            word = 0 

    elif str[i] == " ":
        word += 1
        
if str[i] != " ":
        word += 1
        
print(word)