#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);
void main() {
	vector<int> nums{ -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> result = threeSum(nums);
	for (int i = 0;i < result.size();i++)
	{
		for (int j = 0;j < result[i].size();j++)
			cout << result[i][j] << '\t';
		cout << endl;
	}
}

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> map, map_list;
	vector<int> temp = nums;
	vector<int> remove;
	for (int i = 0;i < nums.size();i++)
		temp[i] = -temp[i];
	for (int i = 0;i < temp.size();i++)
		for (int j = 0;j < nums.size();j++)
			if (j != i)
				for (int t = 0;t < nums.size();t++)
					if (nums[j] + nums[t] + temp[i] == 0 && t != i && t != j)
						map.push_back({ temp[i],nums[j],nums[t] });
	for (int i = 0;i < map.size();i++)
	{
		for (int j = i+1;j < map.size();j++)
		{
			int count = 0;
			int number = 0;
			for (int y = 0;y < map[i].size();y++)
				for (int u = 0;u < map[j].size();u++)
					if (map[i][y] == map[j][u])
						count += 1;
			if (count >= 3 && i != 0)
			{
				for (int k = 0;k < remove.size();k++)
				{
					if (j == remove[k])
					{
						number += 1;
						break;
					}
				}
				if (number == 0)
					remove.push_back(j);
			}
			else if(count >= 3 && i == 0)
				remove.push_back(j);
		}
	}
	sort(remove.begin(), remove.end());

	for (int i = 0; i < map.size();i++)
	{
		int num = 0;
		for (int j = 0;j < remove.size();j++)
			if (i == remove[j])
			{
				num += 1;
				break;
			}
		if (num == 0)
			map_list.push_back(map[i]);
	}
	return map_list;
}