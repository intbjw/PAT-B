N, p = [eval(i) for i in input().split()]
l = [eval(i) for i in input().split()]
l.sort()
MAX = l[-1]
c = len(l)

for i in range(c):
    # print(i, len(l))
    if l[i] * p >= MAX:
        print(c-i)
        break

