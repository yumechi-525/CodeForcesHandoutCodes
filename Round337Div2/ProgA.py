import math

n = int(input())
if n % 2 == 1:
    print(0)
    exit(0)

n /= 4
ce, fl = math.ceil(n), math.floor(n)
print(fl if ce != fl else fl - 1)
