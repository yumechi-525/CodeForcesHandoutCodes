def gcd(a, b):
    if a < b:
        a,b = b,a
    while b > 0:
        r = a % b
        a,b = b,r
    return a

def solve():
    n = int(input())
    al = [int(i) for i in input().split()]
    if 1 in al:
        print(n - al.count(1))
        return
    
    ans = -1
    for i in range(n):
        t = al[i]
        for j in range(i + 1, n):
            t = gcd(t, al[j]) 
            if t == 1:
                if ans == -1:
                    ans = (j - i) + (n - 1)
                else:
                    ans = min(ans, (j - i) + (n - 1))
    print(ans)

if __name__=="__main__":
    solve()
