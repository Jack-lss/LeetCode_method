#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // Lambdaº¯Êý
        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };
        vector<vector<int>> f(s.size() + 1, vector<int>(p.size() + 1));
        f[0][0] = true;
        for (int i = 0;i <= s.size();++i) {
            for (int j = 1;j <= p.size();++j) {
                if (p[j - 1] == '*') {
                    f[i][j] = f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] = f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] = f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[s.size()][p.size()];
    }
};

int main() {
    Solution bull;
    string s_1 = "aaaa";
    string p_1 = "a*";
    cout << "s_1 and p_1:\t" << bull.isMatch(s_1, p_1) << endl;

    string s_2 = "aa";
    string p_2 = "a*";
    cout << "s_2 and p_2:\t" << bull.isMatch(s_2, p_2) << endl;

    string s_3 = "ab";
    string p_3 = ".*";
    cout << "s_3 and p_3:\t" << bull.isMatch(s_3, p_3) << endl;

    string s_4 = "aab";
    string p_4 = "c*a*b";
    cout << "s_4 and p_4:\t" << bull.isMatch(s_4, p_4) << endl;

    string s_5 = "mississippi";
    string p_5 = "mis*is*p*.";
    cout << "s_5 and p_5:\t" << bull.isMatch(s_5, p_5) << endl;

}