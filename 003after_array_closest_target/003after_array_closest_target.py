# -*- coding: utf-8 -*-

def findBeatValue(arr: [int], target: int) -> int:
    arr.sort()
    temp_cha=sum(arr)
    value=0
    for value_i in range(target//len(arr),max(arr)+1):
        sum_arr=0
        center = len(arr)//2
        while arr[center]!=value_i and center!=0 and center!=len(arr)-1:
            if value_i < arr[center]:
                center = center //2
            else:
                center = (center + len(arr))//2
        for i in arr:
            if i>value_i:
                sum_arr+=value_i
            else:
                sum_arr+=i
        if(abs(sum_arr-target) < temp_cha):
            temp_cha = abs(sum_arr-target)
            value = value_i
    return value
    

print(findBeatValue([4,9,3],10))
print(findBeatValue([2,3,5],10))
print(findBeatValue([11,12,13],10))