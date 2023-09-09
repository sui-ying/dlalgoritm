"""
写一个删除列表中重复元素的函数，要求去重后元素相对位置保持不变
"""

def delete_repeat_elem(lst: list):
    s1 = set()
    new_lst = []
    for i in range(len(lst)):
        if lst[i] not in s1:  # 集合的in和not in成员运算在性能上远远优于列表
            new_lst.append(lst[i])
            s1.add(lst[i])
    return new_lst


if __name__ == '__main__':
    aa = delete_repeat_elem([1, 2, 3, 4, 5, 4, 3, 2, 1])
    print(aa)