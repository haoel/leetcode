class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = dict()
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in table:
                return [table[complement],i]
            else:
                table[nums[i]] = i
                
        
