#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& strs);
void main() {
	vector<string> strs_1{ "flower","flow","flight" };
	vector<string> strs_2{ "dog","racecar","car" };
	vector<string> strs_3{ "dog","dogi","dogj" };
	string res_1 = longestCommonPrefix(strs_1);
	string res_2 = longestCommonPrefix(strs_2);
	string res_3 = longestCommonPrefix(strs_3);
	cout << "res_1:" << res_1 << endl;
	cout << "res_2:" << res_2 << endl;
	cout << "res_3:" << res_3 << endl;
}

string longestCommonPrefix(vector<string>& strs) {
	string strs_in{};
	size_t min_strs = strs[0].size();
	for (int i = 1;i < strs.size();i++)
		min_strs = min(min_strs, strs[i].size());

	for (int strs_i = 0;strs_i < strs.size()-1;strs_i++)
	{
		string temp{};
		for (int j = 1;j <= min_strs;j++)
			if (strs[strs_i].compare(0, j, strs[strs_i + 1], 0, j) == 0)
				temp.push_back(strs[strs_i][j - 1]);
			else
				break;
		if (temp.size() < strs_in.size() || strs_in.size() == 0)
			strs_in = temp;
		if (strs_in.size() == 0)
			break;
	}	
	return strs_in;
}