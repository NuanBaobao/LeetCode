# 手串
colorDict = dict()


def inputDate():
    res = 0
    n, m, c = map(int, input().split())  # 输入串数 位置数 颜色数
    for i in range(1, n + 1):
        num = list(map(int, input().split()))
        for color in num[1:]:  # 以颜色为键 位置为值建立字典
            if color in colorDict:
                colorDict[color].append(i)
            else:
                colorDict[color] = [i]
    # 统计计数
    for key, value in colorDict.items():
        # print(key, value)
        if len(value) < m:  # 如果位置数少于m
            print("位置数少于m")
            continue
        else:
            # 遍历位置
            for i in range(len(value) - 1):
                if value[i + 1] - value[i] < m or value[i] + n - value[i+1] < m:
                    res += 1
                    print("颜色不满足")
                    break  # 颜色不满足
                else:
                    print("继续检查")
                    continue

    print(res)


if __name__ == "__main__":
    inputDate()
