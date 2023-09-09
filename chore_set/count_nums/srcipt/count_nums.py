"""
写一个函数统计传入的列表中每个数字出现的次数并返回对应的字典
"""


def count_nums(lst: list):
    result = {}
    for i in range(len(lst)):
        if lst[i] not in result.keys():
            result[lst[i]] = 1
        else:
            result[lst[i]] += 1
    return result


if __name__ == '__main__':
    nums = [1, 2, 3, 2, 1, 4]
    print(count_nums(nums))