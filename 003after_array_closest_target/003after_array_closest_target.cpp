#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int findBestValue(vector<int>& arr, int target);
void main() {
	vector<int> arr{ 4, 9, 3 };int target = 10;
	vector<int> arr_1{ 2,3,5 };
	vector<int> arr_2{ 60864, 25176, 27249, 21296, 20204 };int target_1 = 56803;
	int value_1 = findBestValue(arr, target);
	int value_2 = findBestValue(arr_1, target);
	int value_3 = findBestValue(arr_2, target_1);
	cout << "1:" << value_1 << endl;
	cout << "2:" << value_2 << endl;
	cout << "3:" << value_3 << endl;
}

int findBestValue(vector<int>& arr, int target)
{
	int value = 0;
	int max_sum = 0;
	int max_arr = *max_element(arr.begin(), arr.end());
	int min_arr = *min_element(arr.begin(), arr.end());
	vector<int> sum_p{}, value_p{};
	for (int i = 0;i < arr.size();i++)
		max_sum += arr[i];
	if (min_arr >= target / arr.size())
		min_arr = target / arr.size() * arr.size();
	else
		min_arr = min_arr * arr.size();
	for (int sum_i = min_arr;sum_i <= max_sum;sum_i++)
	{
		int value_max = 0;
		if (max_arr > target)
			value_max = target;
		else
			value_max = max_arr;
		for (value = 0;value <= value_max;value++)
		{
			int sum_ic = sum_i;
			for (int j = 0;j < arr.size();j++)
				if (arr[j] > value)
					sum_ic -= value;
				else
					sum_ic -= arr[j];
			if (sum_ic == 0)
			{
				sum_p.push_back(sum_i);
				value_p.push_back(value);
				break;
			}
		}
	}
	for (int i = 0;i < sum_p.size();i++)
		sum_p[i] = abs(sum_p[i] - target);
	int min_sum_p = *min_element(sum_p.begin(), sum_p.end());
	vector<int> value_in{};
	for (int i = 0;i < sum_p.size();i++)
		if (sum_p[i] == min_sum_p)
			value_in.push_back(value_p[i]);
	value = *min_element(value_in.begin(), value_in.end());
	return value;
}