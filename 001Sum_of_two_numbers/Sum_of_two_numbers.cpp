#include <iostream>
#include <vector>

using namespace std;
vector<int> twoSum(vector<int>& nums, int target);

void main() {
	vector<int> nums{2, 11, 15, 2};
	int target = 9;
	vector<int> numbers = twoSum(nums, target);
	if (numbers[0] == nums.size() && numbers[1] == nums.size())
		cout << "找不到" << endl;
	else
		cout << "下标：" << numbers[0] << "," << numbers[1] << endl;
}

vector<int> twoSum(vector<int>& nums, int target)
{
	int i, j;
	for (i = 0;i < nums.size();i++)
		for (j = i + 1;j < nums.size();j++)
			if (nums[i] + nums[j] == target)
				return vector<int>{i, j};
	return vector<int>{i, j};
}