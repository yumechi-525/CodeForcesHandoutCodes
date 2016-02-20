terminl, r, k = map(int, input().split())
res = []
if k > r:
    print("-1" if l != 1 else "1")
    exit(0)
num = 1
while num < l:
    num *= k
while l <= num <= r:
    res.append(str(num))
    num *= k
print("-1" if len(res) == 0 else " ".join(res))
