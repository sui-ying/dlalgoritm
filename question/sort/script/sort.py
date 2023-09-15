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
        if start >= end:
            return
        mid_data, left, right = self.arr[start], start, end
        while left < right:
            while self.arr[right] >= mid_data and left < right:
                right -= 1
            self.arr[left] = self.arr[right]
            while self.arr[left] < mid_data and left < right:
                left += 1
            self.arr[right] = self.arr[left]
        self.arr[left] = mid_data
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
        

if __name__ == '__main__':
    array = [10, 17, 50, 7, 30, 30, 27, 45, 15, 5, 36, 21]

    sort = Sort(array)
    # print(sort.bubble_sort())
    print(sort.insert_sort())
    # print(sort.quick_sort())
    # print(sort.quick_sort_plus())
    # print(sort.selection_sort())