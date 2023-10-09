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


"""
633. 平方数之和
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。
"""
def judgeSquareSum(target: int) -> bool:
    import math
    num = int(math.sqrt(target))
    l, r = 0, num
    while l <= r:
        res = l*l + r*r
        if res == target:
            return l, r
        elif res < target:
            l += 1
        elif res > target:
            r -= 1
    return False


"""
680. 验证回文串 II
请你判断 s 是否能成为回文字符串：如果能，返回 true ；否则，返回 false 。
"""

def isValidPalindrome(s: str) -> bool:
    l, r = 0, len(s)-1
    while l < r:
        if s[l] != s[r]:
            return False
        else:
            l += 1
            r -= 1
    return True

def validPalindrome(s: str) -> bool:
    l, r = 0, len(s)-1
    while l < r:
        if s[l] == s[r]:
            l += 1
            r -= 1
        else:
            return isValidPalindrome(s[l+1: r]) or isValidPalindrome(s[l: r-1])
    return True

if __name__ == '__main__':
    numbers = [2,7,11,15]
    target = 9
    # print(twoNums(numbers, target))
    # print(judgeSquareSum(2))
    print(validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"))
