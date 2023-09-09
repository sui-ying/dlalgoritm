# 不使用中间变量，交换两个整型变量`a`和`b`的值

def swap_two_nums(num1: int, num2: int):
    num1 = num1 ^ num2  # XOR: 相同位0，不同为1
    num2 = num1 ^ num2
    num1 = num1 ^ num2
    return num1, num2


if __name__ == '__main__':
    a = 1
    b = 2
    a, b = swap_two_nums(a, b)
    print("a: {}, b: {}".format(a, b))
    