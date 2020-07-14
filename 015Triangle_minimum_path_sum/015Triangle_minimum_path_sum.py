class Solution:
    def minimumTotal(self, triangle: [[int]]) -> int:
        n = len(triangle)
        f = list()
        f.append(triangle[0][0])
        for i in range(1, n):
            f.append(f[i - 1] + triangle[i][i])
            for j in range(i - 1, 0, -1):
                f[j] = min(f[j - 1], f[j]) + triangle[i][j]
            f[0] = f[0] + triangle[i][0]
        return min(f)


triangle = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
func = Solution()
print(func.minimumTotal(triangle))
