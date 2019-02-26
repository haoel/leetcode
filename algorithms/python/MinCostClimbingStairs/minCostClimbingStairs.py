def minCostClimbingStairs(self, cost):
    temp = [0, cost[0]]
    for i in range(1, len(cost)):
        temp[0], temp[1] = temp[1], min(temp) + cost[i]
    return min(temp)