str = input().split()
a, b = [eval(i) for i in str]
n = (b - a + 50) // 100
h = n // 3600
m = n % 3600 // 60
s = n - h * 3600 - m * 60
print('{:0>2d}:{:0>2d}:{:0>2d}'.format(h, m, s))
