#!/usr/bin/env python
# -*- coding: utf-8 -*-

from collections import deque


def solve():
    n, k = map(int, input().split())
    s = list(input())
    dq = deque([])
    left = (n - k) // 2
    idx = 0
    for i in range(n):
        idx = i
        if left == 0:
            break
        if s[i] == '(':
            dq.append(s[i])
            continue
        dq.pop()
        left -= 1
    print(''.join(dq) + ''.join(s[idx:]))


if __name__ == "__main__":
    solve()
