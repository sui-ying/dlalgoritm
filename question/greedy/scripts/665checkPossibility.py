"""
665. 非递减数列
给你一个长度为 n 的整数数组 nums ，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。
我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。
"""


def is_increasing(lst):
    for i in range(1, len(lst)):
        if lst[i] <= lst[i-1]:
            return False
    return True


def checkPossibility(nums: list):
    length = len(nums)
    if length <= 2:
        return True
    seg = 0
    for i in range(length-1):
        x = nums[i]
        y = nums[i+1]
        if x > y:
            seg += 1
            if seg > 1:
                return False
            if i>0 and y<nums[i-1]:
                nums[i+1] = x
    return True


if __name__ == '__main__':
    arr = [-1, 4, 2, 3]
    print(checkPossibility(arr))