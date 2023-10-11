"""
81. 搜索旋转排序数组 II
已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
例如， [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。
给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。
你必须尽可能减少整个操作步骤。
"""


def search(nums, target):
    if not nums:
        return False

    n = len(nums)
    if n == 1:
        return nums[0] == target

    l, r = 0, len(nums)-1
    while l <= r:
        mid = (l + r) // 2
        if nums[mid] == target:
            return True

        if nums[l] == nums[mid] and nums[r] == nums[mid]:
            l += 1
            r -= 1
        elif nums[l] <= nums[mid]:
            if nums[l] <= target < nums[mid]:
                r = mid -1
            else:
                l = mid + 1
        else:
            if nums[mid] < target < nums[n - 1]:
                l = mid + 1
            else:
                r = mid -1
    return False


"""
154. 寻找旋转排序数组中的最小值 II
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,4,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
你必须尽可能减少整个过程的操作步骤。
"""


def findMin(nums: list):
    """
    不考虑等于
    """
    l, r = 0, len(nums)-1
    while l < r:
        mid = (l + r) // 2  # 隐藏式： l <= mid < j
        print(l, r, mid, nums[mid])
        if nums[mid] > nums[r]:
            l = mid + 1
        elif nums[mid] < nums[r]:
            r = mid
        else:
            r -= 1
    return nums[l]


if __name__ == '__main__':
    nums = [3, 3, 1, 3]
    target = 5
    print(search(nums, target))
    print(findMin(nums))