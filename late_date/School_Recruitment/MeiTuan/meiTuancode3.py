n, m1, m2 = map(int, input().split())

m1Left = list(map(int, input().split()))
m1Right = list(map(int, input().split()))
m2Left = list(map(int, input().split()))
m2Right = list(map(int, input().split()))

m1Max = max(m1Right)
m2Max = max(m2Right)

place = [0] * n
# print(place)
# m1
for i in range(m1):
    for j in range(m1Left[i], m1Right[i] + 1):
        place[j-1] += 1
for i in range(m2):
    for j in range(m2Left[i], m2Right[i] + 1):
        place[j-1] += 1

res = n - place.count(0) - place.count(1)
print(res)
