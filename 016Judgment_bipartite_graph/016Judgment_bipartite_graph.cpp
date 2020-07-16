#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::ios_base;
using std::queue;
using std::vector;

class Solution
{
private:
    static constexpr int UNCOLORED = 0;
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
    vector<int> color;

public:
    // 广度优先搜索
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, UNCOLORED);
        // 对每个顶点遍历
        for (int i = 0; i < n; ++i)
        {
            if (color[i] == UNCOLORED)
            {
                queue<int> q;
                q.push(i);
                color[i] = RED;
                while (!q.empty())
                {
                    int node = q.front();
                    int cNei = (color[node] == RED ? GREEN : RED);
                    q.pop();
                    // 对与顶点相连的点遍历
                    for (int neighbor : graph[node])
                    {
                        if (color[neighbor] == UNCOLORED)
                        {
                            q.push(neighbor);
                            color[neighbor] = cNei;
                        }
                        else if (color[neighbor] != cNei)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<int>> graph1 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}};
    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}};
    Solution func;
    cout.setf(ios_base::boolalpha);
    cout << "graph1:" << func.isBipartite(graph1) << endl;
    cout << "graph2:" << func.isBipartite(graph2) << endl;
}