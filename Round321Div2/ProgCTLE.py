n, m = map(int, input().split())
l = list(map(int, input().split()))
d = {}
for i in range(n-1):
    a, b = map(int, input().split())
    if a not in d:
        d.update({a:[b]})
    else:
        d[a].append(b)
    if b not in d:
        d.update({b:[a]})
    else:
        d[b].append(a)

visited = [1]
current = [1, (0 if l[0] == 0 else 1)]
que = []
firstcat = 1 if l[0] == 1 else 0
for i in d[1]:
    que.append([i, firstcat])

res = 0
while len(que) > 0:
    current = que.pop(0)
    visited.append(current[0])
    if l[current[0]-1] == 1:
        current[1] += 1
        if current[1] > m:
            continue
    else:
        current[1] = 0
    if len(d[current[0]]) == 1:
        if current[1] <= m:
            res += 1
        continue
    for i in d[current[0]]:
        if i not in visited:
            que.append([i, current[1]])
print(res)
