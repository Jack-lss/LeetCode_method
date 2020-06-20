

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        def matches(i: int, j: int) -> bool:
            if i == 0:
                return False
            if p[j - 1] == '.':
                return True
            return s[i - 1] == p[j - 1]
        sp = [[False] * (len(p) + 1) for _ in range(len(s) + 1)]
        sp[0][0] = True
        for i in range(len(s) + 1):
            for j in range(1, len(p) + 1):
                # 重点，规律总结
                # 匹配0次和匹配n次的合规律
                if p[j - 1] == '*':
                    sp[i][j] = sp[i][j - 2]
                    if matches(i, j - 1):
                        sp[i][j] = sp[i - 1][j]
                else:
                    if matches(i, j):
                        sp[i][j] = sp[i - 1][j - 1]
        return sp[len(s)][len(p)]


bull = Solution()

s_1 = "aaaa"
p_1 = "a*"
print("s_1 and p_1:\t{}".format(bull.isMatch(s_1, p_1)))

s_2 = "aa"
p_2 = "a*"
print("s_2 and p_2:\t{}".format(bull.isMatch(s_2, p_2)))

s_3 = "ab"
p_3 = ".*"
print("s_3 and p_3:\t{}".format(bull.isMatch(s_3, p_3)))

s_4 = "aab"
p_4 = "c*a*b"
print("s_4 and p_4:\t{}".format(bull.isMatch(s_4, p_4)))

s_5 = "mississippi"
p_5 = "mis*is*p*."
print("s_5 and p_5:\t{}".format(bull.isMatch(s_5, p_5)))
