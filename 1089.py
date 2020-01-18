def main():
    N = int(input())
    # 接收输入的正整数 N
    data = []
    for x in range(N):
        data.append(int(input()))
    # 依次读入 N 位玩家的发言， N 个整数

    answer = "No Solution"
    # 先假定没有答案
    for x in range(N):
        for y in range(x + 1, N):
            # 从小序列到大序列依次尝试，就是从（1,2）（1,3）。。。（3,4）的顺序尝试
            if check(data, x, y):
                # 如果让 x, y 作为狼人是符合题意的
                answer = "{} {}".format(x + 1, y + 1)
                break
                # 马上 break 出去，不然可能会被较大序列的狼人对替代
        if answer != "No Solution":
            # 接着上面，马上break 出去
            break

    print(answer)
    # 输出答案


def check(data, x, y):
    # 判断 x, y 作为狼人是否可行
    lies = 0
    # N 位玩家中说谎的人的个数
    liers = []
    # N 位玩家中说谎的人
    wolfs = [x + 1, y + 1]
    # 事实，我们假设 x, y 是狼人，x, y为所讲的下标，加一才是大家编号。

    for index, _ in enumerate(data):
        # 依次检验众人的发言
        if data[index] < 0 and data[index] * -1 not in wolfs:
            # 把好人当成狼人，说谎
            lies += 1
            liers.extend([index])
            # 记录说谎的次数和说谎的人
        if data[index] > 0 and data[index] in wolfs:
            # 把狼人当成好人，说谎
            lies += 1
            liers.extend([index])
            # 记录说谎的次数和说谎的人

    if x in liers and y not in liers and lies == 2:
        # 狼人中有且只有一人说谎 且 共有两人说谎， 符合题意
        return True
    if x not in liers and y in liers and lies == 2:
        # 狼人中有且只有一人说谎 且 共有两人说谎，符合题意
        return True
    # 否则不符合题意
    return False


if __name__ == '__main__':
    main()

# https://blog.csdn.net/A_D_E/article/details/91488940