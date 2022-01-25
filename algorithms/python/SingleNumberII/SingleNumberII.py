def singleNumber(self, nums):
           
    #1. make hashmap
    #2. while traversing list, add each element
    #3. remove it once it has been seen 3 times
    #4. finally, the only value left is the one we're looking for
    
    hashmap = defaultdict(int)
    for num in nums:
        hashmap[num] += 1
        if hashmap[num] == 3:
            del hashmap[num]
            
    singleNum = hashmap.keys()[0]
    return singleNum
