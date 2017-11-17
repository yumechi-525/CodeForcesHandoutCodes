def solve():
    n = int(input())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]
    asum = sum(a)
    b.sort()
    print("YES" if b[-1] + b[-2] >= asum else "NO")

if __name__=="__main__":
    solve()
