string = input()
out = 'PATest'
freq = [0 for i in range(6)]
for s in string:
    inx = out.find(s)
    if inx >= 0:
        freq[inx] += 1
 
while True:
    f = 0
    for i in range(6):
        num = freq[i]
        if num != 0:
            f = 1
            freq[i] -= 1
            print(out[i], sep='', end='')
    if f == 0:
        break