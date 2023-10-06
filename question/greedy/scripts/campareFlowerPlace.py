
class Solution:
    def __init__(self, arr: list, n: int):
        self.flower = arr
        self.n = n

    def compareFlowerPlace(self):
        # 特例
        if self.n == 0:
            return True
        if self.flower == 1 and self.flower[0] == 0:
            return 1 >= self.n

        length = len(self.flower)
        for i in range(length):
            if i == 0:
                if self.flower[i] == 0 and self.flower[i+1] == 0:
                    self.flower[i] = 1
                    self.n -= 1
                    if self.n == 0:
                        return True
            elif i == length-1:
                if self.flower[i] == 0 and self.flower[i-1] == 0:
                    self.flower[i] = 1
                    self.n -= 1
                    if self.n == 0:
                        return True
            else:
                if self.flower[i] == 0 and self.flower[i-1] == 0 and self.flower[i+1] == 0:
                    self.flower[i] = 1
                    self.n -= 1
                    if self.n == 0:
                        return True
        return False

    def compareFlowerPlacePlus(self) -> bool:
        count, m, prev = 0, len(self.flower), -1
        for i in range(m):
            if self.flower[i] == 1:
                if prev < 0:
                    count += i // 2
                else:
                    count += (i - prev - 2) // 2
                if count >= n:
                    return True
                prev = i

        if prev < 0:
            count += (m + 1) // 2
        else:
            count += (m - prev - 1) // 2

        return count >= n


if __name__ == '__main__':
    flower = [1,0,0,0,1,0,0]
    n = 2
    solution = Solution(flower, n)
    # print(solution.compareFlowerPlace())
    print(solution.compareFlowerPlacePlus())