#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        // 为了降低空间复杂度，首先遍历较短的数组，
        if (nums1.size() > nums2.size())
        {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> m;
        // c++11
        // for循环里的:表示依次从nums1中取出元素与num
        for (int num : nums1)
        {
            ++m[num];
        }
        vector<int> intersection;
        // 在哈希表中记录每个数字以及对应出现的次数，
        for (int num : nums2)
        {
            // m.count(num)，计算m中num出现的个数（key）
            if (m.count(num))
            {
                intersection.push_back(num);
                // 减少较短数组中出现的num次数
                --m[num];
                // 如果减少到num1没有num元素了。就在m中删除num
                if (m[num] == 0)
                {
                    m.erase(num);
                }
            }
        }
        // 然后遍历较长的数组得到交集。
        return intersection;
    }
};

int main()
{
    Solution func;
    vector<int> num1 = {1, 2, 2, 1};
    vector<int> num2 = {2, 2};
    vector<int> num3 = {4, 9, 5};
    vector<int> num4 = {9, 4, 9, 8, 4};
    vector<int> num1and2 = func.intersect(num1, num2);
    vector<int> num3and4 = func.intersect(num3, num4);
    cout << "num1 and num2:\n";
    for (int num : num1and2)
    {
        cout << num << '\t';
    }
    cout << endl;
    cout << "num3 and num4:\n";
    for (int num : num3and4)
    {
        cout << num << '\t';
    }
    cout << endl;
    return 0;
}