import math

n, k = map(int, input().split())
li = list(map(int, input().split()))
countmap = {}
finddic = {}
res = 0
for i in range(n):
	t = li[i]
	if t not in countmap:
		countmap.update({t:1})
	else:
		countmap[t] += 1

	if k > 1:
		if t // k in countmap and t // k // k in countmap:
			tres = countmap[t//k] * countmap[t//k//k]
			res += tres

			findli = (t, t//k, t//k//k)
			if findli not in finddic:
				finddic.update({findli:tres})
			else:
				res -= finddic[findli]
				finddic[findli] = tres
	else:
		if countmap[t] == li.count(t):
			res += math.factorial(countmap[t]) // math.factorial(3)
print(res)
