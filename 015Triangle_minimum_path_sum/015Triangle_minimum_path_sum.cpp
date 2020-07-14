#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::min;
using std::vector;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> f(n);
        f[0] = triangle[0][0];
        for (int i = 1; i < n; ++i)
        {
            // ??????????????????ß“???
            f[i] = f[i - 1] + triangle[i][i];
            // ??????ß“???
            for (int j = i - 1; j > 0; --j)
            {
                f[j] = min(f[j - 1], f[j]) + triangle[i][j];
            }
            // ??ß÷?????????????
            f[0] += triangle[i][0];
        }
        // ??¡Ÿ????n??n??????ß÷????
        return *min_element(f.begin(), f.end());
    }
};

int main()
{
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
    Solution func;
    cout << "the minimum path sum:" << func.minimumTotal(triangle) << endl;
    return 0;
}