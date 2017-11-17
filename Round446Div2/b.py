def solve():
    n = int(input())
    al = [int(i) for i in input().split()]
    cl = [0]*n
    
    for i in range(n - 1, -1, -1):
        if i - al[i] <= 0:
            cl[0] = min(cl[0], -i)
        else:
            cl[i - al[i]] = min(-al[i], cl[i - al[i]])
    
    idx = 0
    ans = 1
    while idx < n - 1:
        if cl[idx] != 0:
            t = -cl[idx]
            while t > 0 and idx < n - 1:
                idx += 1
                t -= 1
                t = max(t, -cl[idx])
        else:
            ans += 1
            idx += 1
    print(ans)


if __name__=="__main__":
    solve()
