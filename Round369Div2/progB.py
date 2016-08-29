def solve():
    n = int(input())
    if n == 1:
        print(1)
        return

    cells = [[int(i) for i in input().split()] for _ in range(n)]
    calcset = set([])
    include0num = -1
    for i in range(n):
        row = 0
        cal = 0
        row0f, cal0f = False, False
        for j in range(n):
            row += cells[i][j];
            cal += cells[j][i];
            row0f |= cells[i][j] == 0
            cal0f |= cells[j][i] == 0
        if row0f or cal0f:
            if (row0f and cal0f) and row != cal:
                print("-1")
                return
            elif row0f:
                include0num = row
            elif cal0f:
                include0num = cal
        if (row == include0num and (not row0f)) \
           or (cal == include0num and (not cal0f)):
                print("-1")
                return
        calcset |= set([row, cal])

    i1, i2 = 0, 0
    i10f, i20f = False, False
    for i in range(n):
        i1 += cells[i][i]
        i2 += cells[i][n-i-1]
        i10f |= cells[i][i] == 0
        i20f |= cells[i][n-i-1] == 0
    if i10f:
        if i1 != include0num:
            print("-1")
            return
    else:
        if i1 == include0num:
            print("-1")
            return
    if i20f:
        if i2 != include0num:
            print("-1")
            return
    else:
        if i2 == include0num:
            print("-1")
            return

    calcset |= set([i1, i2])

    if len(calcset) == 2:
        maxnum, minnum = max(calcset), min(calcset)
        if include0num == minnum:
            print(maxnum - minnum)
        else:
            print("-1")
    else:
        print("-1")

if __name__=="__main__":
    solve()
