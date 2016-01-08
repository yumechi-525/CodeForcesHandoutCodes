from functools import reduce
import operator
from collections import Counter
import copy

MOD = (10 ** 9 + 7)
n = int(input())
arr = [int(i) for i in input().split()]
maxnum = reduce(operator.mul, arr, 1)
cnt = Counter(arr)
for k, v in cnt.items():
    t = k
    while v > 1:
        t *= k % MOD
        arr.append(t)
        v -= 1
table = set(arr)
data = list(table)
for a in arr:
    for d in data:
        if max(d, a) % min(d, a) != 0:
            t = (d * a) % MOD
            if t <= maxnum and t not in table:
                table.add(t)
                data.append(t)
print(sorted(data))
print(reduce(operator.mul, data, 1) % MOD)
