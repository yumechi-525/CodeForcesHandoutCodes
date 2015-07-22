n = int(input())
al = list(map(int, input().split()))
print("-1" if min(al) == 1 else "1")