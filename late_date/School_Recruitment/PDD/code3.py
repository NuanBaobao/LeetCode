T = int(input())


def judge(str_s, k):
    # 统计
    chr_dict = {}
    for chr in str_s:
        chr_dict[chr] = str_s.count(chr)
    flag = True
    for key, value in chr_dict.items():
        if value % k != 0:
            flag = False
    if flag:
        print("".join(str(i) for i in str_s))


for i in range(T):
    n, k = map(int, input().split())
    s = list(input())
    judge(s, k)
