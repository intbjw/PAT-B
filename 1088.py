def printn(t):
    if t == n:
        print(" Ping",end="")
    elif t > n:
        print(" Cong",end="")
    else:
        print(" Gai",end="")


s = input().split()
s = [eval(i) for i in s]
n, x, y = s[0], s[1], s[2]
flag = 0
for i in range(99,9,-1):
    j = i % 10 * 10 + i // 10
    k = abs(i - j) / x
    if j == k * y:
        flag = 1
        print(i ,end="")
        printn(i)
        printn(j)
        printn(k)
        break
if flag == 0:
    print('No Solution')
