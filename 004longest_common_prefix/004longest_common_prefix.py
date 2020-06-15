
def longest_common_prefix(strs: [str]) -> str:
    min_str = len(strs[0])
    for i in range(1,len(strs)):
        min_str = min(min_str, len(strs[i]))
    mid = min_str//2

    while (is_mid(strs, mid) == 1 and \
        is_mid(strs, mid+1) !=1) == False:
        if is_mid(strs, mid) == 1:
            mid = (min_str + mid) // 2
        else:
            mid = mid // 2
        if mid == 0:
            return ""
        if mid == min_str-1 and is_mid(strs, mid) == 1:
            return strs[0][:mid+1]
        
    return strs[0][:mid+1]

def is_mid(strs: [str], mid: int) -> int:
    temp_str = []
    for str_i in strs:
        temp_str.append(str_i[mid])
    temp = set(temp_str)
    return len(temp)


str_1 = ["flower","flow","flight"]
str_2 = ["dog","racecar","car"]
str_3 = ["dog","dogi","dogj"]

print(longest_common_prefix(str_1))
print(longest_common_prefix(str_2))
print(longest_common_prefix(str_3))