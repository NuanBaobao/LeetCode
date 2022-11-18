n = int(input())
array_A = list(map(int, input().split()))
array_B = list(map(int, input().split()))

array_A = sorted(array_A)
array_B = sorted(array_B)

result = 0

for i in range(n):
    result += pow(array_A[i] - array_B[i], 2)

print(result)

