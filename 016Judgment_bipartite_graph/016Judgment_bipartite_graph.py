import collections


class Solution:
    def isBipartite(self, graph: [[int]]) -> bool:
        n = len(graph)
        UNCOLORED, RED, GREEN = 0, 1, 2
        color = [UNCOLORED] * n

        for i in range(n):
            if color[i] == UNCOLORED:
                q = collections.deque([i])
                color[i] = RED
                while q:
                    node = q.popleft()
                    cNei = (GREEN if color[node] == RED else RED)
                    for neighbor in graph[node]:
                        if color[neighbor] == UNCOLORED:
                            q.append(neighbor)
                            color[neighbor] = cNei
                        elif color[neighbor] != cNei:
                            return False

        return True


graph1 = [[1, 3], [0, 2], [1, 3], [0, 2]]
graph2 = [[1, 2, 3], [0, 2], [0, 1, 3], [0, 2]]
func = Solution()
print("graph1:{}".format(func.isBipartite(graph1)))
print("graph2:{}".format(func.isBipartite(graph2)))
