
class Topk:
    def __init__(self, arr: list, k: int):
        self.arr = arr
        self.length = len(self.arr)
        self.k = k

    def by_bubble_sort(self):
        for i in range(self.k):
            for j in range(i+1, self.length):
                if self.arr[i] < self.arr[j]:
                    self.arr[i], self.arr[j] = self.arr[j], self.arr[i]
        return self.arr[: k]

    def partition(self, seq):
        """
        将seq划分为 left_arr, po, right_arr
        """
        po, seq = seq[0], seq[1:]
        left_arr = [x for x in seq if x > po]
        right_arr = [x for x in seq if x <= po]
        return left_arr, po, right_arr

    def by_quick_sort_main(self, seq, k):
        left_arr, po, right_arr = self.partition(seq)
        m = len(left_arr)
        if m + 1 == k:
            return po
        elif m + 1 < k:
            return self.by_quick_sort_main(right_arr, k-m-1)
        else: # m + 1 > k
            return self.by_quick_sort_main(left_arr, k)

    def by_quick_sort(self):
        self.by_quick_sort_main(self.arr, self.k)
        return self.arr[k-1]


def findKthLargest(nums, k):
    def partition(nums, l, r, k):
        if l == r:
            return nums[k]

        p = nums[l]
        i = l
        j = r

        while i < j:
            while nums[i] >= p and i < j:
                i += 1
            while nums[j] < p and i <= j:
                j -= 1

            if i < j:
                nums[i], nums[j] = nums[j], nums[i]

        nums[l], nums[j] = nums[j], nums[l]

        if k == j:
            return nums[j]
        elif k < j:
            return partition(nums, l, j-1, k)
        else:
            return partition(nums, j+1, r, k)

    if k < 1 or k > len(nums):
        return None

    return partition(nums, 0, len(nums)-1, k-1)


if __name__ == '__main__':
    array = [10, 17, 50, 7, 30, 30, 27, 45, 15, 5, 36, 21]
    k = 5
    topk = Topk(array, k)
    print(topk.by_bubble_sort())
    print(topk.by_quick_sort())
    print(findKthLargest([2,1], 2))
