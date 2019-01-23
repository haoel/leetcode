# Method 1: sliding window

def findMaxAverage(self, nums, k):
    total = 0
    temp = float('-inf')
    for i, n in enumerate(nums):
        total += n
        if i >= k: total -= nums[i- k]
        if i >= k - 1:
            temp = max(temp, total)
    return temp / k
    
    
    
# Method 2: prefix sum
 def findMaxAverage(self, nums, k):
        temp = [0]
        for n in nums:
            temp.append(temp[-1] + n)
        
        res = max(temp[i + k] - temp[i] for i in range(len(nums) - k + 1))
        return res / k