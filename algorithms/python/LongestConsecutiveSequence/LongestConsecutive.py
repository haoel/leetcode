def longestConsecutive(self, nums):
    
    #first, create a hashmap
    hm = set(nums)
    longest = 0
    #find the longest consecutive sequence from each number in the new
    #hashmap (set)
    for num in hm:
        if (num - 1) not in hm:
            current = num + 1
            cons = 1
            while current in hm:
                current += 1
                cons += 1
            if cons > longest:
                longest = cons
            
    return longest