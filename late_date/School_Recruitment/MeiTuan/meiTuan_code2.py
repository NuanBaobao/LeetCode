import math

n, t = map(int, input().split())

s = list(input())

t = []


# 加密
while len(s):
    # global s

    mid = len(s) // 2 - 1
    t.append(s[mid])
    # print(t)
    s = s[:mid] + s[mid+1:]
    if len(s) == 1:
        t.append(s[0])
        break
    print(s)



print(t)
