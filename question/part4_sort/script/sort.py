# coding=utf-8

class Sort:

    def __init__(self, arr: list):
        self.arr = arr
        self.length = len(self.arr)

    def swap(self, num1, num2):
        tmp = num1
        num1 = num2
        num2 = tmp
        return num1, num2

    def bubble_sort(self):
        for i in range(self.length-1):
            for j in range(0, self.length-1-i):
                if self.arr[j] > self.arr[j+1]:
                    self.arr[j], self.arr[j+1] = self.swap(self.arr[j], self.arr[j+1])
        return self.arr

    def insert_sort(self):
        for i in range(1, self.length):
            base = self.arr[i]
            j = i-1
            while j >= 0 and self.arr[j] > base:
                self.arr[j+1] = self.arr[j]
                j -= 1
            self.arr[j+1] = base
        return self.arr

    def selection_sort(self):
        """
        O(n)=O(n^2), T(n)=O(1)
        :param arr:
        :return:
        """
        for i in range(self.length):
            for j in range(i+1, self.length):
                if self.arr[i] > self.arr[j]:
                    tmp = self.arr[i]
                    self.arr[i] = self.arr[j]
                    self.arr[j] = tmp
        return self.arr

    def quick_sort_main(self, start, end):
        """
        挑选一个中间数，使得左边数都小于等于该数，右边数大于等于该数
        """
        if start >= end:
            return
        mid_data, left, right = self.arr[start], start, end
        while left < right:
            while self.arr[right] >= mid_data and left < right:
                right -= 1
            self.arr[left] = self.arr[right]
            # print(right, self.arr)
            while self.arr[left] < mid_data and left < right:
                left += 1
            self.arr[right] = self.arr[left]
            # print(left, self.arr)
        self.arr[left] = mid_data
        # print(self.arr, "\n")
        self.quick_sort_main(start, left - 1)
        self.quick_sort_main(left + 1, end)
        return self.arr

    def quick_sort(self):
        return self.quick_sort_main(0, self.length-1)

    def quick_sort_plus_main(self, lst):
        if len(lst) <= 1:
            return lst
        else:
            pivot = lst[0]  # 选择第一个元素作为基准值
            less = [x for x in lst[1:] if x <= pivot]  # 小于等于基准值的子数组
            greater = [x for x in lst[1:] if x > pivot]  # 大于基准值的子数组
            return self.quick_sort_plus_main(less) + [pivot] + self.quick_sort_plus_main(greater)

    def quick_sort_plus(self):
        return self.quick_sort_plus_main(self.arr)

    def merge(self, nums: list, left: int, mid: int, right: int):
        """

        左子数组区间 [left, mid]
        右子数组区间 [mid + 1, right]
        初始化辅助数组
        :param left:
        :param mid:
        :param right:
        :return:
        """
        tmp = list(nums[left: right + 1])
        # 左子数组的起始索引和结束索引
        left_start = 0
        left_end = mid - left
        # 右子数组的起始索引和结束索引
        right_start = mid + 1 - left
        right_end = right - left
        # i, j 分别指向左子数组、右子数组的首元素
        i = left_start
        j = right_start
        # 通过覆盖原数组 nums 来合并左子数组和右子数组
        for k in range(left, right + 1):
            # 若“左子数组已全部合并完”，则选取右子数组元素，并且 j++
            if i > left_end:
                nums[k] = tmp[j]
                j += 1  # 否则，若“右子数组已全部合并完”或“左子数组元素 <= 右子数组元素”，则选取左子数组元素，并且 i++
            elif j > right_end or tmp[i] <= tmp[j]:
                nums[k] = tmp[i]
                i += 1  # 否则，若“左右子数组都未全部合并完”且“左子数组元素 > 右子数组元素”，则选取右子数组元素，并且 j++
            else:
                nums[k] = tmp[j]
                j += 1

    def merge_sort_main(self, nums: list, left: int, right: int):
        """ 归并排序"""
        # 终止条件
        if left >= right:
            return  # 当子数组长度为 1 时终止递归
        # 划分阶段
        mid = (left + right) // 2  # 计算中点
        self.merge_sort_main(nums, left, mid)  # 递归左子数组
        self.merge_sort_main(nums, mid + 1, right)  # 递归右子数组
        # 合并阶段
        self.merge(nums, left, mid, right)

    def merge_sort(self):
        self.merge_sort_main(self.arr, 0, self.length-1)
        return self.arr


if __name__ == '__main__':
    array = [10, 17, 50, 7, 30, 30, 27, 45, 15, 5, 36, 21]
    print(array)
    sort = Sort(array)
    # print(sort.bubble_sort())
    # print(sort.insert_sort())
    print(sort.quick_sort())
    # print(sort.quick_sort_plus())
    # print(sort.selection_sort())
    # print(sort.merge_sort())