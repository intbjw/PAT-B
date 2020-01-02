# 没有满分
class School:
    def __init__(self):
        self.name = ''
        self.s = 0
        self.n = 0

    def __lt__(self, other):
        if self.s == other.s:
            if self.n == other.n:
                return self.name < other.name
            return self.n < other.n

        return self.s > other.s


n = eval(input())
l = list()
for i in range(n):
    s = input().split()
    if s[0][0] == "A":
        temp = 1
    elif s[0][0] == "B":
        temp = 1/1.5
    else:
        temp = 1.5
    flag = 0
    for it in l:
        if s[2].lower() == it.name:
            it.n += 1
            it.s = it.s + eval(s[1]) * temp
            flag = 1
            #print(it.name + " " + str(it.s) + " " + str(it.n))
            break
    if flag == 0:
        sch = School()
        sch.name = s[2].lower()
        sch.n = 1
        sch.s = temp * eval(s[1])
        l.append(sch)
for it in l:
    it.s = it.s // 1
l.sort()
print(len(l))
print("1 "+l[0].name+" {} {}".format(int(l[0].s), l[0].n))
    # lambda x: (len(x[0]), x[0])
j = 0
for i in range(1, len(l)):
    if l[i].s == l[i-1].s:
        j += 1
    else:
        j = 0
    print("{} ".format(i + 1 - j) + l[i].name + " {} {}".format(int(l[i].s), l[i].n))
