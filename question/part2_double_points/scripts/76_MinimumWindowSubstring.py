"""
76
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
"""

import collections


class MinimumWindowSubstring:
    def __init__(self, s: str, t: str):
        self.s = s
        self.t = t

    def check(self, ori, cnt):
        """
        两字典的包含关系
        """
        for k, v in ori.items():
            if cnt[k] < v:
                return False
        return True

    def minWindow(self):
        """
        通过滑动区间(l, r)(双指针)遍历待搜索字符串s找到粗略区间，同时维护unordered_map cnt, 逐渐缩小区间直到找到最小的区间
        """
        length = len(s)
        l, r, minLen, ansL = 0, -1, length+1, -1

        ori, cnt = collections.defaultdict(int), collections.defaultdict(int)  # 定义字典ori 和 cnt, 字符及其频数
        for c in t:
            ori[c] += 1  # 更新目标字典ori

        for c in s:
            cnt[c] += 1  # r向右移动, 更新目标字典cnt
            r += 1

            while self.check(ori, cnt) and l <= r:  # 判断搜索字符串区间是否包含目标字符t， 同时l要小于等于r，确保区间有效
                if r - l + 1 < minLen:
                    minLen = r - l + 1
                    ansL = l

                cnt[s[l]] -= 1  # l向右移动, 更新目标字典cnt
                l += 1
        return "" if ansL == -1 else s[ansL:ansL + minLen]


if __name__ == '__main__':
    s = "ADOBECODEBANC"
    t = "ABC"
    # s = "A"
    # t = "A"
    mws = MinimumWindowSubstring(s, t)
    print(mws.minWindow())
