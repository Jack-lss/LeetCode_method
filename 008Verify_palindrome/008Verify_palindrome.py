
class Solution:
    def isPalindrome(self, s: str) -> bool:
        i = 0
        j = len(s) - 1
        while i < j:
            while i < j and not s[i].isalnum():
                i += 1
            while i < j and not s[j].isalnum():
                j -= 1
            if s[i].lower() != s[j].lower():
                return False
            i += 1
            j -= 1
        return True



str_1 = "A man, a plan, a canal: Panama"
str_2 = "race a car"
lss = Solution()
print("{}:{}".format(str_1, lss.isPalindrome(str_1)))
print("{}:{}".format(str_2, lss.isPalindrome(str_2)))