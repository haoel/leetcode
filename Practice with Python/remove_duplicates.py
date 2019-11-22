array=[1,2,3,3,3,4,4]
def remove_duplicate(array):
    slow = 0
    for fast in range( 0, len(array)):
        if array[fast] != array[slow]:
            slow = slow+1
            array[slow] = array[fast]
    return slow+1

print( remove_duplicate(array) )
print( array )