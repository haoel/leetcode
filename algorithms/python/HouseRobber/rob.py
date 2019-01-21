def rob(self, nums):
    temp = [0, 0]
    for n in nums:
        temp[0], temp[1] = max(temp), n + temp[0]
    
    return max(temp)