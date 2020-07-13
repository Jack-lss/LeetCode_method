import collections


class Solution:
    def intersect(self, nums1: [int], nums2: [int]) -> [int]:
        if len(nums1) > len(nums2):
            return self.intersect(nums2, nums1)
        m = collections.Counter()
        for num in nums1:
            m[num] += 1

        intersection = list()
        for num in nums2:
            count = m.get(num, 0)
            if count > 0:
                intersection.append(num)
                m[num] -= 1
                if m[num] == 0:
                    m.pop(num)

        return intersection


num1 = [1, 2, 2, 1]
num2 = [2, 2]
num3 = [4, 9, 5]
num4 = [9, 4, 9, 8, 4]

func = Solution()
print("num1 and num2:{}".format(func.intersect(num1, num2)))
print("num3 and num4:{}".format(func.intersect(num3, num4)))
