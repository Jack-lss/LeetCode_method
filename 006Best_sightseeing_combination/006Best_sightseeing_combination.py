def maxScoreSightseeingPair(A: [int]) -> int:
    max_i = 0
    max_iaddj = 0
    if len(A) == 0:
        return 0
    else:
        max_i = A[0]
    for i in range(1,len(A)):
        max_i = max(max_i, A[i])
        max_iaddj = max(max_iaddj, max_i + A[i] - i)
    return max_iaddj

my_list = [8, 1, 5, 2, 6]
print(maxScoreSightseeingPair(my_list))