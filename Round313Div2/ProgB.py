a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())
a3, b3 = map(int, input().split())

c1 = a1 - a2
c2 = b1 - b2
if c1 >= 0 and c2 >= 0:
    ans = [0, 0, 0, 0]
    ans[0] = 1 if c1 - a3 >= 0 and b1 - b3 >= 0 else 0
    ans[1] = 1 if c1 - b3 >= 0 and b1 - a3 >= 0 else 0
    ans[2] = 1 if a1 - a3 >= 0 and c2 - b3 >= 0 else 0
    ans[3] = 1 if a1 - b3 >= 0 and c2 - a3 >= 0 else 0
    if sum(ans) > 0:
        print("YES")
        exit(0)

d1 = a1 - b2
d2 = b1 - a2
if d1 >= 0 and d2 >= 0:
    ans = [0, 0, 0, 0]
    ans[0] = 1 if d1 - a3 >= 0 and b1 - b3 >= 0 else 0
    ans[1] = 1 if d1 - b3 >= 0 and b1 - a3 >= 0 else 0
    ans[2] = 1 if a1 - a3 >= 0 and d2 - b3 >= 0 else 0
    ans[3] = 1 if a1 - b3 >= 0 and d2 - a3 >= 0 else 0
    if sum(ans) > 0:
        print("YES")
        exit(0)

print("NO")