#!/usr/bin/env python
# -*- coding: utf-8 -*-


def solve():
    n, m = map(int, input().split())
    s, t = input(), input()
    if s.find("*") >= 0:
        ai = s.find("*")
        if t.find(s[:ai]) != 0:
            print("NO")
            return
        if ai == n - 1:
            print("YES")
        else:
            t2 = t[ai:]
            ri = t2.rfind(s[ai + 1:])
            print("YES" if t2[max(0, ri):] == s[ai + 1:] else "NO")
    else:
        print("YES" if s == t else "NO")


if __name__ == "__main__":
    solve()
