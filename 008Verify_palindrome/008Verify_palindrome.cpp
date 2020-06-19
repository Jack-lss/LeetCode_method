#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string & s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            while (i < j && !isalnum(s[i]))
                ++i;
            while (i < j && !isalnum(s[j]))
                --j;
            if (toupper(s[i++]) != toupper(s[j--]))
                return false;
        }
        return true;               
    }
};

int main() {
    string str_1 = "A man, a plan, a canal: Panama";
    string str_2 = "race a car";
    Solution lss;
    cout << str_1 << ":" << lss.isPalindrome(str_1) << endl;
    cout << str_2 << ":" << lss.isPalindrome(str_2) << endl;
}