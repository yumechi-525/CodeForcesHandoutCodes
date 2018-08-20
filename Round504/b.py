#!/usr/bin/env python
# -*- coding: utf-8 -*-

import math


def solve():
    n, k = map(int, input().split())
    h = k / 2
    if n < k:
        ans = n - math.floor(h)
    elif k <= n:
        ans = math.ceil(h) - 1
    ans = max(0, ans)
    print(ans)


if __name__ == "__main__":
    solve()
