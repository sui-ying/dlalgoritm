"""
88. 合并两个有序数组
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
"""


def merge(nums1, m, nums2, n):
    """
    从后往前遍历，每次将两个数组中末尾数较大的那一个赋给nums1的最后一个位置，依次向前填充
    """

    p1 = m-1
    p2 = n-1
    p = m+n-1
    while p1 >= 0 or p2 >= 0:
        if p1 == -1:  # nums1 需要合并的元素为0时
            nums1[p] = nums2[p2]
            p2 -= 1
        elif p2 == -1:  # nums2 需要合并的元素为0时
            # nums1[p] = nums1[p1]
            # p1 -= 1
            break
        elif nums1[p1] >= nums2[p2]:
            nums1[p] = nums1[p1]
            p -= 1
        elif nums1[p1] < nums2[p2]:
            nums1[p] = nums2[p2]
            p2 -= 1
        p -= 1
    print(nums1)



if __name__ == '__main__':
    nums1 = [0]
    m = 0
    nums2 = [1]
    n = 1
    merge(nums1, m, nums2, n)



