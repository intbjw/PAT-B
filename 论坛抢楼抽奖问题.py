# wdsd
line = input()
line = line.split(' ')
# print(line)
string0 = ""
j = 0
flag = 0
for i in range(eval(line[0])):
    string1 = input()
    if string1 not in string0:
        string0 = string0 + string1
        j = j + 1
        if (j % eval(line[2]) == eval(line[1])):
            print(string1)
