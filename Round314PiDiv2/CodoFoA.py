n = int(input())
li = list(map(int, input().split()))
first = li[0]
last = li[-1]
for i in range(n):
	if i == 0:
		print(abs(first - li[1]), abs(last - first))
	elif i == n - 1:
		print(abs(last - li[-2]), abs(first - last))
	else:
		mi = 10 ** 11
		mi = min(mi, abs(li[i] - li[i-1]))
		mi = min(mi, abs(li[i] - li[i+1]))
		ma = 0
		ma = max(ma, abs(li[i] - first))
		ma = max(ma, abs(li[i] - last))
		print(mi, ma)
