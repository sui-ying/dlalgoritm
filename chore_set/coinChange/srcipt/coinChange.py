"""
现有2元、3元、5元共三种面额的货币, 如果需要找零99元, 一共有多少种找零的方式
"""

def minCoinChange(amount, coins):
    """
    从前往后递推
    :param amount:
    :param coins:
    :return:
    """
    dp = [float('inf')] * (amount + 1)  # 表示组成金额 i 所需的最少硬币数
    dp[0] = 0

    # for i in range(1, amount + 1):
    #     for coin in coins:
    #         if i >= coin:
    #             dp[i] = min(dp[i], dp[i - coin] + 1)

    for coin in coins:
        for i in range(1, amount + 1):
            if i >= coin:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    if dp[amount] == float('inf'):
        return -1
    else:
        return dp[amount]


def minCoinChangePlus(amount, coins):
    """
    从前往后递推
    :param amount:
    :param coins:
    :return:
    """
    dp = [float('inf')] * (amount + 1)  # 表示组成金额 i 所需的最少硬币数
    dp[0] = 0
    dp[2] = 1
    dp[3] = 1
    dp[4] = 2
    dp[5] = 1
    if count <= 5:
        return dp[amount]

    for i in range(6, amount + 1):
        dp[i] = min(dp[i-2], dp[i-3], dp[i-5]) + 1

    return dp[amount] if dp[amount] != float('inf') else -1


def minCoinChange_backforward(amount, coins):
    """
    从前往后递推
    :param amount:
    :param coins:
    :return:
    """
    dp = [float('inf')] * (amount + 1)  # 表示组成金额 i 所需的最少硬币数
    dp[0] = 0
    dp[2] = 1
    dp[3] = 1
    dp[4] = 2
    dp[5] = 1
    if count <= 5:
        return dp[amount]

    for i in range(amount, 5, -1):
        dp[i] = min(dp[i - 2], dp[i - 3], dp[i - 5]) + 1

    return dp[amount] if dp[amount] != float('inf') else -1


if __name__ == '__main__':
    count = 99
    coins = [2, 3, 5]

    num_coins = minCoinChangePlus(count, coins)
    print(f"Minimum number of coins required to make {count} yuan: {num_coins}")

    num_coins_backforward = minCoinChange_backforward(12, coins)
    print(f"Minimum number of coins required to make {count} yuan: {num_coins_backforward}")
    # for i in range(10, 99):
    #     num_coins_backforward = minCoinChange_backforward(i, coins)
    #     print(f"Minimum number of coins required to make {i} yuan: {num_coins_backforward}")