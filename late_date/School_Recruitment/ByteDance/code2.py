while True:
    m, n = map(int, input().split())
    res = []

    for num in range(m, n + 1):
        num = str(num)
        first_num = int(num[0])
        second_num = int(num[1])
        third_num = int(num[2])

        if pow(first_num, 3) + pow(second_num, 3) + pow(third_num, 3) == int(num):
            res.append(pow(first_num, 3) + pow(second_num, 3) + pow(third_num, 3))

    if len(res) == 0:
        print("no")
    else:
        print(" ".join(str(i) for i in res))

