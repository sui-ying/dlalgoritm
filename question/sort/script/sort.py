# coding=utf-8
def quick_sort(array, start, end):
    if start >= end:
        return
    mid_data, left, right = array[start], start, end
    while left < right:
        while array[right] >= mid_data and left < right:
            right -= 1
        array[left] = array[right]
        while array[left] < mid_data and left < right:
            left += 1
        array[right] = array[left]
    array[left] = mid_data
    quick_sort(array, start, left - 1)
    quick_sort(array, left + 1, end)

def quick_sort_plus(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]  # 选择第一个元素作为基准值
        less = [x for x in arr[1:] if x <= pivot]  # 小于等于基准值的子数组
        greater = [x for x in arr[1:] if x > pivot]  # 大于基准值的子数组
        return quick_sort_plus(less) + [pivot] + quick_sort_plus(greater)

if __name__ == '__main__':
    array = [10, 17, 50, 7, 30, 30, 27, 45, 15, 5, 36, 21]
    quick_sort(array, 0, len(array) - 1)
    print(quick_sort_plus(array))