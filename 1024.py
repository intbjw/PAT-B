import re

s = input()
m = r'([+-])(\d+.\d+)E([+-])0*(\d+)'


def replace(m):
    N = eval(m.group(1) + m.group(2))
    print(N)
    M = eval(m.group(4))
    print(M)
    if m.group(3) == '+':
        res = N * (10 ** M)
    else:
        res = N / (10 ** M)

    return str(res)


print(re.sub(m, replace, s))
