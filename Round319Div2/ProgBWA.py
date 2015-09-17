n, m = map(int, input().split())
ali = list(map(int, input().split()))
table = [0]
for i in range(n):
    for j in range(len(table)):
        t = table[j] + ali[i]
        if t % m == 0:
            print("YES")
            exit(0)
        table.append(t)
    table = list(set(table))
print("NO")
