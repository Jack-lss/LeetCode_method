import numpy as np


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: [[int]]) -> int:
        obs = np.array(obstacleGrid)
        n, m = obs.shape
        f = np.zeros(m, dtype=np.int32)
        f[0] = (obstacleGrid[0][0] == 0)
        for i in range(n):
            for j in range(m):
                if obstacleGrid[i][j] == 1:
                    f[j] = 0
                    continue
                if j - 1 >= 0 and obstacleGrid[i][j - 1] == 0:
                    f[j] += f[j - 1]
        return f[-1]


obstacleGrid = [[0, 0, 0, 1, 0, 0], [0, 1, 0, 0, 1, 0], [0, 0, 0, 0, 0, 0]]
func = Solution()
print(func.uniquePathsWithObstacles(obstacleGrid))
