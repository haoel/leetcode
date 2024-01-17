class Solution(object):
    def isRobotBounded(self, instructions):
        """
        :type instructions: str
        :rtype: bool
        """
        dirx = 0
        diry = 1
        x = y = 0
        for ins in instructions:
            if ins == "L":
                dirx, diry = -1*diry, dirx
            elif ins == "R":
                dirx, diry = diry, -1*dirx
            else:
                x += dirx
                y += diry
