#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int maxScoreSightseeingPair(vector<int>& A);

int main() {
	vector<int> list{ 8,1,5,2,6 };
	cout << "result:" << maxScoreSightseeingPair(list) << endl;
	return 0;
}

int maxScoreSightseeingPair(vector<int>& A) {
	int max_i = 0;
	int max_iaddj = 0;
	if (A.size() != 0)
		max_i = A[0];
	else return 0;
	for (int j = 1;j < A.size();j++)
	{
		max_i = max(max_i, A[j]);
		max_iaddj = max(max_iaddj, max_i + A[j] - j);
	}
	return max_iaddj;
}