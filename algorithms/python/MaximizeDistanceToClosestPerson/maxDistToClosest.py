def maxDistToClosest(self, seats):
    first = seats.index(1)
    last = 0
    for i in range(len(seats) - 1, -1, -1):
        if seats[i]: 
            last = i
            break
    res = 0
    temp = 0
    for i in range(first, last + 1):
        if seats[i] == 1:
            res = max(temp, res)
            temp = 0
        else:
            temp += 1
    return max(first, len(seats) - last - 1, (res + 1) // 2)