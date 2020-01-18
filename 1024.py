import re
s = input()
m = r'([+-])(\d+.\d+)E([+-])0*(\d+)'


def replace(m):
    N = eval(m.group(1) + m.group(2))
    M = eval(m.group(4))
    flag = 1
    if m.group(3) == '+':
        flag = -1
        res = N * (10 ** M)
    else:
        res = N / (10 ** M)
    if m.group(3) == '+' and M >= (s.find('E') - s.find('.')):
        w = 0
    else:
        w = s.find('E') - s.find('.') + M * flag - 1
    res = format(res, '.'+str(w)+'f')
    return str(res)


print(re.sub(m, replace, s))

