"""
69. x 的平方根
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被舍去 。
"""

def solutionSqrt(num: int):
    """
    遍历法，从左往右遍历区间[0, num)
    """
    i = 0
    while i < num:
        if i*i - num <= 0 and (i+1)*(i+1) - num > 0:
            return i
        else:
            i += 1
    return i


def SqrtBinarySearch(x: int):
    l, r, res = 0, x, -1

    while l <= r:
        mid = (l+r) // 2
        if mid*mid - x <= 0:
            res = l
            l = mid + 1
        else:
            r = mid -1
    return res

def sqrtTaylor(x: int):
    """
    牛顿迭代
    """
    if x == 0:
        return 0

    C, x0 = float(x), float(x)
    while True:
        x1 = 0.5 * (x0 + C / x0)
        if abs(x0 - x1) < 1e-7:
            break
        x0 = x1
    return int(x0)


if __name__ == '__main__':
    num = 6
    print(solutionSqrt(num))
    print(SqrtBinarySearch(num))
    print(sqrtTaylor(num))
