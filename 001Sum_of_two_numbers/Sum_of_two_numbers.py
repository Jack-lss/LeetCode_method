

def twoSum(nums: [int], target: int) -> [int]:
    temp = [target-tem for tem in nums]
    for index,num in enumerate(nums):
        if num in temp and index!=temp.index(num):
            return [index,temp.index(num)]


nums = [3,2,4,11,15]
target = 6

target_nums = twoSum(nums, target)
print(target_nums)