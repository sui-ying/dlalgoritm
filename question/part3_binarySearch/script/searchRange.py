"""
34. 在排序数组中查找元素的第一个和最后一个位置

给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
"""


def searchRange(nums: list, target: int):
    """
    二分查找 + 区间放大
    """
    l, r = 0, len(nums) - 1
    while l <= r:
        mid = (l + r) // 2
        if nums[mid] == target:
            l, r = mid, mid
            while l - 1 >= 0 and nums[l - 1] == target:
                l -= 1
            while r + 1 <= len(nums) - 1 and nums[r + 1] == target:
                r += 1
            return [l, r]
        elif nums[mid] < target:
            l = mid + 1
        else:
            r = mid - 1
    return [-1, -1]


if __name__ == '__main__':
    nums = [8, 8]
    target = 8
    print(searchRange(nums, target))
