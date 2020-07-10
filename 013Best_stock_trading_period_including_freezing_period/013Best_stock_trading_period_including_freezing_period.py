import numpy as np


class Solution:
    def maxProfit(self, prices: [int]) -> int:
        if prices is None:
            return 0

        n = len(prices)
        f = np.zeros([n, 3])
        # 第一天买的收益
        f[0][0] = -prices[0]
        for i in range(1, n):
            # 源于前一天的收益或者当前天买的收益
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i])
            # 卖后的收益（必须持有）
            f[i][1] = f[i - 1][0] + prices[i]
            # 无操作的收益，源于前一天买或卖的收益
            f[i][2] = max(f[i - 1][1], f[i - 1][2])

        return max(f[n - 1][1], f[n - 1][2])


func = Solution()
prices = [1, 2, 3, 0, 2]
print("最大收益：{}".format(func.maxProfit(prices)))
