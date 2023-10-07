"""
167
在一个增序的整数数组里找到两个数，使它们的和为给定值。已知有且只有一对解。
"""

def twoNums(nums, target):
    l, r = 0, len(nums) - 1
    while l < r:
        total = nums[l] + nums[r]
        if total == target:
            return [l, r]
        elif total < target:
            l += 1
        else:
            r -= 1
    return [-1, 1]


if __name__ == '__main__':
    numbers = [2,7,11,15]
    target = 9
    print(twoNums(numbers, target))

