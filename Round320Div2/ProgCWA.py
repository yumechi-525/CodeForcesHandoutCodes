import math

a, b = map(int, input().split())
low, high = 1, 10 ** 9
mid = (low + high) / 2
for i in range(10000):
    lwa = math.floor(a / low)
    hia = math.floor(a / high)
    lwy = ((a // low - a / low) * low) if lwa % 2 == 1 else ((a // low - a / low) * low * (-1) + low)
    hiy = ((a // high - a / high) * high) if hia % 2 == 1 else ((a // high - a / high) * high * (-1) + high)
    if  abs(b - hiy) > abs(b - lwy):
        high = mid
    else:
        low = mid
    mid = (low + high) / 2
print(low)
