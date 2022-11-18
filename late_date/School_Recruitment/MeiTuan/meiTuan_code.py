n = int(input())
prices = list(map(int, input().split()))
discount_price = list(map(int, input().split()))

# 满减
m = int(input())
price_c = list(map(int, input().split()))
price_d = list(map(int, input().split()))

result = []  # 记录结果

for i in range(1, n + 1):
    # 购买前i
    dis_price = sum(discount_price[:i])
    # print("dis_price", dis_price)
    sum_price = sum(prices[:i])  # 原价和
    # print("sum_price",sum_price)
    # 观察是否满减
    flag = False
    for c in reversed(price_c):
        if sum_price >= c:  # 可以满减
            flag = True
            # print("d",price_d[price_c.index(c)])
            temp_price = sum_price - price_d[price_c.index(c)]  # 满减价格
            # print("temp_price",temp_price)
            if temp_price > dis_price:  # 折扣更优惠
                result.append("Z")
            elif temp_price == dis_price:
                result.append("B")
            else:
                result.append("M")
            break
        else:
            continue
    if flag == False:
        # 没有满减
        # print("没有满减")
        if dis_price == sum_price:
            result.append("B")
        if dis_price < sum_price:
            result.append("Z")

print("".join(str(i) for i in result))
