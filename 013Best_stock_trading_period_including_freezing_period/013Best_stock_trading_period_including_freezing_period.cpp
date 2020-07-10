#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // 便于回代，但没写
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;

        int n = prices.size();
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0]; //第一天买的收益
        for (int i = 1; i < n; ++i)
        {
            //源于前一天的收益或者当前天买的收益
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            //卖后的收益（必须持有）
            f[i][1] = f[i - 1][0] + prices[i];
            //无操作的收益，源于前一天买或卖的收益
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }

        return max(f[n - 1][1], f[n - 1][2]);
    }
};

int main()
{
    Solution func;
    vector<int> prices{4, 2, 3, 0, 2};
    cout << "收益：" << func.maxProfit(prices) << endl;
}
