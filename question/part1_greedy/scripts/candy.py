"""
一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
有孩子至少要有一个糖果。求解最少需要多少个糖果。
"""


def candy(arr: list):
    length = len(arr)
    res = [1] * length
    for i in range(1, length):
        if arr[i] > arr[i-1]:
            res[i] += 1
    for i in range(length-2, -1, -1):
        if arr[i] > arr[i+1]:
            res[i] += 1
    return sum(res)


if __name__ == '__main__':
    array = [1, 0, 2]
    print(candy(array))