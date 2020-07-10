#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // ���ڻش�����ûд
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;

        int n = prices.size();
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0]; //��һ���������
        for (int i = 1; i < n; ++i)
        {
            //Դ��ǰһ���������ߵ�ǰ���������
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            //��������棨������У�
            f[i][1] = f[i - 1][0] + prices[i];
            //�޲��������棬Դ��ǰһ�������������
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }

        return max(f[n - 1][1], f[n - 1][2]);
    }
};

int main()
{
    Solution func;
    vector<int> prices{4, 2, 3, 0, 2};
    cout << "���棺" << func.maxProfit(prices) << endl;
}
