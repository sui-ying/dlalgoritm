
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
        po, seq = seq[0], seq[1:]
        left_arr = [x for x in seq if x <= po]
        right_arr = [x for x in seq if x >= po]
        return left_arr, po, right_arr

    def by_quick_sort_main(self, seq, k):
        left_arr, po, right_arr = self.partition(seq)
        m = len(left_arr)
        if m == k:
            return po
        if m < k:
            return self.by_quick_sort_main(right_arr, k-m-1)

    def by_quick_sort(self):
        self.by_quick_sort_main(self.arr, self.k)
        return self.arr[: k]


if __name__ == '__main__':
    array = [10, 17, 50, 7, 30, 30, 27, 45, 15, 5, 36, 21]
    k = 5
    topk = Topk(array, k)
    print(topk.by_bubble_sort())
    print(topk.by_quick_sort())