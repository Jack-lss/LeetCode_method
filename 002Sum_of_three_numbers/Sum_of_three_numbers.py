# -*- coding: utf-8 -*-

def threeSum(nums: [int]) -> [[int]]:
    map=[]
    mapk=[]
    temp = [0-tem for tem in nums]
    for index, num in enumerate(nums):
        for bsd in range(index+1,len(nums)):
            if num + nums[bsd] in temp:
                map.append([num,nums[bsd],-(num+nums[bsd])])
                break
    map=[sorted(map_i) for map_i in map]
    for mp in map:
        if mp not in mapk:
            mapk.append(mp)
            
    return mapk

nums = [-1, 0, 1, 2, -1, -4]
sumt = threeSum(nums)

print(sumt)