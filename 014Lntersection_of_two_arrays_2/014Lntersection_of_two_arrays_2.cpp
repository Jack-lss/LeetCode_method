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
        // Ϊ�˽��Ϳռ临�Ӷȣ����ȱ����϶̵����飬
        if (nums1.size() > nums2.size())
        {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> m;
        // c++11
        // forѭ�����:��ʾ���δ�nums1��ȡ��Ԫ����num
        for (int num : nums1)
        {
            ++m[num];
        }
        vector<int> intersection;
        // �ڹ�ϣ���м�¼ÿ�������Լ���Ӧ���ֵĴ�����
        for (int num : nums2)
        {
            // m.count(num)������m��num���ֵĸ�����key��
            if (m.count(num))
            {
                intersection.push_back(num);
                // ���ٽ϶������г��ֵ�num����
                --m[num];
                // ������ٵ�num1û��numԪ���ˡ�����m��ɾ��num
                if (m[num] == 0)
                {
                    m.erase(num);
                }
            }
        }
        // Ȼ������ϳ�������õ�������
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