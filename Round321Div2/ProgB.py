n, d = map(int, input().split())
al = [list(map(int, input().split())) for _ in range(n)]
al.sort()
res = al[0][1]
t = al[0][1]
idx = 0
for i in range(1, n):
    if al[i][0] - al[idx][0] < d:
        t += al[i][1]
    else:
        while al[i][0] - al[idx][0] >= d:
              t -= al[idx][1]
              idx += 1
        t += al[i][1]
    res = max(res, t);
print(res)
