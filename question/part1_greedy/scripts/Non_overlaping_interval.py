"""
给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
"""


def NOI(list2d):
    if len(list2d) == 1:
        return 0

    list2d.sort(key=lambda x: x[1])
    print(list2d)
    res = 0
    preNode = list2d[0][1]
    for i in range(1, len(list2d)):
        if list2d[i][0] < preNode:
            res += 1
        else:
            preNode = list2d[i][1]
    return res


if __name__ == '__main__':
    arr2d = [[1, 2], [2, 4], [1, 3]]
    print(NOI(arr2d))
